#Android makefile to build kernel as a part of Android Build

ifeq ($(TARGET_PREBUILT_KERNEL),)

IMAGE_OUT := kernel/arch/arm/boot
KERNEL_OUT := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ
KERNEL_CONFIG := $(KERNEL_OUT)/.config
TARGET_PREBUILT_KERNEL := kernel/arch/arm/boot/zImage
# 20110408 david.moon@lge.com, Wi-Fi BCM4330[START]
#KERNEL_MODULES_OUT := $(TARGET_OUT)/etc/wifi
#KERNEL_MODULES_OUT := $(TARGET_OUT)/lib/modules
# 20110408 david.moon@lge.com, Wi-Fi BCM4330[END]
TARGET_PREBUILT_INT_KERNEL := $(KERNEL_OUT)/arch/arm/boot/zImage
#WIFI_KERNEL_MODULE_NAME := wireless.ko
#WIFI_KERNEL_MODULE := $(KERNEL_OUT)/drivers/net/wireless/bcm4329/$(WIFI_KERNEL_MODULE_NAME)
# 20110408 david.moon@lge.com, Wi-Fi BCM4330[END]
# LGE_CHANGE_S, real-wifi@lge.com by wo0ngs 2011-08-20, for Wi-Fi TI WL1271
ifeq ($(BOARD_WLAN_DEVICE), wl1271)
WIFI_KERNEL_MODULE_NAME := tiwlan_drv.ko
SOFTAP_KERNEL_MODULE_NAME := tiap_drv.ko
WIFI_KERNEL_MODULE := $(ANDROID_BUILD_TOP)/hardware/ti/wlan/wl1271/platforms/os/linux/$(WIFI_KERNEL_MODULE_NAME)
WIFI_MODULE_FW :=  $(ANDROID_BUILD_TOP)/hardware/ti/wlan/wl1271/config/firmware.bin
WIFI_KERNEL_MODULE_OUT := $(ANDROID_BUILD_TOP)/out/target/product/$(TARGET_PRODUCT)/system/etc/wifi
SOFTAP_KERNEL_MODULE := $(ANDROID_BUILD_TOP)/hardware/ti/wlan/wl1271_softAP/platforms/os/linux/$(SOFTAP_KERNEL_MODULE_NAME)
SOFTAP_MODULE_FW := $(ANDROID_BUILD_TOP)/hardware/ti/wlan/wl1271_softAP/config/firmware_ap.bin
SOFTAP_KERNEL_MODULE_OUT := $(ANDROID_BUILD_TOP)/out/target/product/$(TARGET_PRODUCT)/system/etc/wifi/softap
endif
# LGE_CHANGE_E, real-wifi@lge.com by wo0ngs 2011-08-20, for Wi-Fi TI WL1271
TARGET_PREBUILT_INT_KERNEL := $(KERNEL_OUT)/arch/arm/boot/zImage

ifeq ($(TARGET_USES_UNCOMPRESSED_KERNEL),true)
$(info Using uncompressed kernel)
TARGET_PREBUILT_KERNEL := $(KERNEL_OUT)/piggy
else
TARGET_PREBUILT_KERNEL := $(TARGET_PREBUILT_INT_KERNEL)
endif

KERNEL_DEFCONFIG_SRC_FILE := kernel/arch/arm/configs/$(KERNEL_DEFCONFIG)

$(KERNEL_OUT):
	mkdir -p $(KERNEL_OUT)

$(KERNEL_MODULES_OUT):
	mkdir -p $(KERNEL_MODULES_OUT)
	mkdir -p $(TARGET_OUT_EXECUTABLES)

$(KERNEL_CONFIG): $(KERNEL_DEFCONFIG_SRC_FILE) | $(KERNEL_OUT)
	$(MAKE) -C kernel O=../$(KERNEL_OUT) ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- $(KERNEL_DEFCONFIG)

$(KERNEL_OUT)/piggy : $(TARGET_PREBUILT_INT_KERNEL)
	$(hide) gunzip -c $(KERNEL_OUT)/arch/arm/boot/compressed/piggy > $(KERNEL_OUT)/piggy

.PHONY: $(TARGET_PREBUILT_INT_KERNEL)
$(TARGET_PREBUILT_INT_KERNEL): $(KERNEL_CONFIG)
	+$(MAKE) -C kernel O=../$(KERNEL_OUT) ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- zImage
	+$(MAKE) -C kernel O=../$(KERNEL_OUT) ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- modules
	+cp $(KERNEL_OUT)/arch/arm/boot/zImage kernel/arch/arm/boot/ 
