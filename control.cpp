#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include "control.h"
#include "DJI_LIB/DJI_Pro_App.h"

activate_data_t ActivateUser(Command_Result_Notify cb) {
	int app_id = 1024717;
	char app_bundle_id[32] = "1234567890";
	char key[] = "a4dc524ca61ca643a9cf1a70cc3f711cb17fc8dea13e7ef96d12bdc10ee2a11a";

	activate_data_t user_act_data;
	user_act_data.app_key = key;
	user_act_data.app_id = app_id;
	user_act_data.app_api_level = 2;
	user_act_data.app_ver = SDK_VERSION;
	strcpy((char*)user_act_data.app_bundle_id, app_bundle_id);

	DJI_Pro_Activate_API(&user_act_data, cb);
	return user_act_data;
}

void onActivate(unsigned short result)
{
	printf("### activation result: %d\n", result);
}

void onSetup(ProHeader *pHeader)
{
	printf("### header %d\n", pHeader->session_id);
}

