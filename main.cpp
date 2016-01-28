#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "control.h"
#include <wiringPi.h>

int main(int argc, char **argv) {
    const int butPin = 16;
    wiringPiSetupGpio(); // Initialize wiringPi -- using Broadcom pin numbers
    pinMode(butPin, INPUT);      // Set button as INPUT
    pullUpDnControl(butPin, PUD_UP);

    printf("Opening serial port...\n");
    if (OpenSerialPort() < 0) {
        perror("UAV Serial Port Open ERROR\n");
        return 0;
    }

    ActivateUser();

    bool pressed = false;
    while (1) {
        usleep(10000);
        int button_state = digitalRead(butPin);
        if (button_state == LOW && !pressed) {
            pressed = true;
            printf("Button pressed...\n");
            TakeOff();
        } else if (button_state == HIGH && pressed) {
            printf("Button released...\n");
            pressed = false;
        }
    }
}
