#include "src/Motor.h"

#define LEFT_WHEEL 1
#define RIGHT_WHEEL 2
#define DirectionPin 4
#define BaudRate 115200

void setup() {

  Serial.begin(BaudRate);
  Motor.begin(BaudRate, DirectionPin, &Serial2);

}

void loop() {}