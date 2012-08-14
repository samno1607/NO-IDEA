/***************************************************************************
* 
*   SiI9244 - MHL Transmitter Driver
*
* Copyright (C) (2011, Silicon Image Inc)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation version 2.
*
* This program is distributed ��as is�� WITHOUT ANY WARRANTY of any
* kind, whether express or implied; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
*****************************************************************************/
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/i2c.h>
#include <linux/gpio.h>
// #include <plat/pm.h>
#include <asm/irq.h>
#include <linux/delay.h>
// #include <plat/gpio-cfg.h>
// #include <plat/gpio-core.h>
// #include <mach/regs-gpio.h>
// #include <mach/regs-clock.h>
#include <linux/miscdevice.h>
#include <linux/slab.h>
#include <linux/syscalls.h> 
#include <linux/fcntl.h> 
#include <asm/uaccess.h> 
#include <linux/regulator/consumer.h>
// #include <linux/mfd/max8998.h>
// #include <linux/mfd/max8997.h>

#include "sii9244_driver.h"
#include "Common_Def.h"

#include <linux/mutex.h>
extern hdmi_common_send_uevent(u8 code);
extern hdmi_common_send_keyevent(u8 code);

#define SUBJECT "MHL_DRIVER"

#define SII_DEV_DBG(format,...)\
	printk ("[ "SUBJECT " (%s,%d) ] " format "\n", __func__, __LINE__, ## __VA_ARGS__);

struct work_struct sii9244_int_work;
struct workqueue_struct *sii9244_wq = NULL;

struct i2c_driver sii9244_i2c_driver;
struct i2c_client *sii9244_i2c_client = NULL;

struct i2c_driver sii9244a_i2c_driver;
struct i2c_client *sii9244a_i2c_client = NULL;

struct i2c_driver sii9244b_i2c_driver;
struct i2c_client *sii9244b_i2c_client = NULL;

struct i2c_driver sii9244c_i2c_driver;
struct i2c_client *sii9244c_i2c_client = NULL;

extern bool sii9244_init(void);

extern int hpd_enable_control(int on);

struct mhl_rcp_dev{
	char *name;
	struct device *dev;
	unsigned char code;
};
static struct i2c_device_id sii9244_id[] = {
	{"SII9244", 0},
	{}
};

static struct i2c_device_id sii9244a_id[] = {
	{"SII9244A", 0},
	{}
};

static struct i2c_device_id sii9244b_id[] = {
	{"SII9244B", 0},
	{}
};

static struct i2c_device_id sii9244c_id[] = {
	{"SII9244C", 0},
	{}
};

int MHL_i2c_init = 0;


struct sii9244_state {
	struct i2c_client *client;
};

void sii9244_cfg_power(bool on);

static void sii9244_cfg_gpio(void);

irqreturn_t mhl_int_irq_handler(int irq, void *dev_id);

irqreturn_t mhl_wake_up_irq_handler(int irq, void *dev_id);

void sii9244_interrupt_event_work(struct work_struct *p);

#define MHL_SWITCH_TEST	1

#ifdef MHL_SWITCH_TEST
struct class *sec_mhl;
EXPORT_SYMBOL(sec_mhl);

struct device *mhl_switch;
EXPORT_SYMBOL(mhl_switch);

static ssize_t check_MHL_command(struct device *dev, struct device_attribute *attr, char *buf)
{
	int count;
	int res;
	SII_DEV_DBG();

	printk(KERN_ERR "[MHL]: check_MHL_command\n");
	sii9244_cfg_power(1);
	res = SiI9244_startTPI();
	count = sprintf(buf,"%d\n", res );
	sii9244_cfg_power(0);
	return count;

}

static ssize_t change_switch_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t size)
{
	char *after;
	unsigned long value = simple_strtoul(buf, &after, 10);
	int i;
	SII_DEV_DBG();

	printk(KERN_ERR "[MHL_SWITCH] Change the switch: %ld\n", value);

	if (value == 0) {
		for (i = 0; i <20; i++) {
			printk(KERN_ERR "[MHL] try %d\n", i+1);
			msleep(500);
		}
#if 0
		s3c_gpio_cfgpin(GPIO_MHL_INT, GPIO_MHL_INT_AF);
		s3c_gpio_setpull(GPIO_MHL_SEL, S3C_GPIO_PULL_UP);
		gpio_set_value(GPIO_MHL_SEL, GPIO_LEVEL_HIGH);
#endif
//		gpio_request(GPIO_MHL_INT, "MHL_INT");
		gpio_direction_input(GPIO_MHL_INT);
		request_irq(gpio_to_irq(GPIO_MHL_INT), mhl_int_irq_handler, IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING, "mhl_irq", dev); 
		sii9244_cfg_power(1);
		sii9244_init();
	} else {	
		sii9244_cfg_power(0);
#if 0		
		s3c_gpio_setpull(GPIO_MHL_SEL, S3C_GPIO_PULL_NONE);
		gpio_set_value(GPIO_MHL_SEL, GPIO_LEVEL_LOW);
#endif
//		gpio_request(GPIO_MHL_SEL, "MUIC/MHL SEL");
		gpio_direction_output(GPIO_MHL_SEL, GPIO_LEVEL_LOW);
		gpio_set_value(GPIO_MHL_SEL, GPIO_LEVEL_LOW);
	}
	return size;
}

