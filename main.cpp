#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "control.h"
#include <wiringPi.h>



int main(int argc,char **argv)
{
	const int butPin = 17;
	bool button_pressed = false;
    	wiringPiSetupGpio(); // Initialize wiringPi -- using Broadcom pin numbers
    	pinMode(butPin, INPUT);      // Set button as INPUT

	printf("Opening serial port...\n");
	if (OpenSerialPort() < 0) {
		perror("UAV Serial Port Open ERROR\n");
		return 0;
	}

	while(1) {
		// Button is released if this returns 1
		if (digitalRead(butPin)) { 
			printf("Button released...\n");
			button_pressed = false;
		} else if(!button_pressed) {
			printf("Activating user...\n");
			printf("Button pressed...\n");
			ActivateUser();	
		}
	}
	
	return 0;
}
