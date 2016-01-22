#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include "control.h"
	
void hello_world()
{
	printf("hello world");
	// return 0;
}

void ActivateUser() {
	activate_data_t user_act_data;
	char key[] = "a4dc524ca61ca643a9cf1a70cc3f711cb17fc8dea13e7ef96d12bdc10ee2a11a";
	user_act_data.app_key = key;
	user_act_data.app_id = 1024717;
	user_act_data.app_api_level = 2;
	user_act_data.app_ver = SDK_VERSION;
	DJI_Pro_Activate_API(&user_act_data, NULL);

}