#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this value to fit the number of steps per revolution for your motor

// initialize the stepper and set the speed:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// initialize the L298N module and set the pins:
const int enA = 6;
const int in1 = 7;
const int in2 = 4;

void setup() {
  // set the speed of the stepper motor:
  myStepper.setSpeed(60);

  // set the pins for the L298N module as outputs:
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  // move the stepper motor clockwise:
  myStepper.step(stepsPerRevolution);

  // set the speed of the DC motor and change its direction:
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(1000);

  // set the speed of the DC motor and change its direction again:
  analogWrite(enA, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(1000);
}
