// Motor control pin definitions
const int enA = 2;    // Motor A speed pin (PWM control)
const int enB = 3;    // Motor B speed pin (PWM control)
const int in1 = 4;    // Motor A direction - forward
const int in2 = 22;   // Motor A direction - backward
const int in3 = 24;   // Motor B direction - forward
const int in4 = 5;    // Motor B direction - backward

// Sensor pin definitions
const int pin_S1 = A0;   // Left sensor
const int pin_S2 = A1;   // Right sensor

// Sensor calibration constants
int sensorWhiteMin = 0;
int sensorWhiteMax = 1023;
int sensorBlackMin = 0;
int sensorBlackMax = 1023;

// Initial motor speeds (left and right)
int speedA = 200; // Motor A speed
int speedB = 200; // Motor B speed

void setup() {
  // Set motor pins as output
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set sensor pins as input  
  pinMode(pin_S1, INPUT);
  pinMode(pin_S2, INPUT);

  // Sensor calibration
  calibrateSensors();
}

void loop() {
  // Read sensors
  int leftSensor = analogRead(pin_S1);
  int rightSensor = analogRead(pin_S2);

  // Check if sensors are over the black line
  if (leftSensor >= sensorBlackMin && leftSensor <= sensorBlackMax &&
      rightSensor >= sensorBlackMin && rightSensor <= sensorBlackMax) {
    // Black square detected: perform the action
    performBlackSquareAction();
  } else {
    // No black square detected: keep following the white line
    followWhiteLine(leftSensor, rightSensor);
  }
}

void followWhiteLine(int leftSensor, int rightSensor) {
  // Implement a PID controller to dynamically adjust motor speed
  // based on sensor readings, for smoother and more precise line following.

  // Simplified example: keep fixed forward speeds
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void performBlackSquareAction() {
  // Implement a movement sequence when the black square is detected,
  // such as a short reverse followed by a 180° turn.

  // Short reverse
  analogWrite(enA, 100);
  analogWrite(enB, 100);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(1000); // Reverse duration (adjust as needed)

  // 180° turn
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(1000); // Turn duration (adjust as needed)
}

void calibrateSensors() {
  // Sensor calibration to determine reference values
  // when placed over the white line and the black square.
  // This function is called at the beginning of the program.

  // Wait a few seconds for initial stabilization
  delay(5000);

  // Readings of sensors over the white line
  int whiteLeftAvg = 0;
  int whiteRightAvg = 0;
  for (int i = 0; i < 10; i++) {
    whiteLeftAvg += analogRead(pin_S1);
    whiteRightAvg += analogRead(pin_S2);
    delay(100);
  }
  sensorWhiteMin = whiteLeftAvg / 10;
  sensorWhiteMax = whiteRightAvg / 10;

  // Readings of sensors over the black square
  int blackLeftAvg = 0;
  int blackRightAvg = 0;
  for (int i = 0; i < 10; i++) {
    blackLeftAvg += analogRead(pin_S1);
    blackRightAvg += analogRead(pin_S2);
    delay(100);
  }
  sensorBlackMin = blackLeftAvg / 10;
  sensorBlackMax = blackRightAvg / 10;
}
