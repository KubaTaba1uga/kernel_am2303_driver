#ifndef AM2303_COMMON
#define AM2303_COMMON
#include <linux/kobject.h>
#include <linux/platform_device.h>
#include <linux/types.h>

struct am2303_data {
	struct timespec64 last_receive;
	struct platform_device *pdev;
	struct gpio_desc *gpio;
	u16 temprature;
	u16 humidity;
	u8 checksum;
};

#define LKM_PRINT_ERR(pdev, fmt, ...)                                          \
  dev_err(&pdev->dev, "[%s:%d] " fmt, __FILE__, __LINE__, ##__VA_ARGS__)

#endif
