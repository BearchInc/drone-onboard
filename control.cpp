#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include "control.h"
#include "DJI_LIB/DJI_Pro_App.h"

activate_data_t user_act_data;
int baudrate = 230400;
char uart_name[32] = {"/dev/ttyAMA0"};
char app_bundle_id[32] = "1234567890";
char key[] = "f28973098ca26058f1c2a81676a49e48fad27a4703728811ffb612526087a2e0";

void OnActivate(unsigned short result) {
    printf("Activated with code: %d\n", result);
    usleep(3000000);
    printf("Quizz: Quanto tempo passou?\n");
    RequestControl();
}

int OpenSerialPort() {
    if (Pro_Hw_Setup(uart_name, baudrate) < 0) {
        return -1;
    }

    DJI_Pro_Setup(NULL);
    return 0;
}

void ActivateUser() {
    user_act_data.app_key = key;
    user_act_data.app_id = 1024746;
    user_act_data.app_api_level = 2;
    user_act_data.app_ver = SDK_VERSION;

    strcpy((char *) user_act_data.app_bundle_id, app_bundle_id);
    DJI_Pro_Activate_API(&user_act_data, &OnActivate);
}

void TakeOff() {
    DJI_Pro_Status_Ctrl(4, 0);
}

void Land() {
    DJI_Pro_Status_Ctrl(6, 0);
}

void RequestControl() {
    DJI_Pro_Control_Management(1, NULL);
}
