#include <mach/lm3530.h>

#define MODULE_NAME 	"LM3530"


//#define DEBUG

#ifdef DEBUG
#define DBG(fmt, args...)				\
	printk(KERN_ERR "[%s] %s(%d): \n"		\
		fmt, MODULE_NAME, __func__, __LINE__, ## args); 
#else	/* DEBUG */
#define DBG(...) 
#endif


static int	lm3530_read_byte(struct lm3530_private_data* pdata, int reg)
{
	int		ret;
	DBG();

	mutex_lock(&pdata->update_lock);
	ret	=	i2c_smbus_read_byte_data(pdata->client, reg);
	mutex_unlock(&pdata->update_lock);

	return	ret;
}

static int	lm3530_write_byte(struct lm3530_private_data* pdata, int reg, int value)
{
	int		ret;
	DBG();

	mutex_lock(&pdata->update_lock);
	ret	=	i2c_smbus_write_byte_data(pdata->client, reg, value);
	mutex_unlock(&pdata->update_lock);

	return	ret;
}

static void	lm3530_store(struct lm3530_private_data* pdata)
{
	DBG();

	lm3530_write_byte(pdata, LM3530_REG_GP, pdata->reg_gp);
	lm3530_write_byte(pdata, LM3530_REG_BRR, pdata->reg_brr);
	lm3530_write_byte(pdata, LM3530_REG_BRT, pdata->reg_brt);

}

static void	lm3530_load(struct lm3530_private_data* pdata)
{
	DBG();

	pdata->reg_gp	=	lm3530_read_byte(pdata, LM3530_REG_GP);
	pdata->reg_brr   =       lm3530_read_byte(pdata, LM3530_REG_BRR);
	pdata->reg_brt	=	lm3530_read_byte(pdata, LM3530_REG_BRT);
}

int	lm3530_set_hwen(struct lm3530_private_data* pdata, int gpio, int status)
{
	DBG();

	if (status == 0) {
		printk("[LM3530] backlight OFF!!!!! lm3530_set_hwen status = 0\n");
		lm3530_load(pdata);
		gpio_set_value(gpio, 0);
		return	0;
	}

	printk("[LM3530] backlight ON!!!! lm3530_set_hwen status = 1\n");
	gpio_set_value(gpio, 1);
	lm3530_store(pdata);

	return	1;
}

int	lm3530_get_hwen(struct lm3530_private_data* pdata, int gpio)
{
	DBG();

	return	gpio_get_value(gpio);
}

int	lm3530_set_brightness_control(struct lm3530_private_data* pdata, int val)
{
	DBG();

	if ((val < 0) || (val > 255))
		return	-EINVAL;

	return	lm3530_write_byte(pdata, LM3530_REG_BRT, val);
}

int	lm3530_get_brightness_control(struct lm3530_private_data* pdata)
{
	int		val;
	DBG();

	val	=	lm3530_read_byte(pdata, LM3530_REG_BRT);
	if (val < 0)
		return	val;

	return	(val & LM3530_BMASK);
}

int	lm3530_init(struct lm3530_private_data* pdata, struct i2c_client* client)
{
	DBG();

	mutex_init(&pdata->update_lock);
	pdata->client	=	client;

	lm3530_load(pdata);

	return 0;
}

EXPORT_SYMBOL(lm3530_init);
EXPORT_SYMBOL(lm3530_set_hwen);
EXPORT_SYMBOL(lm3530_get_hwen);
EXPORT_SYMBOL(lm3530_set_brightness_control);
EXPORT_SYMBOL(lm3530_get_brightness_control);

MODULE_AUTHOR("LG Electronics (dongjin73.kim@lge.com)");
MODULE_DESCRIPTION("Multi Display LED driver");
MODULE_LICENSE("GPL");
