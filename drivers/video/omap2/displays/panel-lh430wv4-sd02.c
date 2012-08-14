/*
 * Cosmopolitan mipi interface support
 *
 */

#include <linux/module.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
//#include <linux/i2c/twl6030.h>
#include <linux/spi/spi.h>
#include <linux/i2c.h>
#include <plat/mux.h>
#include <linux/err.h>
#include <linux/jiffies.h>
#include <linux/sched.h>
#include <linux/backlight.h>
#include <linux/fb.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/completion.h>
#include <linux/workqueue.h>
#include <linux/hrtimer.h>

#include <plat/gpio.h>
#include <asm/mach-types.h>
#include <plat/control.h>

#include <plat/display.h>

#include <plat/dmtimer.h>

#include "panel-lh430wv4-sd02.h"

#define MODULE_NAME 	"LH430WV4_LCD"


//#define DEBUG

#ifdef DEBUG
#define DBG(fmt, args...)				\
	printk(KERN_ERR "[%s] %s(%d): \n"		\
		fmt, MODULE_NAME, __func__, __LINE__, ## args); 
#else	/* DEBUG */
#define DBG(...) 
#endif


//#define DSI_VIDEO_MODE /* BRAD */
#define LH430WV4_LCD

/* DSI Virtual channel. Hardcoded for now. */
#define TCH 0

#define DCS_READ_NUM_ERRORS		0x05
#define DCS_READ_POWER_MODE		0x0a
#define DCS_READ_MADCTL			0x0b
#define DCS_READ_PIXEL_FORMAT		0x0c
#define DCS_RDDSDR			0x0f
#define DCS_SLEEP_IN			0x10
#define DCS_SLEEP_OUT			0x11
#define DCS_DISPLAY_OFF			0x28
#define DCS_DISPLAY_ON			0x29
#define DCS_COLUMN_ADDR			0x2a
#define DCS_PAGE_ADDR			0x2b
#define DCS_MEMORY_WRITE		0x2c
#define DCS_TEAR_OFF			0x34
#define DCS_TEAR_ON			0x35
#define DCS_MEM_ACC_CTRL		0x36
#define DCS_PIXEL_FORMAT		0x3a
#define DCS_BRIGHTNESS			0x51
#define DCS_CTRL_DISPLAY		0x53
#define DCS_WRITE_CABC			0x55
#define DCS_READ_CABC			0x56
#define DCS_DEEP_STANDBY_IN		0xC1
#define DCS_GET_ID			0xf8

#define DSI_DT_DCS_SHORT_WRITE_0	0x05
#define DSI_DT_DCS_SHORT_WRITE_1	0x15
#define DSI_DT_DCS_READ			0x06
#define DSI_DT_SET_MAX_RET_PKG_SIZE	0x37
#define DSI_DT_NULL_PACKET		0x09
#define DSI_DT_DCS_LONG_WRITE		0x39


#define DSI_GEN_SHORTWRITE_NOPARAM 0x3
#define DSI_GEN_SHORTWRITE_1PARAM 0x13
#define DSI_GEN_SHORTWRITE_2PARAM 0x23
#define DSI_GEN_LONGWRITE 0x29

/* #define LH430WV4_PANEL_USE_ESD_CHECK */
#define LH430WV4_PANEL_ESD_CHECK_PERIOD	msecs_to_jiffies(5000)

#define LH430WV4_PANEL_LCD_RESET_N			30
#define LH430WV4_PANEL_LCD_EN				27

#define LONG_CMD_MIPI	0
#define SHORT_CMD_MIPI	1
#define END_OF_COMMAND	2

static struct omap_dss_device *omapdssdev;
int lm3528_brightness_3D_Enable = 0;


u8 lgd_lcd_command_for_mipi[][30] = {
#if 0
	{SHORT_CMD_MIPI, DSI_GEN_SHORTWRITE_1PARAM, 0x01, 0x20,},
	{SHORT_CMD_MIPI, DSI_GEN_SHORTWRITE_2PARAM, 0x02, 0x3A, 0x77},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x03, 0xB2, 0x00, 0xC7,},
	{SHORT_CMD_MIPI, DSI_GEN_SHORTWRITE_2PARAM, 0x02, 0xB3, 0x00},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x08, 0xB5, 0x07, 0x15, 0x15, 0x00, 0x20, 0x15, 0x00,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x09, 0xB6, 0x00, 0x18, 0x82, 0x40, 0x10, 0x10, 0x00, 0x00,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x08, 0xB7, 0x52, 0x00, 0x06, 0x00, 0x0C, 0x00, 0x00},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x04, 0xC0, 0x01, 0x08, 0x10,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x03, 0xC2, 0x07, 0x00,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x06, 0xC3, 0x20, 0x67, 0x00, 0x08, 0x08,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x07, 0xC4, 0x10, 0x02, 0x00, 0x00, 0x22, 0xAA,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x06, 0xC5, 0x04, 0x33, 0x04, 0x04, 0x04,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x03, 0xC6, 0x22, 0x00,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x06, 0xC7, 0x04, 0x98, 0x18, 0x65, 0x00,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x03, 0xC8, 0x24, 0x40,},
