const int TRIGGER_PIN_1 = 2;
const int ECHO_PIN_1 = 3;
const int TRIGGER_PIN_2 = 4;
const int ECHO_PIN_2 = 5;
const int TRIGGER_PIN_3 = 6;
const int ECHO_PIN_3 = 7;
const int TRIGGER_PIN_4 = 8;
const int ECHO_PIN_4 = 9;

const int MAX_DISTANCE = 800; // Maximum distance in centimeters (8 meters)

float chamberWidth = 5.0;   // meters
float chamberLength = 6.0;  // meters

float x = 0.0;  // X-coordinate of the cookie bot position
float y = 0.0;  // Y-coordinate of the cookie bot position

void setup() {
  pinMode(TRIGGER_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(TRIGGER_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
  pinMode(TRIGGER_PIN_3, OUTPUT);
  pinMode(ECHO_PIN_3, INPUT);
  pinMode(TRIGGER_PIN_4, OUTPUT);
  pinMode(ECHO_PIN_4, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Read distance measurements from ultrasonic sensors
  unsigned int distance1 = getDistance(TRIGGER_PIN_1, ECHO_PIN_1);
  unsigned int distance2 = getDistance(TRIGGER_PIN_2, ECHO_PIN_2);
  unsigned int distance3 = getDistance(TRIGGER_PIN_3, ECHO_PIN_3);
  unsigned int distance4 = getDistance(TRIGGER_PIN_4, ECHO_PIN_4);

  // Calculate position based on sensor measurements
  x = (distance2 - distance4) / 2.0;
  y = chamberLength - (distance1 - distance3) / 2.0;

  // Print the position
  Serial.print("Cookie Bot Position (x, y): ");
  Serial.print(x);
  Serial.print(", ");
  Serial.println(y);

  delay(500);
}

unsigned int getDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  unsigned int distance = duration * 0.034 / 2;

  if (distance == 0 || distance > MAX_DISTANCE) {
    distance = MAX_DISTANCE;
  }

  return distance;
}