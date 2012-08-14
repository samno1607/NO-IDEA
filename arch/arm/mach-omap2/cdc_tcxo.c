/*
 * OMAP4 CDC TCXO support
 * The Clock Divider Chip (TCXO) is used on OMAP4 based SDP platforms
 *
 * Copyright (C) 2010 Texas Instruments, Inc.
 * Written by Rajendra Nayak <rnayak@ti.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/platform_device.h>
#include <linux/i2c.h>
#include <linux/cdc_tcxo.h>
#include <linux/delay.h>

#define DRIVER_DESC       "CDC TCXO driver"
#define DRIVER_NAME       "cdc_tcxo_driver"

struct cdc_tcxo_info {
	struct i2c_client *client;
	struct device *dev;
	unsigned char buf[4];
	int active;
};

static struct cdc_tcxo_info cdc_info;

static int cdc_tcxo_probe(struct i2c_client *client, \
				const struct i2c_device_id *id)
{
	int r = 0;
	struct i2c_msg msg;
	/*
	 * The Clock Driver Chip (TCXO) on OMAP4 based SDP needs to
	 * be programmed to output CLK1 based on REQ1 from OMAP.
	 * By default CLK1 is driven based on an internal REQ1INT signal
	 * which is always set to 1.
	 * Doing this helps gate sysclk (from CLK1) to OMAP while OMAP
	 * is in sleep states.
	 * Please refer to the TCXO Data sheet for understanding the
	 * programming sequence further.
	 */
//	u8 buf[4] = {0x9f, 0xf0, 0, 0};
//	u8 buf[4] = {0x9f, 0xf0, 0x20, 0x00};
	cdc_info.buf[0] = 0x9f;
	cdc_info.buf[1] = 0xf0;
	cdc_info.buf[2] = 0x20;
	cdc_info.buf[3] = 0x00;

	cdc_info.active = 1;

	msg.addr = client->addr;
	msg.flags = 0;
	msg.len = 4;
	msg.buf = cdc_info.buf;

	cdc_info.client = client;

	r = i2c_transfer(client->adapter, &msg, 1);

	return 0;
}

int cdc_tcxo_set_req_off(int enable){
	int ret;

	if (enable){
		cdc_info.buf[CDC_TCXO_REG3] |= 0x20;
	}else{
		cdc_info.buf[CDC_TCXO_REG3] &= ~0x20;
		cdc_info.buf[CDC_TCXO_REG3] |= 0x10;
	}
	
	ret = i2c_master_send(cdc_info.client, cdc_info.buf, CDC_TCXO_REGNUM);
	if (ret < 0) {
		dev_err(cdc_info.dev, "failed to write data (%d)\n", ret);
		return ret;
	}	

	return ret;
}

int cdc_tcxo_set_req_int(int clk_id, int enable)
{
	unsigned char mask;
	int ret = -1;
	int retry_cnt = 0;

	if (!cdc_info.active) {
		dev_err(cdc_info.dev, "device is not active yet\n");
		return -ENODEV;
	}

	switch (clk_id) {
	case CDC_TCXO_CLK1:
		mask = CDC_TCXO_REQ1INT;
		break;
	case CDC_TCXO_CLK2:
		mask = CDC_TCXO_REQ2INT;
		break;
	case CDC_TCXO_CLK3:
		mask = CDC_TCXO_REQ3INT;
		break;
	case CDC_TCXO_CLK4:
		mask = CDC_TCXO_REQ4INT;
		break;
	default:
		dev_err(cdc_info.dev, "invalid clk_id: %d\n", clk_id);
		return -EINVAL;
	}

	if (enable)
		cdc_info.buf[CDC_TCXO_REG1] |= mask;
	else
		cdc_info.buf[CDC_TCXO_REG1] &= ~mask;

	do{
		ret = i2c_master_send(cdc_info.client, cdc_info.buf, CDC_TCXO_REGNUM);
		if( ret < 0 )
			msleep(5);
	}while( ret < 0 && retry_cnt++ < 30 );

	if (ret < 0) {
		dev_err(cdc_info.dev, "failed to write data (%d)\n", ret);
		return ret;
	}

	return 0;
}
EXPORT_SYMBOL(cdc_tcxo_set_req_int);

int cdc_tcxo_set_req_prio(int clk_id, int req_prio)
{
	unsigned char mask;
	int ret = -1;
	int retry_cnt = 0;
	
	if (!cdc_info.active) {
		dev_err(cdc_info.dev, "device is not active yet\n");
		return -ENODEV;
	}

	switch (clk_id) {
	case CDC_TCXO_CLK1:
		mask = CDC_TCXO_REQ1PRIO;
		break;
	case CDC_TCXO_CLK2:
		mask = CDC_TCXO_REQ2PRIO;
		break;
	case CDC_TCXO_CLK3:
		mask = CDC_TCXO_REQ3PRIO;
		break;
	case CDC_TCXO_CLK4:
		mask = CDC_TCXO_REQ4PRIO;
		break;
	default:
		dev_err(cdc_info.dev, "invalid clk_id: %d\n", clk_id);
		return -EINVAL;
	}

	if (req_prio == CDC_TCXO_PRIO_REQINT)
		cdc_info.buf[CDC_TCXO_REG3] |= mask;
	else
		cdc_info.buf[CDC_TCXO_REG3] &= ~mask;

	do{
		ret = i2c_master_send(cdc_info.client, cdc_info.buf, CDC_TCXO_REGNUM);
		if( ret < 0 )
			msleep(5);
	}while( ret < 0 && retry_cnt++ < 30 );
	
	if (ret < 0) {
		dev_err(cdc_info.dev, "failed to write data (%d)\n", ret);
		return ret;
	}

	return 0;
}
EXPORT_SYMBOL(cdc_tcxo_set_req_prio);

static const struct i2c_device_id cdc_tcxo_id[] = {
	{ "cdc_tcxo_driver", 0 },
	{ }
};

static struct i2c_driver cdc_tcxo_i2c_driver = {
	.driver = {
		.name		= DRIVER_NAME,
	 },
	.probe		= cdc_tcxo_probe,
	.id_table	= cdc_tcxo_id,
};

static int __init cdc_tcxo_init(void)
{
	int r;

	r = i2c_add_driver(&cdc_tcxo_i2c_driver);
	if (r < 0) {
		printk(KERN_WARNING DRIVER_NAME
		       " driver registration failed\n");
		return r;
	}

	return 0;
}

static void __exit cdc_tcxo_exit(void)
{
	i2c_del_driver(&cdc_tcxo_i2c_driver);
}


module_init(cdc_tcxo_init);
module_exit(cdc_tcxo_exit);

