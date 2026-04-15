// config.h

#ifndef CONFIG_H
#define CONFIG_H

// Pin definitions
const int TM1638_CLK_PIN = 2;
const int TM1638_DATA_PIN = 3;
const int MOTOR_DRIVER_PIN = 4;
const int BUTTON_PIN = 5;

// Constants and configuration
const int DEBOUNCE_DELAY = 50; // milliseconds
const float GEAR_RATIO = 5.0; // Example gear ratio
const int MAX_SPEED = 100; // Maximum speed limit

#endif // CONFIG_H