#endif
#if 0
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD0, 0x00, 0x16, 0x62, 0x35, 0x02, 0x00, 0x30, 0x00, 0x03,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD1, 0x00, 0x16, 0x62, 0x35, 0x02, 0x00, 0x30, 0x00, 0x03,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD2, 0x00, 0x16, 0x62, 0x35, 0x02, 0x00, 0x30, 0x00, 0x03,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD3, 0x00, 0x16, 0x62, 0x35, 0x02, 0x00, 0x30, 0x00, 0x03,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD4, 0x00, 0x16, 0x62, 0x35, 0x02, 0x00, 0x30, 0x00, 0x03,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD5, 0x00, 0x16, 0x62, 0x35, 0x02, 0x00, 0x30, 0x00, 0x03,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x06, 0xE0, 0x47, 0x40, 0x80, 0x00, 0x00,},
	{END_OF_COMMAND,},
#endif
#if 1
	{SHORT_CMD_MIPI, DSI_GEN_SHORTWRITE_1PARAM, 0x01, 0x20,},
	{SHORT_CMD_MIPI, DSI_GEN_SHORTWRITE_2PARAM, 0x02, 0x35, 0x00,},
	{SHORT_CMD_MIPI, DSI_GEN_SHORTWRITE_2PARAM, 0x02, 0x3A, 0x77,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x03, 0xB2, 0x00, 0xC7,},
	{SHORT_CMD_MIPI, DSI_GEN_SHORTWRITE_2PARAM, 0x02, 0xB3, 0x02,},
	{SHORT_CMD_MIPI, DSI_GEN_SHORTWRITE_2PARAM, 0x02, 0xB4, 0x04,},
//	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x08, 0xB5, 0x29, 0x10, 0x10, 0x00, 0x20, 0x00, 0x00,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x08, 0xB5, 0x20, 0x10, 0x10, 0x00, 0x20, 0x00, 0x00,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x09, 0xB6, 0x00, 0x22, 0x02, 0x40, 0x20, 0x20, 0x05, 0x30,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x08, 0xB7, 0x52, 0x00, 0x10, 0x00, 0x0C, 0x00, 0x00,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x04, 0xC0, 0x00, 0x0B, 0x0F,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x03, 0xC2, 0x07, 0x00,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x06, 0xC3, 0x20, 0x67, 0x00, 0x08, 0x08,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x07, 0xC4, 0x01, 0x17, 0x00, 0x00, 0x33, 0x1A,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x06, 0xC5, 0x12, 0x32, 0x14, 0x14, 0x12,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x03, 0xC6, 0x22, 0x00,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x06, 0xC7, 0x04, 0x1A, 0x1A, 0x6E, 0x00,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x03, 0xC8, 0x44, 0x63,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x06, 0xE0, 0X43, 0x40, 0x80, 0x00, 0x00,},
#endif
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD0, 0x20, 0x06, 0x76, 0x06, 0x02, 0x18, 0x40, 0x11, 0x04,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD1, 0x20, 0x06, 0x76, 0x06, 0x01, 0x00, 0x40, 0x11, 0x04,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD2, 0x20, 0x06, 0x76, 0x06, 0x02, 0x18, 0x40, 0x11, 0x04,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD3, 0x20, 0x06, 0x76, 0x06, 0x01, 0x00, 0x40, 0x11, 0x04,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD4, 0x20, 0x06, 0x76, 0x06, 0x02, 0x18, 0x40, 0x11, 0x04,},
	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x0A, 0xD5, 0x20, 0x06, 0x76, 0x06, 0x01, 0x00, 0x40, 0x11, 0x04,},

