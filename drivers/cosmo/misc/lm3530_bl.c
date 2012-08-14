#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/types.h>
#include <mach/lm3530.h>


#define MODULE_NAME 	"LM3530_BL"


//#define DEBUG

#ifdef DEBUG
#define DBG(fmt, args...)				\
	printk(KERN_ERR "[%s] %s(%d): \n"		\
		fmt, MODULE_NAME, __func__, __LINE__, ## args); 
#else	/* DEBUG */
#define DBG(...) 
#endif

 
int g_osp_lcd_level = 0;

static int	old_brightness	=	-1;

static int get_brightness(int data)
{
	DBG();

	int mLcdBacklightValues[] =   {46,47,48,49,50,51,52,53,54,55,
	56,57,58,59,60,61,62,64,66,68,
	70,71,73,74,75,76,77,78,79,80,
	81,82,83,84,85,86,87,88,88,89,
	90,91,92,93,93,94,95,96,97,98,
	98,98,99,99,100,100,101,101,101,102,
	103,104,105,105,106,106,107,107,108,108,
	109,109,110,110,111,111,111,112,112,113,
	113,113,113,114,114,114,115,115,116,116,
	116,117,117,118,118,119,119,120,120,121,
	121,121,122,122,122,123,123,124,124,124,
	125,125,125,
	};

	return (mLcdBacklightValues[data-15]);
}

/* SYSFS for brightness control */
static ssize_t	brightness_show(struct device* dev, 
		struct device_attribute* attr, char* buf)
{
	struct	lm3530_platform_data*	pdata	=	dev->platform_data;
	int	val;
	DBG();

	if ((val = lm3530_get_brightness_control(&pdata->private)) < 0)
		return	0;

	return	snprintf(buf, PAGE_SIZE, "%d\n", val);
}

static ssize_t	brightness_store(struct device* dev, 
		struct device_attribute* attr, const char* buf, size_t count)
{
	struct	lm3530_platform_data*	pdata	=	dev->platform_data;
	int	brightness	=	simple_strtol(buf, NULL, 10);
	DBG("brightness_store = [%d]",brightness);


	if (brightness > 0 && brightness < 30)	// MIN brightness to be off
		brightness	=	30;

	if ((brightness < 0) || (brightness > 255)) // Invalid brightness
		goto	exit;

	if (old_brightness == brightness) // No need to change the brightness
		goto	exit;

	g_osp_lcd_level = brightness; 

	if (brightness == 0) {	// Zero-Brightness, Turn off LM3530
		lm3530_set_hwen(&pdata->private, pdata->gpio_hwen, 0);
		old_brightness	=	brightness;
		goto	exit;
	}

	//if (old_brightness < brightness) 
	{	// Dimming up
		if (old_brightness == 0)
		{		
			 pdata->private.reg_brr = pdata->private.reg_brr & 0x00;
			lm3530_set_hwen(&pdata->private, pdata->gpio_hwen, 1);	
		}
		else if((pdata->private.reg_brr & 0x24) == 0)
		{
			pdata->private.reg_brr = pdata->private.reg_brr | 0x24;
			lm3530_set_hwen(&pdata->private, pdata->gpio_hwen, 1);				
		}
	}
	//lm3530_set_brightness_control(&pdata->private, (brightness>>1));
//	lm3530_set_brightness_control(&pdata->private, get_brightness(brightness >> 1));
	lm3530_set_brightness_control(&pdata->private, get_brightness(brightness));


	old_brightness	=	brightness;

exit:
	return	count;
}

static DEVICE_ATTR(brightness, 0664, brightness_show, brightness_store);

/* SYSFS for LCD backlight ON/OFF
 */
static ssize_t	enable_show(struct device* dev, 
		struct device_attribute* attr, char *buf)
{
	struct	lm3530_platform_data*	pdata	=	dev->platform_data;
	int	val	=	lm3530_get_hwen(&pdata->private, pdata->gpio_hwen);
	DBG();

	return	snprintf(buf, PAGE_SIZE, "%d\n", val);
}

static ssize_t	enable_store(struct device* dev, 
		struct device_attribute* attr, const char* buf, size_t count)
{
	struct	lm3530_platform_data*	pdata	=	dev->platform_data;
	DBG();

//	DEBUG_MSG("enable_store = [%d] \n",(int)simple_strtol(buf, NULL, 10));

	lm3530_set_hwen(&pdata->private, pdata->gpio_hwen, (int)simple_strtol(buf, NULL, 10));

	return	count;
}

static DEVICE_ATTR(enable, 0664, enable_show, enable_store);

/* Driver
 */
static int __devinit lm3530bl_probe(struct i2c_client* client,
							const struct i2c_device_id* id)
{
	struct lm3530_platform_data*	pdata;
	int		ret = 0;
	DBG();

	pdata	=	client->dev.platform_data;
	gpio_request(pdata->gpio_hwen, "backlight_enable");
	gpio_direction_output(pdata->gpio_hwen, 1);	// OUTPUT

	lm3530_init(&pdata->private, client);

	ret = device_create_file(&client->dev, &dev_attr_brightness);
	ret = device_create_file(&client->dev, &dev_attr_enable);

	old_brightness	=	lm3530_get_brightness_control(&pdata->private);

	return	ret;
}

static int __devexit lm3530bl_remove(struct i2c_client* client)
{
	device_remove_file(&client->dev, &dev_attr_brightness);
	device_remove_file(&client->dev, &dev_attr_enable);	
	return	0;
}

static const struct i2c_device_id lm3530bl_ids[] = {
	{	LM3530_I2C_NAME, 0 },	// LM3530
	{},
};

static struct i2c_driver lm3530bl_driver = {
	.probe		= lm3530bl_probe,
	.remove		= __devexit_p(lm3530bl_remove),
	.id_table	= lm3530bl_ids,
	.driver = {
		.name	= LM3530_I2C_NAME,
		.owner	= THIS_MODULE,
	},
};

static int __init lm3530bl_init(void)
{
	DBG();

	return	i2c_add_driver(&lm3530bl_driver);
}

static void __exit lm3530bl_exit(void)
{
	i2c_del_driver(&lm3530bl_driver);
}

module_init(lm3530bl_init);
module_exit(lm3530bl_exit);

MODULE_AUTHOR("LG Electronics");
MODULE_DESCRIPTION("Backlight driver (LM3530)");
MODULE_LICENSE("GPL");