void MHL_On(bool on)
{
	//static DEFINE_MUTEX(mutex);
	//mutex_lock(&mutex);
	SII_DEV_DBG();

	printk("[MHL] USB path change : %d\n", on);
	if (on == 1) {
		if(gpio_get_value(GPIO_MHL_SEL))
			printk("[MHL] GPIO_MHL_SEL : already 1\n");
		else {
			//gpio_set_value(GPIO_MHL_SEL, GPIO_LEVEL_HIGH);
			sii9244_cfg_power(1);
			sii9244_init();
 			gpio_set_value(GPIO_MHL_SEL, GPIO_LEVEL_HIGH); //daniel for mass product issue
		}	
	} else {
		if(!gpio_get_value(GPIO_MHL_SEL))
			printk("[MHL] GPIO_MHL_SEL : already 0\n");
		else {	
			gpio_set_value(GPIO_MHL_SEL, GPIO_LEVEL_LOW);
			sii9244_cfg_power(0);
//			gpio_set_value(GPIO_MHL_SEL, GPIO_LEVEL_LOW);
		}
	}
	//printk("[MHL] USB path change : %d \tP940 MHL Muxtex end\n", on);

	//mutex_unlock(&mutex);
}
EXPORT_SYMBOL(MHL_On);


static DEVICE_ATTR(mhl_sel, S_IRUGO | S_IWUSR | S_IXOTH, check_MHL_command, change_switch_store);
#endif

static ssize_t MHD_check_read(struct device *dev, struct device_attribute *attr, char *buf)
{
	int count;
	int res = 0;
	#if 0
	SII_DEV_DBG();

	s3c_gpio_setpull(GPIO_MHL_SEL, S3C_GPIO_PULL_UP);	//MHL_SEL

	gpio_set_value(GPIO_MHL_SEL, GPIO_LEVEL_HIGH);
	

	//TVout_LDO_ctrl(true);
	
	if(!MHD_HW_IsOn())
	{
		sii9244_tpi_init();
		res = MHD_Read_deviceID();
		MHD_HW_Off();		
	}
	else
	{
		sii9244_tpi_init();
		res = MHD_Read_deviceID();
	}

	I2C_WriteByte(0x72, 0xA5, 0xE1);
	res = 0;
	res = I2C_ReadByte(0x72, 0xA5);

	printk(KERN_ERR "A5 res %x",res);

	res = 0;
	res = I2C_ReadByte(0x72, 0x1B);

	printk(KERN_ERR "Device ID res %x",res);

	res = 0;
	res = I2C_ReadByte(0x72, 0x1C);

	printk(KERN_ERR "Device Rev ID res %x",res);

	res = 0;
	res = I2C_ReadByte(0x72, 0x1D);

	printk(KERN_ERR "Device Reserved ID res %x",res);

	printk(KERN_ERR "\n####HDMI_EN1 %x MHL_RST %x GPIO_MHL_SEL %x\n",gpio_get_value(GPIO_HDMI_EN),gpio_get_value(GPIO_MHL_RST),gpio_get_value(GPIO_MHL_SEL));

	res = I2C_ReadByte(0x7A, 0x3D);

	res = I2C_ReadByte(0x7A, 0xFF);
		
	s3c_gpio_setpull(GPIO_MHL_SEL, S3C_GPIO_PULL_NONE);	//MHL_SEL

	gpio_set_value(GPIO_MHL_SEL, GPIO_LEVEL_LOW);
#endif
	count = sprintf(buf,"%d\n", res );
	//TVout_LDO_ctrl(false);
	return count;
}

