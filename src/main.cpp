#include <Arduino.h>
#include <Stepper.h>

// change this to the number of steps on your motor
const int steps = 200;
int AIN1 = 1;
int AIN2 = 2;
int BIN1 = 3;
int BIN2 = 4;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to

Stepper stepper(steps, AIN1, AIN2, BIN1, BIN2);

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  // set the speed at 10 rpm:
  stepper.setSpeed(30);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  stepper.step(steps);
  delay(3000);

  // // step one revolution in the other direction:
  // Serial.println("counterclockwise");
  // stepper.step(-STEPS);
  // delay(1000);
}


/*
void setup()
{
  Serial.begin(9600);
  Serial.println("Stepper test!");
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(60);
}

void loop()
{
  Serial.println("Forward");
  stepper.step(STEPS);
  Serial.println("Backward");
  stepper.step(-STEPS);
}
*/