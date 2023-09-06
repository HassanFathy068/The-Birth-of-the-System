# MPU6050 Yaw Angle Retrieval

This document describes an Arduino code snippet that interfaces with the MPU6050 sensor to retrieve the yaw angle along the z-axis.

### Code Explanation

The provided code performs the following steps:

1. It includes the necessary libraries and defines the MPU6050 sensor address and register constants.
2. In the `setup()` function, it initializes the serial communication, starts the I2C communication, and configures the MPU6050 sensor.
3. The `loop()` function continuously reads the yaw angle from the sensor and calculates the angle in degrees.
4. The raw gyroscope data is read from the MPU6050 sensor using the `readRegister16Bit()` function.
5. The raw value is converted to degrees per second, assuming a sensitivity of 16.4 LSB/(°/s).
6. The yaw angle is calculated by multiplying the gyroscope value by the loop duration (assumed to be 20ms).
7. The yaw angle is printed to the serial monitor for debugging and monitoring purposes.

### Filter for Noisy Environment

In a noisy environment, it is recommended to apply a low-pass filter to reduce noise interference. The MPU6050 sensor provides a built-in Digital Low Pass Filter (DLPF) feature that can be configured to attenuate high-frequency noise.

According to the MPU6050 datasheet, the recommended cutoff frequencies for the DLPF are as follows:

- DLPF = 0: 260 Hz
- DLPF = 1: 184 Hz
- DLPF = 2: 94 Hz
- DLPF = 3: 44 Hz
- DLPF = 4: 21 Hz
- DLPF = 5: 10 Hz
- DLPF = 6: 5 Hz

To select the appropriate cutoff frequency, consider the frequency range of the noise and the desired response time for your application. If the noise frequency is high, choose a higher cutoff frequency. If the motion you want to measure is slow, select a lower cutoff frequency.

In the provided code, the DLPF is configured by writing the corresponding value to the `MPU6050_REG_CONFIG` register during the setup phase. For example, to set the cutoff frequency to 44 Hz, the following line of code is used:

```
writeRegister(MPU6050_REG_CONFIG, 0x03);  // DLPF = 44Hz
```

---