static ssize_t MHD_check_write(struct device *dev, struct device_attribute *attr, const char *buf, size_t size)
{
	printk(KERN_ERR "input data --> %s\n", buf);

	return size;
}

static DEVICE_ATTR(MHD_file, S_IRUGO , MHD_check_read, MHD_check_write);


struct i2c_client* get_sii9244_client(u8 device_id)
{

	struct i2c_client* client_ptr;

	if(device_id == 0x72)
		client_ptr = sii9244_i2c_client;
	else if(device_id == 0x7A)
		client_ptr = sii9244a_i2c_client;
	else if(device_id == 0x92)
		client_ptr = sii9244b_i2c_client;
	else if(device_id == 0xC8)
		client_ptr = sii9244c_i2c_client;
	else
		client_ptr = NULL;

	return client_ptr;
}
EXPORT_SYMBOL(get_sii9244_client);

u8 sii9244_i2c_read(struct i2c_client *client, u8 reg)
{
	u8 ret;
	//SII_DEV_DBG();

	if(!MHL_i2c_init)
	{
		SII_DEV_DBG("I2C not ready");
		return 0;
	}
	
	i2c_smbus_write_byte(client, reg);
	

	ret = i2c_smbus_read_byte(client);

	//printk(KERN_ERR "#######Read reg %x data %x\n", reg, ret);

	if (ret < 0)
	{
		SII_DEV_DBG("i2c read fail");
		return -EIO;
	}
	return ret;

}
EXPORT_SYMBOL(sii9244_i2c_read);


int sii9244_i2c_write(struct i2c_client *client, u8 reg, u8 data)
{
	//SII_DEV_DBG();

	if(!MHL_i2c_init)
	{
		SII_DEV_DBG("I2C not ready");
		return 0;
	}

	//printk(KERN_ERR "#######Write reg %x data %x\n", reg, data);
	return i2c_smbus_write_byte_data(client, reg, data);
}
EXPORT_SYMBOL(sii9244_i2c_write);


void sii9244_interrupt_event_work(struct work_struct *p)
{

	printk(KERN_ERR "[MHL]sii9244_interrupt_event_work() is called\n");
	sii9244_interrupt_event();
}


void mhl_int_irq_handler_sched(void)
{
	//printk(KERN_ERR "mhl_int_irq_handler_sched() is called\n");
	queue_work(sii9244_wq, &sii9244_int_work);		
}


irqreturn_t mhl_int_irq_handler(int irq, void *dev_id)
{
	printk(KERN_ERR "[MHL]mhl_int_irq_handler() is called\n");

	if (gpio_get_value(GPIO_MHL_SEL))	
		mhl_int_irq_handler_sched();

	return IRQ_HANDLED;
}

