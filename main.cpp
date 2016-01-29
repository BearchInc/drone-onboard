#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wiringPi.h>
#include <DJI_guidance.h>

#include "models/Lock.h"
#include "control.h"

using namespace std;

//int main(int argc, char **argv) {
//    const int butPin = 16;
//    wiringPiSetupGpio(); // Initialize wiringPi -- using Broadcom pin numbers
//    pinMode(butPin, INPUT);      // Set button as INPUT
//    pullUpDnControl(butPin, PUD_UP);
//
//    cout << "Opening serial port..." << endl;
//    if (OpenSerialPort() < 0) {
//        cerr << "UAV Serial Port Open ERROR" << endl;
//        return 0;
//    }
//
//    ActivateUser();
//
//    bool pressed = false;
//    while (1) {
//        usleep(10000);
//        int button_state = digitalRead(butPin);
//        if (button_state == LOW && !pressed) {
//            pressed = true;
//            cout << "Button pressed..." << endl;
//            TakeOff();
//        } else if (button_state == HIGH && pressed) {
//            cout << "Button released..." << endl;
//            pressed = false;
//        }
//    }
//}

#define RETURN_IF_ERR(err_code) { if (err_code) { release_transfer(); cout << "Error: " << (e_sdk_err_code)err_code << " at " << __LINE__ << ", " << __FILE__ << endl; return -1; }}

int EventHandler(int data_type, int data_len, char *content);
int startGuidance();
int stopGuidance();

int main(int argc, char **argv)
{
    const int butPin = 16;
    wiringPiSetupGpio();        // Initialize wiringPi -- using Broadcom pin numbers
    pinMode(butPin, INPUT);      // Set button as INPUT
    pullUpDnControl(butPin, PUD_UP);

    cout << "Opening serial port..." << endl;
    if (OpenSerialPort() < 0) {
        cerr << "UAV Serial Port Open ERROR" << endl;
        return 0;
    }

    ActivateUser();

    bool pressed = false;
    bool flying = false;

    while (1) {
        usleep(10000);
        int button_state = digitalRead(butPin);
        if (button_state == LOW && !pressed) {
            pressed = true;
            cout << "Button pressed..." << endl;
            if (!flying) {
                TakeOff();
                int err_code = startGuidance();
                RETURN_IF_ERR(err_code);
                flying = true;
            } else {
                Land();
                int err_code = stopGuidance();
                RETURN_IF_ERR(err_code);
                return 0;
            }
        } else if (button_state == HIGH && pressed) {
            cout << "Button released..." << endl;
            pressed = false;
        }
    }
}

void moveDroneBack()
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

void moveDrone()
{
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

void moveDroneRight()
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

void moveDroneLeft()
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

int startGuidance()
{
    reset_config();

    int err_code = init_transfer();
    RETURN_IF_ERR(err_code);

    int online_status[CAMERA_PAIR_NUM];
    err_code = get_online_status(online_status);
    RETURN_IF_ERR(err_code);

    cout << "Sensor online status: ";
    for (int i=0; i<CAMERA_PAIR_NUM; i++)
        cout << online_status[i] << ", ";
    cout<<endl;

    select_ultrasonic();
    select_obstacle_distance();

    err_code = set_sdk_event_handler(EventHandler);
    RETURN_IF_ERR(err_code);

    err_code = start_transfer();
    RETURN_IF_ERR(err_code);

    return 0;
}

int stopGuidance() {
    int err_code = stop_transfer();
    RETURN_IF_ERR( err_code );
    //make sure the ack packet from GUIDANCE is received
    sleep( 1000000 );
    err_code = release_transfer();
    RETURN_IF_ERR( err_code );

    return 0;
}

Lock mutex;

int EventHandler(int data_type, int data_len, char *content)
{
    mutex.enter();

    cout << "Data Type: " << data_type << endl;

    switch (data_type)
    {
        case e_ultrasonic: {
            ultrasonic_data *data = (ultrasonic_data *) content;
            cout << "distance: " << data->ultrasonic[1] << endl;
            cout << "reliability: " << data->reliability[1] << endl << endl;
            //Frontal camera
            if (data->ultrasonic[1] < 200 && data->reliability[1] > 0) {
                moveDroneBack();
            }
            //Back camera
            if (data->ultrasonic[3] < 200 && data->reliability[3] > 0) {
                moveDrone();
            }
            //Right camera
            if (data->ultrasonic[2] < 200 && data->reliability[2] > 0 ) {
                moveDroneLeft();
            }
            //Left camera
            if (data->ultrasonic[4] < 200 && data->reliability[4] > 0) {
                moveDroneRight();
            }
            break;
        }

        case e_obstacle_distance: {
            obstacle_distance *data = (obstacle_distance *) content;
            cout << "distance: " << data->distance[1] << endl << endl;
            break;
        }
    }

    mutex.leave();
    return 0;
}
