#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "control.h"

int main(int argc,char **argv)
{
	printf("Opening serial port...");
	if (OpenSerialPort() < 0) {
		perror("UAV Serial Port Open ERROR/n");
		return 0;
	}
	usleep(3000000);
	printf("Activating user...");
	ActivateUser();
	usleep(3000000);
	printf("Requesting control...");
	RequestControl();
	usleep(3000000);
	printf("Taking off...");
	TakeOff();
	usleep(10000000);
	printf("Landing...");
	Land();
	return 0;
}