#if 0
void rcp_cbus_uevent(u8 rcpCode)	
{
	char env_buf[120];
	u8 code= 0x0;


	memset(env_buf, 0, sizeof(env_buf));
	printk("%s : RCP Message Recvd , rcpCode =0x%x\n",__func__,rcpCode);

	switch(rcpCode)
	{
	case 0x60: // Play Function
		code = 0x44;
		break;
	case 0x61: //Pause_Play Func
		code =  0x46;
		break;
	case 0x64://Stop Function
		code = 0x45;
		break;
	default:
		code = rcpCode;
		break;
	}

	printk("%s : change code , rcpCode =0x%x\n",__func__,code);
		
	sprintf(env_buf, "MHL_RCP=%d", code);	

       hdmi_common_send_uevent(env_buf);
	return;
}
#else
void rcp_cbus_uevent(u8 rcpCode)	
{
	u8 code= 0x0;

	printk("%s : RCP Message Recvd , rcpCode =0x%x\n",__func__,rcpCode);

	code = rcpCode;

	printk("%s : change code , rcpCode =0x%x\n",__func__,code);

	hdmi_common_send_keyevent(code);		
	//hdmi_common_send_uevent(code);
	return;
}

#endif
EXPORT_SYMBOL(rcp_cbus_uevent);
 
irqreturn_t mhl_wake_up_irq_handler(int irq, void *dev_id)
{

	printk(KERN_ERR "mhl_wake_up_irq_handler() is called\n");

	if (gpio_get_value(GPIO_MHL_SEL))	
		mhl_int_irq_handler_sched();
	
	return IRQ_HANDLED;
}

static int sii9244_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	/* int retval; */

	struct sii9244_state *state;

	struct class *mhl_class;
	struct device *mhl_dev;

	SII_DEV_DBG();


	state = kzalloc(sizeof(struct sii9244_state), GFP_KERNEL);
	if (state == NULL) {		
		printk(KERN_ERR "failed to allocate memory \n");
		return -ENOMEM;
	}
	
	state->client = client;
	i2c_set_clientdata(client, state);


	
	/* rest of the initialisation goes here. */
	
	printk(KERN_ERR "SII9244 attach success!!!\n");

	sii9244_i2c_client = client;

	MHL_i2c_init = 1;

	mhl_class = class_create(THIS_MODULE, "mhl");
	if (IS_ERR(mhl_class))
	{
		pr_err("Failed to create class(mhl)!\n");
	}

	mhl_dev = device_create(mhl_class, NULL, 0, NULL, "mhl_dev");
	if (IS_ERR(mhl_dev))
	{
		pr_err("Failed to create device(mhl_dev)!\n");
	}

	if (device_create_file(mhl_dev, &dev_attr_MHD_file) < 0)
		printk(KERN_ERR "Failed to create device file(%s)!\n", dev_attr_MHD_file.attr.name);

	return 0;

}



static int __devexit sii9244_remove(struct i2c_client *client)
{
	struct sii9244_state *state = i2c_get_clientdata(client);
	kfree(state);

	return 0;
}

static int sii9244a_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct sii9244_state *state;
	SII_DEV_DBG();

	state = kzalloc(sizeof(struct sii9244_state), GFP_KERNEL);
	if (state == NULL) {		
		printk(KERN_ERR "failed to allocate memory \n");
		return -ENOMEM;
	}
	
	state->client = client;
	i2c_set_clientdata(client, state);
	
	/* rest of the initialisation goes here. */
	
	printk(KERN_ERR "SII9244A attach success!!!\n");

	sii9244a_i2c_client = client;

	return 0;

}



static int __devexit sii9244a_remove(struct i2c_client *client)
{
	struct sii9244_state *state = i2c_get_clientdata(client);
	kfree(state);
	return 0;
}

static int sii9244b_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct sii9244_state *state;
	SII_DEV_DBG();

	state = kzalloc(sizeof(struct sii9244_state), GFP_KERNEL);
	if (state == NULL) {		
		printk(KERN_ERR "failed to allocate memory \n");
		return -ENOMEM;
	}
	
	state->client = client;
	i2c_set_clientdata(client, state);
	
	/* rest of the initialisation goes here. */
	
	printk(KERN_ERR "SII9244B attach success!!!\n");

	sii9244b_i2c_client = client;

	
	return 0;

}