//	{LONG_CMD_MIPI, DSI_GEN_LONGWRITE, 0x06, 0xE0, 0x47, 0x40, 0x80, 0x00, 0x00,},
	{END_OF_COMMAND,},
};

static void lh430wv4_panel_esd_work(struct work_struct *work);
extern void dsi_enable_video_mode(struct omap_dss_device *dssdev);
extern void dsi_enable_cmd_video_mode(struct omap_dss_device *dssdev);
extern int dispc_enable_gamma(enum omap_channel ch, u8 gamma);


static void hw_guard_start(struct lh430wv4_panel_data *td, int guard_msec)
{
	DBG();
	td->hw_guard_wait = msecs_to_jiffies(guard_msec);
	td->hw_guard_end = jiffies + td->hw_guard_wait;
}

static void hw_guard_wait(struct lh430wv4_panel_data *td)
{
	unsigned long wait = td->hw_guard_end - jiffies;
	DBG();

	if ((long)wait > 0 && wait <= td->hw_guard_wait) {
		set_current_state(TASK_UNINTERRUPTIBLE);
		schedule_timeout(wait);
	}
}

static int lh430wv4_panel_dcs_read_1(u8 dcs_cmd, u8 *data)
{
	int r;
	u8 buf[1];
	DBG();

	r = dsi_vc_dcs_read(1,TCH, dcs_cmd, buf, 1);

	if (r < 0)
		return r;

	*data = buf[0];

	return 0;
}

static int lh430wv4_panel_dcs_write_0(u8 dcs_cmd)
{
	DBG();

	return dsi_vc_dcs_write(1,TCH, &dcs_cmd, 1);
}

static int lh430wv4_panel_dcs_write_1(u8 dcs_cmd, u8 param)
{
	u8 buf[2];
	buf[0] = dcs_cmd;
	buf[1] = param;
	DBG();

	return dsi_vc_dcs_write(1,TCH, buf, 2);
}

static int lh430wv4_panel_sleep_in(struct lh430wv4_panel_data *td)

{
	u8 cmd;
	int r;
	DBG();

	hw_guard_wait(td);

	cmd = DCS_SLEEP_IN;
	r = dsi_vc_dcs_write_nosync(1,TCH, &cmd, 1);
	if (r)
		return r;

	hw_guard_start(td, 120);

	msleep(5);

	return 0;
}

static int lh430wv4_panel_sleep_out(struct lh430wv4_panel_data *td)
{
	int r;
	DBG();

	hw_guard_wait(td);	

	r = lh430wv4_panel_dcs_write_0(DCS_SLEEP_OUT);
	if (r)
		return r;

	hw_guard_start(td, 120);	

	msleep(5);

	return 0;
}

static int lh430wv4_panel_get_id(u8 *buf)
{
	int r;
	DBG();

	r = dsi_vc_dcs_read(1,TCH, DCS_GET_ID, buf, 3);
	if (r)
		return r;

	return 0;
}

