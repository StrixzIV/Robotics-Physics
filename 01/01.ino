#include "src/Motor.h"

#define DirectionPin 4
#define BaudRate 115200

int RPM_L = 94;
int RPM_R = 54;

void setup() {

  Motor.begin(BaudRate, DirectionPin, &Serial2);
  Motor.turnWheel(1, LEFT, RPM_L);
  Motor.turnWheel(2, RIGHT, RPM_R);

  delay(8000);

  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, 0);

}

void loop() {}