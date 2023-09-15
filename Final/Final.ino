#include "src/Motor.h"

#define REVERSE 0
#define FORWARD 1

#define SPEED 20
#define LEFT_WHEEL 1
#define RIGHT_WHEEL 2
#define DIRECTION_PIN 4
#define BRAUD_RATE 115200

// a distance that robot could move in 1 second.
const float DISTANCE_PER_SEC = 7;

// Move robot for `d` cm in `mode` direction
void move(float distance_cm, int mode) {

    int time_to_target = round(distance_cm * (1000 / DISTANCE_PER_SEC));

    switch (mode) {

        case FORWARD:

            Motor.turnWheel(LEFT_WHEEL, LEFT, SPEED);
            Motor.turnWheel(RIGHT_WHEEL, RIGHT, SPEED);

            delay(time_to_target);

            break;
        
        case REVERSE:
            
            Motor.turnWheel(LEFT_WHEEL, RIGHT, SPEED);
            Motor.turnWheel(RIGHT_WHEEL, LEFT, SPEED);

            delay(time_to_target);

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
    Serial.begin(BRAUD_RATE);
    Motor.begin(BRAUD_RATE, DIRECTION_PIN, &Serial2);

    // To preparation point
    move(60, FORWARD);
    
    // Move to target #1
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
    pause(500);

    // Move to target #2
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

    // Move to target #3
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

    // Move forward to last turning point
    move(15, FORWARD);

    // Last turn
    Motor.turnWheel(LEFT_WHEEL, RIGHT, 20);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 20);
    delay(1100);

    // Last forward
    move(45, FORWARD);

    // Stop the robot
    Motor.turnWheel(LEFT_WHEEL, LEFT, 0);
    Motor.turnWheel(RIGHT_WHEEL, RIGHT, 0);
    
}


void loop() {}