static int lh430wv4_panel_set_addr_mode(u8 rotate, bool mirror)
{
	int r;
	u8 mode;
	int b5, b6, b7;
	DBG();

	r = lh430wv4_panel_dcs_read_1(DCS_READ_MADCTL, &mode);
	if (r)
		return r;

	switch (rotate) {
	default:
	case 0:
		b7 = 0;
		b6 = 0;
		b5 = 0;
		break;
	case 1:
		b7 = 0;
		b6 = 1;
		b5 = 1;
		break;
	case 2:
		b7 = 1;
		b6 = 1;
		b5 = 0;
		break;
	case 3:
		b7 = 1;
		b6 = 0;
		b5 = 1;
		break;
	}

	if (mirror)
		b6 = !b6;

	mode &= ~((1<<7) | (1<<6) | (1<<5));
	mode |= (b7 << 7) | (b6 << 6) | (b5 << 5);

	return lh430wv4_panel_dcs_write_1(DCS_MEM_ACC_CTRL, mode);
}

static int lh430wv4_panel_bl_update_status(struct backlight_device *dev)
{
	struct omap_dss_device *dssdev = dev_get_drvdata(&dev->dev);
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	int r;
	int level;
	DBG();

	if (dev->props.fb_blank == FB_BLANK_UNBLANK &&
			dev->props.power == FB_BLANK_UNBLANK)
		level = dev->props.brightness;
	else
		level = 0;

	dev_dbg(&dssdev->dev, "update brightness to %d\n", level);

	if (td->use_dsi_bl) {
		if (td->enabled) {
			dsi_bus_lock(1);
			r = lh430wv4_panel_dcs_write_1(DCS_BRIGHTNESS, level);
			dsi_enable_cmd_video_mode(dssdev);
			dsi_bus_unlock(1);

//			dsi_enable_video_mode(dssdev);
			
			if (r)
				return r;
		}
	} else {
		if (!dssdev->set_backlight)
			return -EINVAL;

		r = dssdev->set_backlight(dssdev, level);
		if (r)
			return r;
	}

	return 0;
}

static int lh430wv4_panel_bl_get_intensity(struct backlight_device *dev)
{
	DBG();

	if (dev->props.fb_blank == FB_BLANK_UNBLANK &&
			dev->props.power == FB_BLANK_UNBLANK)
		return dev->props.brightness;

	return 0;
}

static struct backlight_ops lh430wv4_panel_bl_ops = {
	.get_brightness = lh430wv4_panel_bl_get_intensity,
	.update_status  = lh430wv4_panel_bl_update_status,
};

static void lh430wv4_panel_get_timings(struct omap_dss_device *dssdev,
			struct omap_video_timings *timings)
{
	DBG();

	*timings = dssdev->panel.timings;
}

static irqreturn_t lh430wv4_panel_te_isr(int irq, void *data)
{
	struct omap_dss_device *dssdev = data;
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);

	complete_all(&td->te_completion);

	return IRQ_HANDLED;
}

static ssize_t lh430wv4_panel_num_errors_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct omap_dss_device *dssdev = to_dss_device(dev);
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	u8 errors;
	int r;
	DBG();

	if (td->enabled) {
		dsi_bus_lock(1);
		r = lh430wv4_panel_dcs_read_1(DCS_READ_NUM_ERRORS, &errors);
		dsi_bus_unlock(1);
	} else {
		r = -ENODEV;
	}

	if (r)
		return r;

	return snprintf(buf, PAGE_SIZE, "%d\n", errors);
}

static ssize_t lh430wv4_panel_hw_revision_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	struct omap_dss_device *dssdev = to_dss_device(dev);
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	u8 dbuf[3];
	int r;
	DBG();

	if (td->enabled) {
		dsi_bus_lock(1);
		r = lh430wv4_panel_get_id(dbuf);
		dsi_bus_unlock(1);
	} else {
		r = -ENODEV;
	}

	if (r)
		return r;

	return snprintf(buf, PAGE_SIZE, "%02x.%02x.%02x\n", dbuf[0], dbuf[1], dbuf[2]);
}

static DEVICE_ATTR(num_dsi_errors, S_IRUGO, lh430wv4_panel_num_errors_show, NULL);
static DEVICE_ATTR(hw_revision, S_IRUGO, lh430wv4_panel_hw_revision_show, NULL);

