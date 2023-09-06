// Rotary Encoder Pins
const int encoderPinA = 2;
const int encoderPinB = 3;

// Variables
volatile int count = 0;
volatile bool aState;
volatile bool bState;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Set encoder pins as input
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);

  // Attach interrupt to the encoder pin A
  attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoderInterrupt, CHANGE);
}

void loop() {
  // Print the count value
  Serial.println(count);
  delay(100); // Adjust the delay as per your requirements
}

void handleEncoderInterrupt() {
  // Read the current states of the encoder pins
  aState = digitalRead(encoderPinA);
  bState = digitalRead(encoderPinB);

  // Update the count based on the direction of rotation
  if (aState == bState) {
    count++;
  } else {
    count--;
  }
}