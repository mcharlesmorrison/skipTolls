#include <Arduino.h>

// function declarations
int myFunction(int, int);


#define MOTOR_IN1 1
#define MOTOR_IN2 2

void setup() {
  Serial.begin(9600);

  Serial.println("DRV8871 test");
  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
}

void loop() {

  // ramp up forward
  digitalWrite(MOTOR_IN1, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN2, i);
    delay(10);
    Serial.println("loop 1");
  }

  // forward full speed for one second
  delay(1000);
  
  // ramp down forward
  for (int i=255; i>=0; i--) { //attn was i=255
    analogWrite(MOTOR_IN2, i);
    delay(10);
    Serial.println("loop 2");
  }

  // ramp up backward
  digitalWrite(MOTOR_IN2, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN1, i);
    delay(10);
    Serial.println("loop 3");
  }

  // backward full speed for one second
  delay(1000);

  // ramp down backward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN1, i);
    delay(10);
    Serial.println("loop 4");
  }
}

// function definitions
int myFunction(int x, int y) {
  return x + y;
}