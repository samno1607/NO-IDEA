#ifndef _HEAVEN_LCD_H
#define _HEAVEN_LCD_H

#define	MAIN_LCD	0

#define LCD_LDO_EN			56
#define LCD_ID		35
#define LCD_RESET_N		34
#define RGB_CVT_EN	126
#define LCD_CVT_RESET_N	181

struct heaven_lcd_platform_data {
/* TODO: add field..*/
	struct spi_device	*spi_dev;
	struct i2c_client	*i2c_client;
	int lcd_type;
	struct res_handle *vpll_rhandle;
};

#endif
