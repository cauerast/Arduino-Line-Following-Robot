/*
 * Hardware:
 *   - Dual DC motors (Motor A & B)
 *   - 2 analog line sensors (Left & Right)
 *   - Motor driver (L298N / L293D)
 *   - Arduino Mega / Uno
 * ==========================================================
 */

const int ENA = 2;    // Motor A PWM control
const int ENB = 3;    // Motor B PWM control
const int IN1 = 4;    // Motor A direction 1
const int IN2 = 22;   // Motor A direction 2
const int IN3 = 24;   // Motor B direction 1
const int IN4 = 5;    // Motor B direction 2

const int SENSOR_LEFT = A0;  // Left line sensor
const int SENSOR_RIGHT = A1; // Right line sensor


float Kp = 25.0;   // Proportional gain
float Ki = 0.0;    // Integral gain
float Kd = 12.0;   // Derivative gain


int baseSpeed = 180;        // Base motor speed (adjust per robot)
float error = 0, lastError = 0, integral = 0, derivative = 0;
unsigned long lastTime = 0;

// Black and white sensor calibration values
int whiteValue = 850;  // Reading for white surface
int blackValue = 200;  // Reading for black line


void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(SENSOR_LEFT, INPUT);
  pinMode(SENSOR_RIGHT, INPUT);

  Serial.begin(9600);
  delay(2000);
  Serial.println("Robot Ready - Line Follower PID");
}


void loop() {
  int leftVal = analogRead(SENSOR_LEFT);
  int rightVal = analogRead(SENSOR_RIGHT);

  // Map sensor values to normalized range [0, 1]
  float leftNorm = mapSensor(leftVal);
  float rightNorm = mapSensor(rightVal);

  // Calculate error: positive = drift to right, negative = drift to left
  error = rightNorm - leftNorm;

  // PID computation
  unsigned long now = millis();
  float deltaTime = (now - lastTime) / 1000.0;
  integral += error * deltaTime;
  derivative = (error - lastError) / deltaTime;
  float correction = Kp * error + Ki * integral + Kd * derivative;

  lastError = error;
  lastTime = now;

  // Adjust motor speeds based on PID output
  int speedLeft = constrain(baseSpeed - correction, 0, 255);
  int speedRight = constrain(baseSpeed + correction, 0, 255);

  // Black square detection (both sensors detect black)
  if (leftVal < blackValue + 50 && rightVal < blackValue + 50) {
    performBlackSquareAction();
  } else {
    driveMotors(speedLeft, speedRight);
  }

  delay(10);
}



// Normalize sensor reading from analog value to [0,1]
float mapSensor(int raw) {
  return constrain((float)(raw - blackValue) / (whiteValue - blackValue), 0, 1);
}

// Drive motors with individual speed control
void driveMotors(int leftSpeed, int rightSpeed) {
  // Left motor (A)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, leftSpeed);

  // Right motor (B)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, rightSpeed);
}

// Behavior when black zone is detected
void performBlackSquareAction() {
  Serial.println("Black Zone Detected - Performing Action");

  // Short reverse
  driveBackward(150);
  delay(500);

  // 180° rotation
  turnAround();
}

// Reverse movement
void driveBackward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, speed);
}

// Rotate 180 degrees in place
void turnAround() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200);

  delay(900);  // Adjust this value to achieve a perfect 180° turn
  stopMotors();
}

// Stop motors
void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}