# LGE_CHANGE_S, real-wifi@lge.com by wo0ngs 2011-08-20, for Wi-Fi TI WL1271
# WILINK_TIK Alex
ifeq ($(BOARD_WLAN_DEVICE), wl1271)
	cd $(shell pwd)/hardware/ti/wlan/wl1271/platforms/os/linux && source 4430_env.bash && make clean && make
	mkdir -p $(WIFI_KERNEL_MODULE_OUT)
	-cp  -f $(WIFI_KERNEL_MODULE) $(WIFI_KERNEL_MODULE_OUT)
	-cp  -f $(WIFI_MODULE_FW) $(WIFI_KERNEL_MODULE_OUT)
	cd $(shell pwd)/hardware/ti/wlan/wl1271_softAP/platforms/os/linux && source 4430_env.bash && make clean && make
	mkdir -p $(SOFTAP_KERNEL_MODULE_OUT)
	-cp  -f $(SOFTAP_KERNEL_MODULE) $(SOFTAP_KERNEL_MODULE_OUT)
	-cp  -f $(SOFTAP_MODULE_FW) $(SOFTAP_KERNEL_MODULE_OUT)
endif
# LGE_CHANGE_E, real-wifi@lge.com by wo0ngs 2011-08-20, for Wi-Fi TI WL1271
# 20110408 david.moon@lge.com, Wi-Fi BCM4330[START]
#	mkdir -p $(TARGET_OUT)/lib
#	mkdir -p $(KERNEL_MODULES_OUT)
#ifeq ($(TARGET_PRODUCT), lge_p940)
#	-cp  -f $(KERNEL_OUT)/drivers/net/wireless/bcm4330/wireless.ko $(KERNEL_MODULES_OUT)
#else ifeq ($(TARGET_PRODUCT), lge_gelato_nfc)
#	-cp  -f $(KERNEL_OUT)/drivers/net/wireless/bcm4330/wireless.ko $(KERNEL_MODULES_OUT)
#endif
# 20110408 david.moon@lge.com, Wi-Fi BCM4330[END]



# 20110825 teddy.ju TI BT [START]

	if [ ! -d $(PRODUCT_OUT)/data/btips/TI/scripts        ]; then mkdir -p $(PRODUCT_OUT)/data/btips/TI/scripts;        fi;
