/*
 * xmd-tty.c
 *
 * Copyright (C) 2011 Intel Mobile Communications. All rights reserved.
 *
 * Author: Chaitanya <Chaitanya.Khened@intel.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/wait.h>
#include <linux/wakelock.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/spinlock.h>

#include <linux/tty.h>
#include <linux/tty_driver.h>
#include <linux/tty_flip.h>
#include <linux/slab.h>

#include "xmd-ch.h"

/* #define XMD_TTY_ENABLE_DEBUG_MSG */
#define XMD_TTY_ENABLE_ERR_MSG

static DEFINE_MUTEX(xmd_tty_lock);

static struct xmd_ch_info tty_channels[MAX_SMD_TTYS] = {
	{0,  "CHANNEL1",  0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
	{1,  "CHANNEL2",  0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
	{2,  "CHANNEL3",  0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
	{3,  "CHANNEL4",  0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
	{4,  "CHANNEL5",  0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
	{5,  "CHANNEL6",  0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
	{6,  "CHANNEL7",  0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
	{7,  "CHANNEL8",  0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
	{8,  "CHANNEL9",  0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
	{9,  "CHANNEL10", 0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
	{10, "CHANNEL11", 0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
	{11, "CHANNEL12", 0, XMD_TTY, NULL, 0, SPIN_LOCK_UNLOCKED, 0},
};

static int tty_channels_len = ARRAY_SIZE(tty_channels);

static void xmd_ch_tty_send_to_user(int chno)
{
	struct tty_struct *tty = NULL;
	struct xmd_ch_info *tty_ch = NULL;
	unsigned char *buf = NULL;
	int i,len, dataToRead;

	buf = (unsigned char *)xmd_ch_read(chno, &len);

	if ((!buf)||(len == 0)) {
#if defined (XMD_TTY_ENABLE_ERR_MSG)
		printk("\n%s (line %d): buf is NULL or len is %d\n", __func__, __LINE__, len);
#endif
		return;
	}

#if defined (XMD_TTY_ENABLE_DEBUG_MSG)
	{
		char *str = (char *) kzalloc(len + 1, GFP_ATOMIC);
		
		if(str) {
			memcpy(str, buf, len);
			printk("\nxmdtty: Sending data of size %d to ch %d, buf = %s\n",
						len, chno, str);
			kfree(str);
		}
	}
#endif

	for (i=0; i<tty_channels_len; i++) {
		if (tty_channels[i].chno == chno) {
			tty = (struct tty_struct *)tty_channels[i].priv;
			tty_ch = (struct xmd_ch_info*)tty->driver_data;
		}
	}

	if (!tty || !tty_ch) {
#if defined (XMD_TTY_ENABLE_ERR_MSG)
		printk("\n%s (line %d): invalid chno %d \n", __func__, __LINE__, chno);
#endif
		return;
	}

	if(tty_ch->throttled != 0) {
#if defined (XMD_TTY_ENABLE_ERR_MSG)
		printk("\n%s (line %d): throttled chno %d dropping data \n", __func__, __LINE__, chno);
#endif
		return;
	}

	tty->low_latency = 1;

	dataToRead = tty_insert_flip_string(tty, buf, len);

#if defined (XMD_TTY_ENABLE_ERR_MSG)
	if (dataToRead != len) {
		printk("\n%s (line %d): ch %d dropping data : dataToRead (%d) len(%d)\n",
				__func__, __LINE__, chno, dataToRead, len);
	}
#endif

	tty_flip_buffer_push(tty);
	
	tty_wakeup(tty);
}

static int xmd_ch_tty_open(struct tty_struct *tty, struct file *f)
{
	struct xmd_ch_info *tty_ch;
	char init_flag = 0;

	int n = tty->index;

	if (n >= tty_channels_len) {
#if defined (XMD_TTY_ENABLE_ERR_MSG)
		printk("\n%s (line %d): Error opening channel %d\n", __func__, __LINE__, n);
#endif
		return -ENODEV;
	}

#if defined (XMD_TTY_ENABLE_DEBUG_MSG)
	printk("\n%s (line %d): Opening channel %d\n", __func__, __LINE__, n+1);
#endif

	tty_ch = tty_channels + n;

	mutex_lock(&xmd_tty_lock);

	if (tty_ch->open_count > 0)
		init_flag = 1;

	tty_ch->open_count++;

	if(init_flag) {
		mutex_unlock(&xmd_tty_lock);
#if defined (XMD_TTY_ENABLE_ERR_MSG)
		printk("\n%s (line %d): Channel already opened successfully %d\n",
					__func__, __LINE__, tty_ch->chno);
#endif
		return 0;
	}

	tty_ch->chno = xmd_ch_open(tty_ch, xmd_ch_tty_send_to_user);
	
	if (0 > tty_ch->chno) {
#if defined (XMD_TTY_ENABLE_ERR_MSG)
		printk("\n%s (line %d): Error opening channel %d\n", __func__, __LINE__, n);
#endif
		tty_ch->open_count = 0;
		tty_ch->chno = 0;
		mutex_unlock(&xmd_tty_lock);		
		return -ENOMEM;
	}

#if defined (XMD_TTY_ENABLE_DEBUG_MSG)
	printk("\n%s (line %d): Channel opened successfully %d\n", 
		__func__, __LINE__, tty_ch->chno);
#endif

	tty_ch->throttled = 0;
	tty->driver_data = (void *)tty_ch;
	tty_ch->priv = (void*) tty;
	mutex_unlock(&xmd_tty_lock);

	return 0;
}

static void xmd_ch_tty_close(struct tty_struct *tty, struct file *f)
{
	struct xmd_ch_info *tty_ch = (struct xmd_ch_info*)tty->driver_data;
	char cleanup_flag = 1;

#if defined (XMD_TTY_ENABLE_DEBUG_MSG)
	printk("\n%s (line %d): Channel close function [ch %d]\n",
		__func__, __LINE__, tty_ch->chno);
#endif

	if (!tty_ch) {
#if defined (XMD_TTY_ENABLE_ERR_MSG)
		printk("\n%s (line %d): Channel close function fails\n", __func__, __LINE__);
#endif
		return;
	}

	mutex_lock(&xmd_tty_lock);

	if (tty_ch->open_count > 1) {
		tty_ch->open_count--;
		cleanup_flag = 0;
#if defined (XMD_TTY_ENABLE_ERR_MSG)
		printk("\n%s (line %d): Channel close [ch %d] [open_count %d]\n", 
			__func__, __LINE__, tty_ch->chno, tty_ch->open_count);
#endif		
	}
	else {
		tty_ch->open_count = 0;
		tty_ch->throttled = 0;		
	}

	if (cleanup_flag) {
		xmd_ch_close(tty_ch->chno);
		tty->driver_data = NULL;
	}

	mutex_unlock(&xmd_tty_lock);
}


#if defined(CONFIG_MACH_LGE_COSMOPOLITAN)
/***********************************************
	LGE-RIL CHANNEL : 1 , 2, 3, 4, 5, 8, 9, (11: KR SKT), 12
	GPS CHANNEL : 7
	AT SERVICE CHANNEL : 10
	VT DATA CHANNEL : 6
	CIQ CHANNEL : 11 (For ATnT)
	DUN : Not used

	IMC Modem supports at most 2000 bytes AT command
	io_db.h - SIO_RXP_AT_DEFAULT_BUFLEN (2000)

	IMC Modem VT Data buffer : 8192 bytes
	io_db.h - IO_DS_RX_BUFFER_SIZE (8192)

	IMC Modem CIQ Data buffer : 1024*16
	xia_slave_bridge.c - 1024*16
	
***********************************************/

/* AT command */    
#define XMD_TTY_AT_MAX_WRITE_SIZE	2000

/* VT data */
#define XMD_TTY_VT_MAX_WRITE_SIZE	1024

/* CIQ data */
#define XMD_TTY_CIQ_MAX_WRITE_SIZE	1024*8

static int xmd_ch_tty_write(
	struct tty_struct *tty,
	const unsigned char *buf,
	int len)
{
	int written_len = 0;
	struct xmd_ch_info *tty_ch = tty->driver_data;

	/* VT data */
	if(tty_ch->chno == XMD_TTY_VT_DATA_CHANNEL) 
		written_len = min(len, XMD_TTY_VT_MAX_WRITE_SIZE);

#if defined (TARGET_CARRIER_ATT)
	/* CIQ data */
	else if(tty_ch->chno == XMD_TTY_CIQ_CHANNEL) 
		written_len = min(len, XMD_TTY_CIQ_MAX_WRITE_SIZE);
#endif

	/* AT command */
	else 
		written_len = min(len, XMD_TTY_AT_MAX_WRITE_SIZE);

#if defined (XMD_TTY_ENABLE_DEBUG_MSG)
	{
		int max_len = 0;
		char *str = (char *) kzalloc(written_len + 1, GFP_ATOMIC);

		if(tty_ch->chno == XMD_TTY_VT_DATA_CHANNEL) /* VT data */
			max_len = XMD_TTY_VT_MAX_WRITE_SIZE;
#if defined (TARGET_CARRIER_ATT)		
		else if(tty_ch->chno == XMD_TTY_CIQ_CHANNEL) /* CIQ data */
			max_len = XMD_TTY_CIQ_MAX_WRITE_SIZE;
#endif		
		else /* AT command */
			max_len = XMD_TTY_AT_MAX_WRITE_SIZE;

		if(len > max_len) {
			printk("\nxmdtty: xmd_ch_tty_write len(%d) is bigger than max write size for ch %d\n",
					len, tty_ch->chno);
		}

		if(str) {
			memcpy(str, buf, written_len);
			printk("\nxmdtty: writing data of size %d to ch %d, data: %s\n",
						written_len, tty_ch->chno, str);
			kfree(str);
		}
	}
#endif

	xmd_ch_write(tty_ch->chno, (void *)buf, written_len);

	return written_len;
}

#else /* CONFIG_MACH_LGE_COSMOPOLITAN */

static int xmd_ch_tty_write(
	struct tty_struct *tty,
	const unsigned char *buf,
	int len)
{
	struct xmd_ch_info *tty_ch = tty->driver_data;

#if defined (XMD_TTY_ENABLE_DEBUG_MSG)
	{
		char *str = (char *) kzalloc(len + 1, GFP_ATOMIC);

		if(str) {
			memcpy(str, buf, len);
			printk("\nxmdtty: writing data of size %d to ch %d, data: %s\n",
						len, tty_ch->chno, str);
			kfree(str);
		}
	}
#endif

	xmd_ch_write(tty_ch->chno, (void *)buf, len);

	return len;
}
#endif


static int xmd_ch_tty_write_room(struct tty_struct *tty)
{
#if defined (XMD_TTY_ENABLE_DEBUG_MSG)
	struct xmd_ch_info *tty_ch = (struct xmd_ch_info*)tty->driver_data;

	printk("\n%s (line %d): [ch %d]\n", __func__, __LINE__, tty_ch->chno);
#endif

	if(xmd_is_recovery_state()) {
#if defined (XMD_TTY_ENABLE_DEBUG_MSG)
		printk("\n%s (line %d): xmd_is_recovery_state\n", __func__, __LINE__);
#endif
		return 0;
	}

	return 8192;
}

static int xmd_ch_tty_chars_in_buffer(struct tty_struct *tty)
{
#if defined (XMD_TTY_ENABLE_DEBUG_MSG)
	struct xmd_ch_info *tty_ch = (struct xmd_ch_info*)tty->driver_data;

	printk("\n%s (line %d): [ch %d]\n", __func__, __LINE__, tty_ch->chno);
#endif

	return 0;
}

static void xmd_ch_tty_throttle(struct tty_struct *tty)
{
	struct xmd_ch_info *tty_ch = (struct xmd_ch_info*)tty->driver_data;

#if defined (XMD_TTY_ENABLE_ERR_MSG)
	printk("\n%s (line %d): [ch %d]\n", __func__, __LINE__, tty_ch->chno);
#endif

	mutex_lock(&xmd_tty_lock);
	tty_ch->throttled = 1;
	mutex_unlock(&xmd_tty_lock);
}

static void xmd_ch_tty_unthrottle(struct tty_struct *tty)
{
	struct xmd_ch_info *tty_ch = (struct xmd_ch_info*)tty->driver_data;

#if defined (XMD_TTY_ENABLE_ERR_MSG)
	printk("\n%s (line %d): [ch %d]\n", __func__, __LINE__, tty_ch->chno);
#endif
	mutex_lock(&xmd_tty_lock);
	tty_ch->throttled = 0;
	mutex_unlock(&xmd_tty_lock);
}

static struct tty_operations xmd_ch_tty_ops = {
	.open = xmd_ch_tty_open,
	.close = xmd_ch_tty_close,
	.write = xmd_ch_tty_write,
	.write_room = xmd_ch_tty_write_room,
	.chars_in_buffer = xmd_ch_tty_chars_in_buffer,
	.throttle = xmd_ch_tty_throttle,
	.unthrottle = xmd_ch_tty_unthrottle,
};

static struct tty_driver *xmd_ch_tty_driver;

static int __init xmd_ch_tty_init(void)
{
	int ret, i;

#if defined (XMD_TTY_ENABLE_DEBUG_MSG)
	printk("\n%s (line %d): xmd_ch_tty_init\n", __func__, __LINE__);
#endif

	xmd_ch_tty_driver = alloc_tty_driver(MAX_SMD_TTYS);

	if (xmd_ch_tty_driver == 0) {
#if defined (XMD_TTY_ENABLE_ERR_MSG)
		printk("\n%s (line %d): xmd_ch_tty_driver is NULL\n", __func__, __LINE__);
#endif		
		return -ENOMEM;
	}

	xmd_ch_tty_driver->owner = THIS_MODULE;
	xmd_ch_tty_driver->driver_name = "xmd_ch_tty_driver";
	xmd_ch_tty_driver->name = "xmd-tty";
	xmd_ch_tty_driver->major = 0;
	xmd_ch_tty_driver->minor_start = 0;
	xmd_ch_tty_driver->type = TTY_DRIVER_TYPE_SERIAL;
	xmd_ch_tty_driver->subtype = SERIAL_TYPE_NORMAL;
	xmd_ch_tty_driver->init_termios = tty_std_termios;
	xmd_ch_tty_driver->init_termios.c_iflag = 0;
	xmd_ch_tty_driver->init_termios.c_oflag = 0;
	xmd_ch_tty_driver->init_termios.c_cflag = B38400 | CS8 | CREAD;
	xmd_ch_tty_driver->init_termios.c_lflag = 0;
	xmd_ch_tty_driver->flags = TTY_DRIVER_RESET_TERMIOS |
								TTY_DRIVER_REAL_RAW 	|
								TTY_DRIVER_DYNAMIC_DEV;

	tty_set_operations(xmd_ch_tty_driver, &xmd_ch_tty_ops);

	ret = tty_register_driver(xmd_ch_tty_driver);

	if (ret != 0) {
#if defined (XMD_TTY_ENABLE_ERR_MSG)
		printk("\n%s (line %d): tty_register_driver fails by error %d\n", __func__, __LINE__, ret);
#endif		
		return ret;
	}

	for (i = 0; i < tty_channels_len; i++) {
		tty_register_device(xmd_ch_tty_driver, tty_channels[i].id, 0);
	}

	xmd_ch_init();

	return 0;
}

module_init(xmd_ch_tty_init);

