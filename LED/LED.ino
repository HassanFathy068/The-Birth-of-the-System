#include <Wire.h>

#define LED_PIN 9

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Wire.begin(9);  // Address of this Arduino
  Wire.onReceive(receiveEvent);
}

void loop() {
  // Do other tasks if needed
}

void receiveEvent(int Bytes) {
    int button1State = Wire.read();
    int button2State = Wire.read();

    int ledIntensity = 0;
    String message;

    if (button1State == 0 && button2State == 0) {
      ledIntensity = 0;
      message = "No message";
    } else if (button1State == 1 && button2State == 0) {
      ledIntensity = 128;
      message = "Vector focused";
    } else if (button1State == 0 && button2State == 1) {
      ledIntensity = 192;
      message = "Vector distracted";
    } else if (button1State == 1 && button2State == 1) {
      ledIntensity = 255;
      message = "Glitch";
    }
    analogWrite(LED_PIN, ledIntensity);
    Serial.println(message);
  }