static int __devexit sii9244b_remove(struct i2c_client *client)
{
	struct sii9244_state *state = i2c_get_clientdata(client);
	kfree(state);
	return 0;
}


static int sii9244c_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct sii9244_state *state;
	int ret;
	SII_DEV_DBG();

	state = kzalloc(sizeof(struct sii9244_state), GFP_KERNEL);
	if (state == NULL) {		
		printk(KERN_ERR "failed to allocate memory \n");
		return -ENOMEM;
	}
	
	state->client = client;
	i2c_set_clientdata(client, state);
	
	/* rest of the initialisation goes here. */
	
	printk(KERN_ERR "SII9244C attach success!!!\n");

	sii9244c_i2c_client = client;

	msleep(100);	

	sii9244_wq = create_singlethread_workqueue("sii9244_wq");
	INIT_WORK(&sii9244_int_work, sii9244_interrupt_event_work);

#if 0		
	ret = request_threaded_irq(MHL_INT_IRQ, NULL, mhl_int_irq_handler,
				IRQF_SHARED , "mhl_int", (void *) state); 
#endif
	ret = request_threaded_irq(gpio_to_irq(GPIO_MHL_INT), NULL, mhl_int_irq_handler,
				IRQF_TRIGGER_FALLING | IRQF_ONESHOT, "mhl_int", (void *) state); 

	if (ret) {
		printk(KERN_ERR "unable to request irq mhl_int"
					" err:: %d\n", ret);
		return ret;
	}		
	printk(KERN_ERR "MHL int reques successful %d\n", ret);

#if 0		
	ret = request_threaded_irq(MHL_WAKEUP_IRQ, NULL,
		mhl_wake_up_irq_handler, IRQF_SHARED,
		"mhl_wake_up", (void *) state);

//	ret = request_threaded_irq(gpio_to_irq(GPIO_MHL_WAKE_UP), NULL,
//		mhl_wake_up_irq_handler, IRQF_SHARED,
//		"mhl_wake_up", (void *) state);

	ret = request_irq(gpio_to_irq(GPIO_MHL_WAKE_UP), mhl_wake_up_irq_handler, IRQF_TRIGGER_FALLING | IRQF_SHARED, "mhl_wake_up", (void *) state); 
//	if (ret < 0){
//		printk(KERN_INFO "[MHL INT] GPIO 160 IRQ line set up failed!\n");
//		free_irq(gpio_to_irq(GPIO_MHL_WAKE_UP), (void *) state);
//	}	


	if (ret) {
		printk(KERN_ERR "unable to request irq mhl_wake_up"
					" err:: %d\n", ret);
		return ret;
	}		
#endif
	
	return 0;

}



static int __devexit sii9244c_remove(struct i2c_client *client)
{
	struct sii9244_state *state = i2c_get_clientdata(client);
	kfree(state);
	return 0;
}

struct i2c_driver sii9244_i2c_driver = {
	.driver = {
		.owner	= THIS_MODULE,
		.name	= "SII9244",
	},
	.id_table	= sii9244_id,
	.probe	= sii9244_i2c_probe,
	.remove	= __devexit_p(sii9244_remove),
	.command = NULL,
};

struct i2c_driver sii9244a_i2c_driver = {
	.driver = {
		.owner	= THIS_MODULE,
		.name	= "SII9244A",
	},
	.id_table	= sii9244a_id,
	.probe	= sii9244a_i2c_probe,
	.remove	= __devexit_p(sii9244a_remove),
	.command = NULL,
};

struct i2c_driver sii9244b_i2c_driver = {
	.driver = {
		.owner	= THIS_MODULE,
		.name	= "SII9244B",
	},
	.id_table	= sii9244b_id,
	.probe	= sii9244b_i2c_probe,
	.remove	= __devexit_p(sii9244b_remove),
	.command = NULL,
};