void lh430wv4_panel_init_lcd(void)
{
	DBG();

	if(gpio_request(LH430WV4_PANEL_LCD_RESET_N, "lcd gpio") < 0) {
		return;
	}
	gpio_direction_output(LH430WV4_PANEL_LCD_RESET_N, 1);
    	gpio_set_value(LH430WV4_PANEL_LCD_RESET_N,0);
}

void lh430wv4_panel_reset_lcd(void)
{
	DBG();

	gpio_set_value(LH430WV4_PANEL_LCD_RESET_N, 0);
	mdelay(2);
	gpio_set_value(LH430WV4_PANEL_LCD_RESET_N, 1);
	mdelay(2);
}


static int lh430wv4_panel_enable(struct omap_dss_device *dssdev)
{
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	int i, r;
	enum omap_dsi_index ix;
	DBG();

	ix = (dssdev->channel == OMAP_DSS_CHANNEL_LCD) ? DSI1 : DSI2;

	
	//if(td->enabled) return 0;
	if (dssdev->platform_enable) {
		r = dssdev->platform_enable(dssdev);
		if (r)
			return r;
	}
	if(!(td->enabled))		
		lh430wv4_panel_reset_lcd();

	mutex_lock(&td->lock);
	dsi_bus_lock(ix);

	r = omapdss_dsi_display_enable(dssdev);
	if (r) {
		dev_err(&dssdev->dev, "failed to enable DSI\n");
		goto err;
	}

	/* it seems we have to wait a bit until lh430wv4_panel is ready */
	mdelay(5);	
#if 0
	extern int dsi_vc_generic_write_short(enum omap_dsi_index ix, int channel, u8 cmd, u8 *data, int len);

	for (i = 0; lcd_generic_write[i][0] != END_OF_COMMAND; i++) {
		dsi_vc_generic_write_short(1, TCH, lcd_generic_write[i][1], &lcd_generic_write[i][3], lcd_generic_write[i][2]);
	}
#endif
	for (i = 0; lgd_lcd_command_for_mipi[i][0] != END_OF_COMMAND; i++) {
		dsi_vc_dcs_write(1, TCH, &lgd_lcd_command_for_mipi[i][3], lgd_lcd_command_for_mipi[i][2]);
	//printk("kyungtae.oh~~~~~~~~~~ i = %d\n",i);
	mdelay(2);
	}

	r = lh430wv4_panel_sleep_out(td);
	if (r)
		goto err;

	lh430wv4_panel_dcs_write_0(DCS_DISPLAY_ON);	
#if defined(CONFIG_COSMO_S_CURVE) && defined(CONFIG_COSMO_GAMMA)						 
	dispc_enable_gamma(OMAP_DSS_CHANNEL_LCD, 0);
	dispc_enable_gamma(OMAP_DSS_CHANNEL_LCD2, 0);
#endif 

	dsi_enable_video_mode(dssdev); 
	mdelay(30); //after 1 frame

#ifdef HUB_PANEL_USE_ESD_CHECK
	queue_delayed_work(td->esd_wq, &td->esd_work, LH430WV4_PANEL_ESD_CHECK_PERIOD);
#endif

	td->enabled = 1;

	dsi_bus_unlock(ix);

	mutex_unlock(&td->lock);	

	dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;

	printk("panel-lh430wv4-sd02 enable!\n");

	return 0;
err:
	if (dssdev->platform_disable)
		dssdev->platform_disable(dssdev);

	return r;
}

static struct attribute *lh430wv4_panel_attrs[] = {
	&dev_attr_num_dsi_errors.attr,
	&dev_attr_hw_revision.attr,
	NULL,
};

static struct attribute_group lh430wv4_panel_attr_group = {
	.attrs = lh430wv4_panel_attrs,
};

