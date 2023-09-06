#include "src/Motor.h"

#define LEFT_WHEEL 1
#define RIGHT_WHEEL 2
#define DirectionPin 4
#define BaudRate 115200

void setup() {

    // Initialization
    Serial.begin(BaudRate);
    Motor.begin(BaudRate, DirectionPin, &Serial2);

    // To preparation point
    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(8570);
    
    // Turn to target #1
    Motor.turnWheel(LEFT_WHEEL, RIGHT, 20);
    Motor.turnWheel(RIGHT_WHEEL, LEFT, 20);

    delay(2143);

    Motor.turnWheel(LEFT_WHEEL, RIGHT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(1950);

    Motor.turnWheel(LEFT_WHEEL, RIGHT, 0);
    Motor.turnWheel(RIGHT_WHEEL, LEFT, 0);
    delay(100);

    
    Motor.turnWheel(LEFT_WHEEL, RIGHT, 20);
    Motor.turnWheel(RIGHT_WHEEL, LEFT, 20);

    delay(8751);

    // Back to preparation point
    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(8214);

    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, LEFT, 20);

    delay(1950);

    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(1786);

    Motor.turnWheel(LEFT_WHEEL, LEFT, 0);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 0);

    delay(500);

    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(4857);

    // Back to preparation point
    Motor.turnWheel(LEFT_WHEEL, RIGHT, 20);
    Motor.turnWheel(RIGHT_WHEEL, LEFT, 20);

    delay(3929);

    // Turn to target #3
    Motor.turnWheel(LEFT_WHEEL, RIGHT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(1950);

    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(6429);

    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, LEFT, 20);

    delay(1950);

    // Rotate around half-circle
    Motor.turnWheel(LEFT_WHEEL, LEFT, 35);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 70);
    delay(4200);

    // Last turn
    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(500);
    
    Motor.turnWheel(LEFT_WHEEL, RIGHT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(900);

    // Last forward
    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(7143);

    Motor.turnWheel(LEFT_WHEEL, LEFT, 0);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 0);
    

}

void loop() {}
