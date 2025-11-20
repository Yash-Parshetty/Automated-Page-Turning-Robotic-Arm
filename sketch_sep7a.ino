#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Match Arduino Servo.h timing
#define SERVOMIN  112   // 0° = ~544µs
#define SERVOMAX  492   // 180° = ~2400µs

// Servo channels on PCA9685
int motor1 = 0;  // Base
int motor2 = 1;  // Fixed
int motor3 = 2;  // Fixed
int motor4 = 3;  // Fixed
int motor5 = 4;  // Claw

// Store current angle of motor1
int motor1_angle = 220;  // logical starting angle

// Map angle to PCA9685 pulse
int angleToPulse(int ang) {
  return map(ang, 0, 180, SERVOMIN, SERVOMAX);
}

// ---------------- Motor Functions ----------------

// Smooth movement with tracking
void moveMotorSlow(int motor, int &currentAngle, int targetAngle, int stepDelay) {
  if (currentAngle < targetAngle) {
    for (int a = currentAngle; a <= targetAngle; a++) {
      pwm.setPWM(motor, 0, angleToPulse(a));
      delay(stepDelay);
    }
  } else {
    for (int a = currentAngle; a >= targetAngle; a--) {
      pwm.setPWM(motor, 0, angleToPulse(a));
      delay(stepDelay);
    }
  }
  currentAngle = targetAngle; // Update stored angle
}

// Motor 1 (Base)
void motor1_rest() {
  moveMotorSlow(motor1, motor1_angle, 220, 10);   // Go to rest smoothly
}
void motor1_left() {
  moveMotorSlow(motor1, motor1_angle, 135, 10);   // Go to left smoothly
}

// Motor 2 (Fixed)
void holdMotor2() {
  pwm.setPWM(motor2, 0, angleToPulse(270));   // Hold at angle
}

// Motor 3 (Fixed)
void holdMotor3() {
  pwm.setPWM(motor3, 0, angleToPulse(30));    // Hold at angle
}

// Motor 4 (Fixed)
void holdMotor4() {
  pwm.setPWM(motor4, 0, angleToPulse(35));    // Hold at angle
}

// Motor 5 (Claw)
void motor5_open() {
  pwm.setPWM(motor5, 0, angleToPulse(90));    // Open
}
void motor5_close() {
  pwm.setPWM(motor5, 0, angleToPulse(35));    // Close
}

// -------------------------------------------------

void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);  // 60Hz for servos
  delay(10);

  // ✅ Force motor1 directly to rest (center) at startup
  pwm.setPWM(motor1, 0, angleToPulse(220));
  motor1_angle = 220;

  // Initialize others
  holdMotor2();
  holdMotor3();
  holdMotor4();
  motor5_open();
  delay(1000);
}

void loop() {
  // 1. Base at rest, claw closes (grab paper)
  motor1_rest();
  motor5_close();
  delay(4000);

  // 2. Base moves left (holding paper)
  motor1_left();
  delay(2000);

  // 3. Claw opens (release paper)
  motor5_open();
  delay(3000);

  // 4. Base returns to rest
  motor1_rest();
  delay(1000);

  // Loop continues
}