static int lh430wv4_panel_probe(struct omap_dss_device *dssdev)
{
	struct lh430wv4_panel_data *td;
	struct backlight_device *bldev;
	struct omap_dss_device *dss_info;
	int r;

	DBG();

	td = kzalloc(sizeof(*td), GFP_KERNEL);
	if (!td) {
		r = -ENOMEM;
		goto err0;
	}
	td->dssdev = dssdev;

	mutex_init(&td->lock);
 
	td->esd_wq = create_singlethread_workqueue("lh430wv4_panel_esd");
	if (td->esd_wq == NULL) {
		dev_err(&dssdev->dev, "can't create ESD workqueue\n");
		r = -ENOMEM;
		goto err2;
	}
	INIT_DELAYED_WORK_DEFERRABLE(&td->esd_work, lh430wv4_panel_esd_work);

	dev_set_drvdata(&dssdev->dev, td);

	omapdssdev = dssdev;

	/* if no platform set_backlight() defined, presume DSI backlight
	 * control */
	if (!dssdev->set_backlight)
		td->use_dsi_bl = true;


	bldev = backlight_device_register("lh430wv4_panel", &dssdev->dev, dssdev,
			&lh430wv4_panel_bl_ops, NULL);
	if (IS_ERR(bldev)) {
		r = PTR_ERR(bldev);
		goto err1;
	}

	td->bldev = bldev;

	bldev->props.fb_blank = FB_BLANK_UNBLANK;
	bldev->props.power = FB_BLANK_UNBLANK;
	if (td->use_dsi_bl) {
		bldev->props.max_brightness = 255;
		bldev->props.brightness = 255;
	} else {
		bldev->props.max_brightness = 127;
		bldev->props.brightness = 127;
	}

	lh430wv4_panel_bl_update_status(bldev);

	dss_info = container_of(dssdev, struct omap_dss_device, dev);

	if (dss_info->phy.dsi.ext_te) {
		int gpio = dss_info->phy.dsi.ext_te_gpio;
		

		r = gpio_request(gpio, "lh430wv4_panel irq");
	
		printk("GPIO_lh430wv4_panel_irq=%x",gpio);

		if (r) {
			dev_err(&dssdev->dev, "GPIO request failed\n");
			goto err3;
		}

		gpio_direction_input(gpio);

		init_completion(&td->te_completion);

		td->use_ext_te = true;

		r = request_irq(gpio_to_irq(gpio), lh430wv4_panel_te_isr,
				//IRQF_DISABLED | IRQF_TRIGGER_RISING,
				IRQF_TRIGGER_RISING,
				"lh430wv4_panel vsync", dssdev);

		if (r) {
			dev_err(&dssdev->dev, "IRQ request failed\n");
			gpio_free(gpio);
			goto err3;
		}
	}

	r = sysfs_create_group(&dssdev->dev.kobj, &lh430wv4_panel_attr_group);
	if (r) {
		dev_err(&dssdev->dev, "failed to create sysfs files\n");
		goto err4;
	}

	td->enabled = 1;
	dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
	return 0;
err4:
	if (td->use_ext_te) {
		int gpio = dss_info->phy.dsi.ext_te_gpio;
		free_irq(gpio_to_irq(gpio), dssdev);
		gpio_free(gpio);
	}
err3:
	backlight_device_unregister(bldev);
err2:
	cancel_delayed_work_sync(&td->esd_work);
	destroy_workqueue(td->esd_wq);
err1:
	kfree(td);
err0:
	return r;
}

static void lh430wv4_panel_remove(struct omap_dss_device *dssdev)
{
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	struct backlight_device *bldev;
	struct omap_dss_device *dss_info;

	dev_dbg(&dssdev->dev, "remove\n");

	sysfs_remove_group(&dssdev->dev.kobj, &lh430wv4_panel_attr_group);

	dss_info = container_of(dssdev, struct omap_dss_device, dev);

	if (td->use_ext_te) {
		int gpio = dss_info->phy.dsi.ext_te_gpio;
		free_irq(gpio_to_irq(gpio), dssdev);
		gpio_free(gpio);
	}

	bldev = td->bldev;
	bldev->props.power = FB_BLANK_POWERDOWN;
	lh430wv4_panel_bl_update_status(bldev);
	backlight_device_unregister(bldev);

	cancel_delayed_work_sync(&td->esd_work);
	destroy_workqueue(td->esd_wq);

	kfree(td);
}