struct i2c_driver sii9244c_i2c_driver = {
	.driver = {
		.owner	= THIS_MODULE,
		.name	= "SII9244C",
	},
	.id_table	= sii9244c_id,
	.probe	= sii9244c_i2c_probe,
	.remove	= __devexit_p(sii9244c_remove),
	.command = NULL,
};


extern struct device * fimc_get_active_device(void);


void sii9244_cfg_power(bool on)
{

	if(on)
	{
#if 0	
//		s3c_gpio_cfgpin(GPIO_HDMI_EN,S3C_GPIO_OUTPUT);	//HDMI_EN
#ifdef CONFIG_TARGET_LOCALE_KOR
		gpio_set_value(GPIO_HDMI_EN,GPIO_LEVEL_HIGH);
#else
		if(system_rev < 7)
			gpio_set_value(GPIO_HDMI_EN,GPIO_LEVEL_HIGH);
		else
			gpio_set_value(GPIO_HDMI_EN_REV07,GPIO_LEVEL_HIGH);
#endif


		s3c_gpio_cfgpin(GPIO_MHL_RST,S3C_GPIO_OUTPUT);	//MHL_RST
		s3c_gpio_setpull(GPIO_MHL_RST, S3C_GPIO_PULL_NONE);
	

		s3c_gpio_setpull(GPIO_AP_SCL_18V, S3C_GPIO_PULL_DOWN);
		gpio_set_value(GPIO_MHL_RST, GPIO_LEVEL_LOW);
		msleep(10);
		gpio_set_value(GPIO_MHL_RST, GPIO_LEVEL_HIGH);
		s3c_gpio_setpull(GPIO_AP_SCL_18V, S3C_GPIO_PULL_NONE);
#endif
		hpd_enable_control(1);

//		gpio_request(GPIO_HDMI_EN, "MHL_EN");
		gpio_direction_output(GPIO_HDMI_EN, GPIO_LEVEL_LOW);
		gpio_set_value(GPIO_HDMI_EN, GPIO_LEVEL_HIGH);


//		gpio_request(GPIO_MHL_RST, "MHL_RESET_N");
		gpio_direction_output(GPIO_MHL_RST, GPIO_LEVEL_LOW);
		gpio_set_value(GPIO_MHL_RST, GPIO_LEVEL_LOW);
		msleep(10);
		gpio_set_value(GPIO_MHL_RST, GPIO_LEVEL_HIGH);
	}
	else
	{
		
		gpio_direction_output(GPIO_HDMI_EN, GPIO_LEVEL_LOW);
		gpio_set_value(GPIO_HDMI_EN, GPIO_LEVEL_LOW);

#if 0	
#ifdef CONFIG_TARGET_LOCALE_KOR
		gpio_set_value(GPIO_HDMI_EN,GPIO_LEVEL_HIGH);
#else
		if(system_rev < 7)
		  gpio_set_value(GPIO_HDMI_EN,GPIO_LEVEL_LOW);
		else
			gpio_set_value(GPIO_HDMI_EN_REV07,GPIO_LEVEL_LOW);
#endif
#endif
		gpio_set_value(GPIO_HDMI_EN,GPIO_LEVEL_HIGH);
		msleep(10);
		gpio_set_value(GPIO_HDMI_EN,GPIO_LEVEL_LOW);

		gpio_set_value(GPIO_MHL_RST, GPIO_LEVEL_LOW);
	hpd_enable_control(0);
	}
	printk(KERN_ERR "[MHL]%s : %d \n",__func__,on);

out:
	return;
}