#	if [ ! -d $(PRODUCT_OUT)/data/btips/TI/BTInitScript   ]; then mkdir -p $(PRODUCT_OUT)/data/btips/TI/BTInitScript;   fi;
	if [ ! -d $(PRODUCT_OUT)/system/btips/TI/BTInitScript   ]; then mkdir -p $(PRODUCT_OUT)/system/btips/TI/BTInitScript;   fi;
	if [ ! -d $(PRODUCT_OUT)/data/btips/TI/opp            ]; then mkdir -p $(PRODUCT_OUT)/data/btips/TI/opp;            fi;
	if [ ! -d $(PRODUCT_OUT)/data/btips/TI/ftproot        ]; then mkdir -p $(PRODUCT_OUT)/data/btips/TI/ftproot;        fi;
	if [ ! -d $(PRODUCT_OUT)/data/btips/TI/ftproot_c      ]; then mkdir -p $(PRODUCT_OUT)/data/btips/TI/ftproot_c;      fi;
	if [ ! -d $(PRODUCT_OUT)/data/btips/TI/images/bip/xml ]; then mkdir -p $(PRODUCT_OUT)/data/btips/TI/images/bip/xml; fi;
	if [ ! -d $(PRODUCT_OUT)/data/btips/TI/bip            ]; then mkdir -p $(PRODUCT_OUT)/data/btips/TI/bip;            fi;
	if [ ! -d $(PRODUCT_OUT)/data/btips/TI/bpp            ]; then mkdir -p $(PRODUCT_OUT)/data/btips/TI/bpp;            fi;
	if [ ! -d $(PRODUCT_OUT)/system/etc/firmware          ]; then mkdir -p $(PRODUCT_OUT)/system/etc/firmware;          fi;
	-cp -f $(ANDROID_HOME)/external/mcp/MCP_Common/Platform/init_script/android_zoom/*                 $(ANDROID_HOME)/$(PRODUCT_OUT)/system/btips/TI/BTInitScript/
	-cp -f $(ANDROID_HOME)/external/mcp/MCP_Common/Platform/init_script/android_zoom/tiinit_7.2.31.bts $(ANDROID_HOME)/$(PRODUCT_OUT)/system/etc/firmware/TIInit_7.2.31.bts
	-cp -f $(PRODUCT_OUT)/obj/KERNEL_OBJ/drivers/misc/ti-hci/hci_if_drv.ko $(PRODUCT_OUT)/system/etc/firmware
	-cp -f $(PRODUCT_OUT)/obj/KERNEL_OBJ/drivers/misc/ti-st/st_drv.ko $(PRODUCT_OUT)/system/etc/firmware
#	-cp -f $(PRODUCT_OUT)/obj/KERNEL_OBJ/drivers/staging/ti-st/fm_drv.ko $(PRODUCT_OUT)/system/etc/firmware
# 20110825 teddy.ju TI BT 	[END]



#.PHONY: $(WIFI_KERNEL_MODULE)
#$(WIFI_KERNEL_MODULE): $(TARGET_PREBUILT_INT_KERNEL) | $(KERNEL_MODULES_OUT)
#	+$(MAKE) -C kernel O=../$(KERNEL_OUT) ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- modules


PRODUCT_COPY_FILES_TO := $(subst $(PRODUCT_OUT),,$(KERNEL_MODULES_OUT))
#PRODUCT_COPY_FILES += \
#	$(WIFI_KERNEL_MODULE):$(PRODUCT_COPY_FILES_TO)/$(WIFI_KERNEL_MODULE_NAME)\
#	kernel/drivers/net/wireless/bcm4329/firmware/fw_bcm4329.bin:$(PRODUCT_COPY_FILES_TO)/fw_bcm4329.bin\
#	kernel/drivers/net/wireless/bcm4329/firmware/fw_bcm4329_mfg.bin:$(PRODUCT_COPY_FILES_TO)/fw_bcm4329_mfg.bin\
#	kernel/drivers/net/wireless/bcm4329/firmware/fw_bcm4329_ap.bin:$(PRODUCT_COPY_FILES_TO)/fw_bcm4329_ap.bin\
#	kernel/drivers/net/wireless/bcm4329/firmware/nvram.txt:$(PRODUCT_COPY_FILES_TO)/nvram.txt\
#	kernel/drivers/net/wireless/bcm4329/wpa_supplicant.conf:$(PRODUCT_COPY_FILES_TO)/wpa_supplicant.conf

PRODUCT_COPY_FILES_TO := $(subst $(PRODUCT_OUT),,$(TARGET_OUT_EXECUTABLES))
#PRODUCT_COPY_FILES += \
#	kernel/drivers/net/wireless/bcm4329/wl:$(PRODUCT_COPY_FILES_TO)/wl


kerneltags: $(KERNEL_OUT) $(KERNEL_CONFIG)
	$(MAKE) -C kernel ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- tags

kernelconfig: $(KERNEL_OUT) $(KERNEL_CONFIG)
	env KCONFIG_NOTIMESTAMP=true \
	     $(MAKE) -C kernel ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- menuconfig
	cp $(KERNEL_OUT)/.config kernel/arch/arm/configs/$(KERNEL_DEFCONFIG)


INSTALLED_KERNEL_TARGET ?= $(PRODUCT_OUT)/kernel
INSTALLED_BOOTIMAGE_TARGET ?= $(PRODUCT_OUT)/boot.img
INSTALLED_RECOVERYIMAGE_TARGET ?= $(PRODUCT_OUT)/recovery.img

KERNEL_CLEAN_TARGET_LIST := $(TARGET_PREBUILT_INT_KERNEL) $(TARGET_PREBUILT_KERNEL) $(INSTALLED_KERNEL_TARGET) \
                            $(INSTALLED_BOOTIMAGE_TARGET) $(INSTALLED_RECOVERYIMAGE_TARGET)

.PHONY: ckernel
ckernel:
	-@$(MAKE) -C kernel O=../$(KERNEL_OUT) ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- distclean
	-@rm -vf $(KERNEL_CLEAN_TARGET_LIST)

.PHONY: kernel
kernel: $(INSTALLED_BOOTIMAGE_TARGET) $(INSTALLED_RECOVERYIMAGE_TARGET)
$(INSTALLED_BOOTIMAGE_TARGET): $(INSTALLED_KERNEL_TARGET)
$(INSTALLED_RECOVERYIMAGE_TARGET): $(INSTALLED_KERNEL_TARGET)
$(INSTALLED_KERNEL_TARGET): $(TARGET_PREBUILT_INT_KERNEL)

endif
