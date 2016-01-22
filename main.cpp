#include <iostream>
#include <stdio.h>
#include <string.h>
#include "control.h"

int main(int argc,char **argv)
{
	// sleep(10);
	int activation_result = ActivateUser();
	printf("Account creation response: %d\n", activation_result);
	sleep(3);
	printf("Requesting control...");
	RequestControl();
	sleep(3);
	printf("Taking off...");
	TakeOff();
	sleep(10);
	printf("Landing...");
	Land();
	return 0;
}