static void sii9244_cfg_gpio()
{
#if 0
	s3c_gpio_cfgpin(GPIO_AP_SDA_18V, S3C_GPIO_SFN(0x0));	//AP_MHL_SDA
	s3c_gpio_setpull(GPIO_AP_SDA_18V, S3C_GPIO_PULL_NONE);

	s3c_gpio_cfgpin(GPIO_AP_SCL_18V,S3C_GPIO_SFN(0x1));	//AP_MHL_SCL
	s3c_gpio_setpull(GPIO_AP_SCL_18V, S3C_GPIO_PULL_NONE);

	s3c_gpio_cfgpin(GPIO_MHL_WAKE_UP,S3C_GPIO_INPUT);//GPH1(6) XEINT 14
	set_irq_type(MHL_WAKEUP_IRQ, IRQ_TYPE_EDGE_RISING);
	s3c_gpio_setpull(GPIO_MHL_WAKE_UP, S3C_GPIO_PULL_DOWN);

	s3c_gpio_setpull(GPIO_MHL_INT, S3C_GPIO_PULL_DOWN);
	set_irq_type(MHL_INT_IRQ, IRQ_TYPE_EDGE_RISING);
	s3c_gpio_cfgpin(GPIO_MHL_INT, GPIO_MHL_INT_AF); 

#ifdef CONFIG_TARGET_LOCALE_KOR
	s3c_gpio_cfgpin(GPIO_HDMI_EN,S3C_GPIO_OUTPUT);	//HDMI_EN
	gpio_set_value(GPIO_HDMI_EN,GPIO_LEVEL_LOW);
	s3c_gpio_setpull(GPIO_HDMI_EN, S3C_GPIO_PULL_NONE);
#else
	if(system_rev < 7) {
		s3c_gpio_cfgpin(GPIO_HDMI_EN,S3C_GPIO_OUTPUT);	//HDMI_EN
		gpio_set_value(GPIO_HDMI_EN,GPIO_LEVEL_LOW);
		s3c_gpio_setpull(GPIO_HDMI_EN, S3C_GPIO_PULL_NONE);
	}
	else {
		s3c_gpio_cfgpin(GPIO_HDMI_EN_REV07,S3C_GPIO_OUTPUT);	//HDMI_EN
		gpio_set_value(GPIO_HDMI_EN_REV07,GPIO_LEVEL_LOW);
		s3c_gpio_setpull(GPIO_HDMI_EN_REV07, S3C_GPIO_PULL_NONE);
	}
#endif

	s3c_gpio_cfgpin(GPIO_MHL_RST,S3C_GPIO_OUTPUT);
	s3c_gpio_setpull(GPIO_MHL_RST, S3C_GPIO_PULL_NONE);
	gpio_set_value(GPIO_MHL_RST, GPIO_LEVEL_LOW);

	s3c_gpio_cfgpin(GPIO_MHL_SEL,S3C_GPIO_OUTPUT);
	s3c_gpio_setpull(GPIO_MHL_SEL, S3C_GPIO_PULL_NONE);
	gpio_set_value(GPIO_MHL_SEL, GPIO_LEVEL_LOW);
#endif		
	gpio_request(GPIO_MHL_INT, "MHL_INT");
	gpio_direction_input(GPIO_MHL_INT);

	gpio_request(GPIO_MHL_SEL, "MUIC/MHL SEL");
	gpio_direction_output(GPIO_MHL_SEL, GPIO_LEVEL_LOW);
//	gpio_set_value(GPIO_MHL_WAKE_UP, GPIO_LEVEL_LOW);	

	gpio_request(GPIO_HDMI_EN, "MHL_EN");
	gpio_direction_output(GPIO_HDMI_EN, GPIO_LEVEL_LOW);
//	gpio_set_value(GPIO_MHL_WAKE_UP, GPIO_LEVEL_LOW);	

	gpio_request(GPIO_MHL_RST, "MHL_RESET_N");
	gpio_direction_output(GPIO_MHL_RST, GPIO_LEVEL_LOW);
	gpio_set_value(GPIO_MHL_RST, GPIO_LEVEL_HIGH);	

	gpio_request(GPIO_MHL_WAKE_UP, "WAKEUP_MHL");
//	gpio_direction_output(GPIO_MHL_WAKE_UP, GPIO_LEVEL_LOW);

//	gpio_direction_input(GPIO_MHL_WAKE_UP);	

//	gpio_set_value(GPIO_MHL_WAKE_UP, GPIO_LEVEL_LOW);	



}

