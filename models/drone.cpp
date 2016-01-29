#include <iostream>
#include <unistd.h>
#include "drone.h"

using namespace std;

Drone::Drone()
{
    cout << "Object is being created" << endl;
}

activate_data_t user_act_data;
int baudrate = 230400;
char uart_name[32] = {"/dev/ttyAMA0"};
char app_bundle_id[32] = "1234567890";

char port_name[32] = {"/dev/ttyAMA0"};

bool OpenSerialPort() {
    cout << "Openning serial port" << endl;
    int baudrate = 230400;
    
    if (Pro_Hw_Setup(port_name, baudrate) < 0) {
        cout << "Failed to serial port" << endl;
        return true;
    }

    cout << "DJI Pro Setup" << endl;
    DJI_Pro_Setup(NULL);
    return false;
}

void OnActivate(unsigned short result) {
    printf("Drone activated with code: %d\n", result);
    usleep(2000000);
    cout << "Requesting control" << endl;
    DJI_Pro_Control_Management(1, NULL);
}

bool Drone::Connect(int app_id, char key[]) 
{
    cout << "Connecting to drone..." << endl;
    if(OpenSerialPort()) {
        return false;
    }

    user_act_data.app_key = key;
    user_act_data.app_id = app_id;
    user_act_data.app_api_level = 2;
    user_act_data.app_ver = SDK_VERSION;

    strcpy((char *) user_act_data.app_bundle_id, app_bundle_id);
    DJI_Pro_Activate_API(&user_act_data, &OnActivate);
}

bool Drone::Disconnect() {
    cout << "Releasing control" << endl;
    DJI_Pro_Control_Management(0, NULL);
} 

bool Drone::TakeOff() {
    DJI_Pro_Status_Ctrl(4, 0);
    return true;
}

bool Drone::Land() {
    return false;
}

void Drone::MoveBack()
{
    attitude_data_t user_ctrl_data;
    int i;
    for(i = 0;i < 60;i++)
    {
        user_ctrl_data.ctrl_flag = HORIZ_POS|VERT_VEL|YAW_ANG|HORIZ_BODY|YAW_BODY;
        user_ctrl_data.roll_or_x = 3;
        user_ctrl_data.pitch_or_y = 0;
        user_ctrl_data.thr_z = 0;
        user_ctrl_data.yaw = 0;
        DJI_Pro_Attitude_Control(&user_ctrl_data);
    }
}

void Drone::MoveForward() {
    attitude_data_t user_ctrl_data;
    int i;
    for(i = 0;i < 60;i++)
    {
        user_ctrl_data.ctrl_flag = HORIZ_POS|VERT_VEL|YAW_ANG|HORIZ_BODY|YAW_BODY;
        user_ctrl_data.roll_or_x = -3;
        user_ctrl_data.pitch_or_y = 0;
        user_ctrl_data.thr_z = 0;
        user_ctrl_data.yaw = 0;
        DJI_Pro_Attitude_Control(&user_ctrl_data);
    }
}

void Drone::MoveRight()
{
    attitude_data_t user_ctrl_data;
    int i;
    for(i = 0;i < 60;i++)
    {
        user_ctrl_data.ctrl_flag = HORIZ_POS|VERT_VEL|YAW_ANG|HORIZ_BODY|YAW_BODY;
        user_ctrl_data.roll_or_x = 0;
        user_ctrl_data.pitch_or_y = -3;
        user_ctrl_data.thr_z = 0;
        user_ctrl_data.yaw = 0;
        DJI_Pro_Attitude_Control(&user_ctrl_data);
    }
}

void Drone::MoveLeft()
{
    attitude_data_t user_ctrl_data;
    int i;
    for(i = 0;i < 60;i++)
    {
        user_ctrl_data.ctrl_flag = HORIZ_POS|VERT_VEL|YAW_ANG|HORIZ_BODY|YAW_BODY;
        user_ctrl_data.roll_or_x = 0;
        user_ctrl_data.pitch_or_y = 3;
        user_ctrl_data.thr_z = 0;
        user_ctrl_data.yaw = 0;
        DJI_Pro_Attitude_Control(&user_ctrl_data);
    }
}

