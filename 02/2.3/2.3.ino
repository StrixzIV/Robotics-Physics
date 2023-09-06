#include "src/Motor.h"

#define LEFT_WHEEL 1
#define RIGHT_WHEEL 2
#define DirectionPin 4
#define BaudRate 115200

void setup() {

  Serial.begin(BaudRate);
  Motor.begin(BaudRate, DirectionPin, &Serial2);

  Motor.turnWheel(LEFT_WHEEL, LEFT, 50);
  delay(300);

  Motor.turnWheel(RIGHT_WHEEL, RIGHT, 50);
  delay(3000);

  Motor.turnWheel(RIGHT_WHEEL, RIGHT, 0);
  delay(2500);

  Motor.turnWheel(RIGHT_WHEEL, RIGHT, 50);
  delay(3000);
  
  Motor.turnWheel(RIGHT_WHEEL, RIGHT, 0);
  delay(2450);

  Motor.turnWheel(RIGHT_WHEEL, RIGHT, 50);
  delay(2500);

  Motor.turnWheel(RIGHT_WHEEL, RIGHT, 0);
  delay(2350);

  Motor.turnWheel(RIGHT_WHEEL, RIGHT, 50);
  delay(2350);

  Motor.turnWheel(RIGHT_WHEEL, RIGHT, 0);
  delay(2750);

  Motor.turnWheel(RIGHT_WHEEL, RIGHT, 50);
  delay(2500);

  Motor.turnWheel(LEFT_WHEEL, LEFT, 0);
  Motor.turnWheel(RIGHT_WHEEL, RIGHT, 0);

}

void loop() {}