static int mhl_open(struct inode *ip, struct file *fp)
{
	printk(KERN_ERR "[%s] \n",__func__);
	return 0;

}

static int mhl_release(struct inode *ip, struct file *fp)
{
	
	printk(KERN_ERR "[%s] \n",__func__);
	return 0;
}


static int mhl_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg)
{
	printk(KERN_ERR "[%s] \n",__func__);

#if 0
	byte data;

	switch(cmd)
	{
		case MHL_READ_RCP_DATA:
			data = GetCbusRcpData();
			ResetCbusRcpData();
			put_user(data,(byte *)arg);
			printk(KERN_ERR "MHL_READ_RCP_DATA read");
			break;
		
		default:
		break;
	}
#endif		
	return 0;
}

static struct file_operations mhl_fops = {
	.owner  = THIS_MODULE,
	.open   = mhl_open,
    	.release = mhl_release,
    	.ioctl = mhl_ioctl,
};
                 
static struct miscdevice mhl_device = {
    .minor  = MISC_DYNAMIC_MINOR,
    .name   = "mhl",
    .fops   = &mhl_fops,
};

static int __init sii9244_module_init(void)
{
	int ret;

	sii9244_cfg_gpio();

	/* sii9244_cfg_power(1);	//Turn On power to sii9244 
	*/

#ifdef MHL_SWITCH_TEST
	sec_mhl = class_create(THIS_MODULE, "sec_mhl");
	if (IS_ERR(sec_mhl))
		printk(KERN_ERR "[MHL] Failed to create class (sec_mhl)\n");

	mhl_switch = device_create(sec_mhl, NULL, 0, NULL, "switch");
	if (IS_ERR(mhl_switch))
		printk(KERN_ERR "[MHL] Failed to create device (mhl_switch)\n");
	if (device_create_file(mhl_switch, &dev_attr_mhl_sel) < 0)
		printk(KERN_ERR "[MHL] Failed to create file (mhl_sel)");
#endif

	ret = misc_register(&mhl_device);
	if(ret) {
		pr_err(KERN_ERR "misc_register failed - mhl \n");
	}

	ret = i2c_add_driver(&sii9244_i2c_driver);
	if (ret != 0)
		printk(KERN_ERR "[MHL SII9244] can't add i2c driver\n");	
	else
		printk(KERN_ERR "[MHL SII9244] add i2c driver\n");
	ret = i2c_add_driver(&sii9244a_i2c_driver);
	if (ret != 0)
		printk(KERN_ERR "[MHL SII9244A] can't add i2c driver\n");	
	else
		printk(KERN_ERR "[MHL SII9244A] add i2c driver\n");
	ret = i2c_add_driver(&sii9244b_i2c_driver);
	if (ret != 0)
		printk(KERN_ERR "[MHL SII9244B] can't add i2c driver\n");	
	else
		printk(KERN_ERR "[MHL SII9244B] add i2c driver\n");

	ret = i2c_add_driver(&sii9244c_i2c_driver);
	if (ret != 0)
		printk(KERN_ERR "[MHL SII9244C] can't add i2c driver\n");	
	else
		printk(KERN_ERR "[MHL SII9244C] add i2c driver\n");

	return ret;	
}
module_init(sii9244_module_init);
static void __exit sii9244_exit(void)
{
	i2c_del_driver(&sii9244_i2c_driver);
	i2c_del_driver(&sii9244a_i2c_driver);
	i2c_del_driver(&sii9244b_i2c_driver);	
	i2c_del_driver(&sii9244c_i2c_driver);
	
};
module_exit(sii9244_exit);

MODULE_DESCRIPTION("Sii9244 MHL driver");
MODULE_AUTHOR("Jerry Koo");
MODULE_LICENSE("GPL");
