#include <Wire.h>

const int MPU6050_ADDRESS = 0x68;  // MPU6050 I2C address
const int MPU6050_REG_PWR_MGMT_1 = 0x6B;    // Power Management 1 register
const int MPU6050_REG_CONFIG = 0x1A;        // Configuration register
const int MPU6050_REG_GYRO_CONFIG = 0x1B;   // Gyroscope Configuration register
const int MPU6050_REG_ACCEL_CONFIG = 0x1C;  // Accelerometer Configuration register
const int MPU6050_REG_GYRO_XOUT_H = 0x43;   // Gyroscope X-axis high byte register
const int MPU6050_REG_GYRO_XOUT_L = 0x44;   // Gyroscope X-axis low byte register

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // Wake up the MPU6050
  writeRegister(MPU6050_REG_PWR_MGMT_1, 0x00);
  
  // Configure the MPU6050
  writeRegister(MPU6050_REG_CONFIG, 0x03);  // DLPF = 44Hz
  writeRegister(MPU6050_REG_GYRO_CONFIG, 0x18);  // ±2000°/s
  writeRegister(MPU6050_REG_ACCEL_CONFIG, 0x18);  // ±16g
}

void loop() {
  // Read the yaw angle
  int16_t gyroX = readRegister16Bit(MPU6050_REG_GYRO_XOUT_H);
  
  // Convert the raw value to degrees per second
  float gyroXValue = gyroX / 16.4;
  
  // Calculate the yaw angle in degrees
  float yawAngle = gyroXValue * 0.02;  // Assuming a loop duration of 20ms
  
  Serial.print("Yaw Angle: ");
  Serial.print(yawAngle);
  Serial.println(" degrees");
  
  delay(200);  // Delay for easier reading
}

void writeRegister(byte regAddr, byte value) {
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(regAddr);
  Wire.write(value);
  Wire.endTransmission();
}

int16_t readRegister16Bit(byte regAddr) {
  Wire.beginTransmission(MPU6050_ADDRESS);
  Wire.write(regAddr);
  Wire.endTransmission(false);
  
  Wire.requestFrom(MPU6050_ADDRESS, 2, true);
  
  byte highByte = Wire.read();
  byte lowByte = Wire.read();
  
  return (highByte << 8) | lowByte;
}