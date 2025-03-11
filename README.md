# simple_sensor_cache

A Linux kernel module that implements a custom GPIO driver for the AM2303 sensor with caching. It offers:

- **One-wire communication** with the AM2303 sensor.
- **Sysfs interfaces** to read temperature and humidity values.
- A **built-in caching mechanism** to ensure sensor data is polled at most once every 2 seconds.

## Building

1. Ensure you have the kernel headers and build tools installed:
   ```bash
   sudo apt-get install build-essential linux-headers-$(uname -r)
   ```
2. Build the module by running:
   ```bash
   make
   ```

## Usage

- **Load the module:**
  ```bash
  sudo insmod am2303_driver.ko
  ```
- **Access sensor data via sysfs:**
  ```bash
  cat /sys/devices/platform/simple_sensor_cache_device/temp
  cat /sys/devices/platform/simple_sensor_cache_device/humid
  ```
- **Unload the module:**
  ```bash
  sudo rmmod am2303_driver
  ```

## Device Tree Overlay (for Raspberry Pi 5)

Add the following snippet to `arch/arm64/boot/dts/broadcom/bcm2712-rpi-5-b.dts` after the `leds: leds` section:

```dts
    simple_sensor_cache_device {
        compatible = "raspberrypi,simple_sensor_cache_device";
        data-gpios = <&rp1_gpio 15 0>;
        status = "okay";
    };
```

After modifying the DTS file, recompile and update your boot partition. On boot, verify that the custom GPIO device is recognized by checking:

```bash
find /proc/device-tree/ | grep simple
```

## License

Dual MIT/GPL
