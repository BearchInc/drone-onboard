#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "control.h"

int main(int argc,char **argv)
{
	printf("Opening serial port...");
	if (OpenSerialPort() < 0) {
		perror("UAV Serial Port Open ERROR\n");
		return 0;
	}
	usleep(7000000);
	printf("Activating user...\n");
	ActivateUser();
	usleep(7000000);
	printf("Requesting control...\n");
	RequestControl();
	usleep(10000000);
	printf("Taking off...\n");
	TakeOff();
	usleep(20000000);
	printf("Landing...\n");
	Land();
	return 0;
}