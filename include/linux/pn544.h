#define PN544_MAGIC	0xE9

/*
 * PN544 power control via ioctl
 * PN544_SET_PWR(0): power off
 * PN544_SET_PWR(1): power on
 * PN544_SET_PWR(2): reset and power on with firmware download enabled
 */
#define PN544_SET_PWR	_IOW(PN544_MAGIC, 0x01, unsigned int)

#if 0	
/* NFC macros */
#define NFC_GPIO_IRQ			  21
#define NFC_GPIO_VEN			  13
#define NFC_GPIO_FRIM			  48
#define NFC_I2C_SLAVE_ADDR		0x28 // for B2
//#define NFC_I2C_SLAVE_ADDR		0x28 // For HDK
#else
#define NFC_GPIO_IRQ			  4
#define NFC_GPIO_VEN			  61
#define NFC_GPIO_FRIM			  49
#define NFC_I2C_SLAVE_ADDR		0x2B // for B2
//#define NFC_I2C_SLAVE_ADDR		0x28 // For HDK
#endif
struct pn544_i2c_platform_data {
	unsigned int irq_gpio;
	unsigned int ven_gpio;
	unsigned int firm_gpio;
};
