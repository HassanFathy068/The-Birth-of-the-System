#include <Wire.h>

#define BUTTON1_PIN 2
#define BUTTON2_PIN 3

void setup() {
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT);
  Wire.begin();
}

void loop() {
  int button1State = digitalRead(BUTTON1_PIN);
  int button2State = digitalRead(BUTTON2_PIN);

  Wire.beginTransmission(9);  // Address of the receiving Arduino
  Wire.write(button1State);
  Wire.write(button2State);
  Wire.endTransmission();

  delay(100);
}