static void lh430wv4_panel_disable(struct omap_dss_device *dssdev)
{
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);

	DBG();


	cancel_delayed_work(&td->esd_work);

	if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE) {
		/* if not active, below DSI commands trigger unhandled fault */
		lh430wv4_panel_dcs_write_0(DCS_DISPLAY_OFF);
		lh430wv4_panel_sleep_in(td);
	}

	/* wait a bit so that the message goes through */
	msleep(10);

	if (dssdev->platform_disable)
		dssdev->platform_disable(dssdev);
	
	td->enabled = 0;
}

static int lh430wv4_panel_suspend(struct omap_dss_device *dssdev)
{
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	struct backlight_device *bldev = td->bldev;
	DBG();	
	bldev->props.power = FB_BLANK_POWERDOWN;
	lh430wv4_panel_bl_update_status(bldev);
	dsi_bus_lock(DSI2);
   	lh430wv4_panel_dcs_write_0(DCS_DISPLAY_OFF);
   	lh430wv4_panel_dcs_write_0(DCS_SLEEP_IN);
	lh430wv4_panel_dcs_write_1(DCS_DEEP_STANDBY_IN, 0x01);
	msleep(20);
	
	gpio_set_value(LH430WV4_PANEL_LCD_RESET_N, 0);
	msleep(1);

	gpio_set_value(LH430WV4_PANEL_LCD_EN, 0);
	msleep(1);
		

	omapdss_dsi_display_disable(dssdev);
	if (dssdev->platform_disable)
		dssdev->platform_disable(dssdev);
	dsi_bus_unlock(DSI2);
	dssdev->state = OMAP_DSS_DISPLAY_SUSPENDED;
	return 0;
}

static int lh430wv4_panel_resume(struct omap_dss_device *dssdev)
{
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	//struct backlight_device *bldev = td->bldev;
	DBG();

	gpio_set_value(LH430WV4_PANEL_LCD_EN, 1);
	msleep(5);
	
	td->enabled=0;
	lh430wv4_panel_enable(dssdev);

	return 0;
}

static int lh430wv4_panel_enable_te(struct omap_dss_device *dssdev, bool enable)
{
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	int r;
	DBG();

	td->te_enabled = enable;

	if (enable)
		r = lh430wv4_panel_dcs_write_1(DCS_TEAR_ON, 0);
	else
		r = lh430wv4_panel_dcs_write_0(DCS_TEAR_OFF);
	return r;
}

static int lh430wv4_panel_rotate(struct omap_dss_device *dssdev, u8 rotate)
{
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	int r;
	DBG();

	dev_dbg(&dssdev->dev, "rotate %d\n", rotate);

	if (td->enabled) {
		r = lh430wv4_panel_set_addr_mode(rotate, td->mirror);

		if (r)
			return r;
	}

	td->rotate = rotate;

	return 0;
}

static u8 lh430wv4_panel_get_rotate(struct omap_dss_device *dssdev)
{
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	DBG();

	return td->rotate;
}

static int lh430wv4_panel_mirror(struct omap_dss_device *dssdev, bool enable)
{
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	int r;
	DBG();

	dev_dbg(&dssdev->dev, "mirror %d\n", enable);

	if (td->enabled) {
		r = lh430wv4_panel_set_addr_mode(td->rotate, enable);

		if (r)
			return r;
	}

	td->mirror = enable;

	return 0;
}

static bool lh430wv4_panel_get_mirror(struct omap_dss_device *dssdev)
{
	struct lh430wv4_panel_data *td = dev_get_drvdata(&dssdev->dev);
	DBG();

	return td->mirror;
}

static int lh430wv4_panel_run_test(struct omap_dss_device *dssdev, int test_num)
{
	u8 buf[3];
	int r;

	r = dsi_vc_dcs_read(1,TCH, DCS_GET_ID, buf, 3);
	if (r)
		return r;

	return 0;
}


