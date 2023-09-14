#include "src/Motor.h"

#define REVERSE 0
#define FORWARD 1

#define SPEED 20
#define LEFT_WHEEL 1
#define RIGHT_WHEEL 2
#define DirectionPin 4
#define BaudRate 115200

// Move robot for `d` cm in `mode` direction
void move(float distance_cm, int mode) {

    float distance_per_sec = 7;
    int target_time = round(distance_cm * (1000 / distance_per_sec));

    switch (mode) {

        case FORWARD:

            Motor.turnWheel(LEFT_WHEEL, LEFT, SPEED);
            Motor.turnWheel(RIGHT_WHEEL, RIGHT, SPEED);

            delay(target_time);

            break;
        
        case REVERSE:
            
            Motor.turnWheel(LEFT_WHEEL, RIGHT, SPEED);
            Motor.turnWheel(RIGHT_WHEEL, LEFT, SPEED);

            delay(target_time);

            break;
        
        default:
            break;

    }

}


// Stop moving for `n` milliseconds
void pause(int time_ms) {
    Motor.turnWheel(LEFT_WHEEL, RIGHT, 0);
    Motor.turnWheel(RIGHT_WHEEL, LEFT, 0);
    delay(time_ms);
}


void setup() {

    // Initialization
    Serial.begin(BaudRate);
    Motor.begin(BaudRate, DirectionPin, &Serial2);

    // To preparation point
    move(60, FORWARD);
    
    // Turn to target #1
    move(12.5, REVERSE);

    // Rotate left 90deg
    Motor.turnWheel(LEFT_WHEEL, RIGHT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(1857);

    pause(100);
    
    move(61.25, REVERSE);

    // Back to preparation point
    move(61.25, FORWARD);

    // Rotate right 90deg
    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, LEFT, 20);

    delay(1950);

    move(12.5, FORWARD);

    // Stop for a while
    pause(500);

    move(25, FORWARD);

    pause(500);

    // Turn to beeper
    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 0);

    delay(1000);

    Motor.turnWheel(LEFT_WHEEL, RIGHT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 0);

    delay(1000);

    // Back to preparation point
    move(22.5, REVERSE);

    // Turn to target #3
    Motor.turnWheel(LEFT_WHEEL, RIGHT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(1950);

    move(45, FORWARD);

    Motor.turnWheel(LEFT_WHEEL, LEFT, 20);
    Motor.turnWheel(RIGHT_WHEEL, LEFT, 20);

    delay(1950);

    // Rotate around half-circle
    Motor.turnWheel(LEFT_WHEEL, LEFT, 35);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 75);
    delay(3600);

    move(15, FORWARD);

    // Last turn
    Motor.turnWheel(LEFT_WHEEL, RIGHT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);

    delay(1100);

    // Last forward
    move(45, FORWARD);

    Motor.turnWheel(LEFT_WHEEL, LEFT, 0);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 0);
    
}


void loop() {}
