#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "control.h"

int main(int argc,char **argv)
{
	// sleep(10);
	int activation_result = ActivateUser();
	printf("Account creation response: %d\n", activation_result);
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