static void lh430wv4_panel_esd_work(struct work_struct *work)
{
	struct lh430wv4_panel_data *td = container_of(work, struct lh430wv4_panel_data,
			esd_work.work);
	struct omap_dss_device *dssdev = td->dssdev;
	u8 state1, state2;
	int r;
	DBG();

	if (!td->enabled)
		return;

	dsi_bus_lock(1);

	r = lh430wv4_panel_dcs_read_1(DCS_RDDSDR, &state1);
	if (r) {
		dev_err(&dssdev->dev, "failed to read Taal status\n");
		goto err;
	}

	/* Run self diagnostics */
	r = lh430wv4_panel_sleep_out(td);
	if (r) {
		dev_err(&dssdev->dev, "failed to run Taal self-diagnostics\n");
		goto err;
	}

	r = lh430wv4_panel_dcs_read_1(DCS_RDDSDR, &state2);
	if (r) {
		dev_err(&dssdev->dev, "failed to read Taal status\n");
		goto err;
	}

	/* Each sleep out command will trigger a self diagnostic and flip
	 * Bit6 if the test passes.
	 */
	if (!((state1 ^ state2) & (1 << 6))) {
		dev_err(&dssdev->dev, "LCD self diagnostics failed\n");
		goto err;
	}
	/* Self-diagnostics result is also shown on TE GPIO line. We need
	 * to re-enable TE after self diagnostics */
	if (td->use_ext_te && td->te_enabled)
		lh430wv4_panel_enable_te(dssdev, true);

	dsi_bus_unlock(1);

	queue_delayed_work(td->esd_wq, &td->esd_work, LH430WV4_PANEL_ESD_CHECK_PERIOD);

	return;
err:
	dev_err(&dssdev->dev, "performing LCD reset\n");

	lh430wv4_panel_disable(dssdev);
	lh430wv4_panel_enable(dssdev);

	dsi_bus_unlock(1);

	queue_delayed_work(td->esd_wq, &td->esd_work, LH430WV4_PANEL_ESD_CHECK_PERIOD);
}

static void lh430wv4_panel_get_dimension(struct omap_dss_device *dssdev,
		u32 *width, u32 *height)
{
	DBG();

	*width	= dssdev->panel.width_in_mm;
	*height	= dssdev->panel.height_in_mm;
}

static struct omap_dss_driver lh430wv4_panel_driver = {
	.probe		= lh430wv4_panel_probe,
	.remove		= lh430wv4_panel_remove,

	.enable		= lh430wv4_panel_enable,
	.disable	= lh430wv4_panel_disable,
	.suspend	= lh430wv4_panel_suspend,
	.resume		= lh430wv4_panel_resume,

	.enable_te	= lh430wv4_panel_enable_te,
	.set_rotate	= lh430wv4_panel_rotate,
	.get_rotate	= lh430wv4_panel_get_rotate,
	.set_mirror	= lh430wv4_panel_mirror,
	.get_mirror	= lh430wv4_panel_get_mirror,
	.run_test	= lh430wv4_panel_run_test,
	.get_timings	= lh430wv4_panel_get_timings,
	.get_dimension	= lh430wv4_panel_get_dimension,

	.driver         = {
		.name 	= "lh430wv4_panel",
		.owner  = THIS_MODULE,
	},
};

static int __init lh430wv4_panel_init(void)
{
	DBG();
	printk("Trying to register driver\n");
	omap_dss_register_driver(&lh430wv4_panel_driver);
	printk("Registering driver done\n");

	return 0;
}

static void __exit lh430wv4_panel_exit(void)
{
	omap_dss_unregister_driver(&lh430wv4_panel_driver);
}

module_init(lh430wv4_panel_init);
module_exit(lh430wv4_panel_exit);

MODULE_AUTHOR("taekeun Kim <taekeun1.kim@lge.com>");
MODULE_DESCRIPTION("LH430WV4_PANEL lcd Driver");
MODULE_LICENSE("GPL");


