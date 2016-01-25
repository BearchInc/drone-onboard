#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "control.h"
#include <wiringPi.h>



int main(int argc,char **argv)
{
	const int butPin = 17;
	bool canpress = true;
    	wiringPiSetupGpio(); // Initialize wiringPi -- using Broadcom pin numbers
    	pinMode(butPin, INPUT);      // Set button as INPUT

	printf("Opening serial port...\n");
	if (OpenSerialPort() < 0) {
		perror("UAV Serial Port Open ERROR\n");
		return 0;
	}

	while(1) {
		bool button_released = digitalRead(butPin);
		if (!button_released && canpress ) { 
			printf("Button pressed...\n");
			canpress = false; 
		} else if (button_released && !canpress) {
			//printf("Activating user...\n");
			printf("Button released...\n");
			canpress = true;
			//ActivateUser();	
		}
	}
	
	return 0;
}
