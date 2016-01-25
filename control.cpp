#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include "control.h"
#include "DJI_LIB/DJI_Pro_App.h"

void hello_world()
{
	printf("hello world");
	// return 0;
}

int OpenSerialPort() {
	int baudrate = 115200;
	char uart_name[32] = {"/dev/ttyAMA0"};

	if(Pro_Hw_Setup(uart_name, baudrate) < 0) {
		return -1;
	}

	DJI_Pro_Setup(NULL);
	return 0;
}

activate_data_t user_act_data;
void ActivateUser() {
	char key[] = "a4dc524ca61ca643a9cf1a70cc3f711cb17fc8dea13e7ef96d12bdc10ee2a11a";
	char app_bundle_id[32] = "1234567890";

	user_act_data.app_key = key;
	user_act_data.app_id = 1024717;
	user_act_data.app_api_level = 2;
	user_act_data.app_ver = SDK_VERSION;
	strcpy((char*)user_act_data.app_bundle_id, app_bundle_id);

	DJI_Pro_Activate_API(&user_act_data, NULL);
}

void TakeOff() {
	DJI_Pro_Status_Ctrl(4,0);
}

void Land() {
	DJI_Pro_Status_Ctrl(6,0);
}

void RequestControl() {
	DJI_Pro_Control_Management(1,NULL);
}