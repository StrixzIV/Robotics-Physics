#include "src/Motor.h"

#define LEFT_WHEEL 1
#define RIGHT_WHEEL 2
#define DirectionPin 4
#define BaudRate 115200

void setup() {

  Serial.begin(BaudRate);
  Motor.begin(BaudRate, DirectionPin, &Serial2);

  Motor.turnWheel(LEFT_WHEEL, LEFT, 10);

}

void loop() {

  int left_motor_angle = Motor.readPosition(LEFT_WHEEL);

  Serial.println(left_motor_angle);

  if (left_motor_angle > 180) {
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 10);
  }

}
