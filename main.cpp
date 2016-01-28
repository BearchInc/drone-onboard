#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wiringPi.h>
#include <DJI_guidance.h>

#include "Lock.h"
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

int main(int argc, char **argv)
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

    err_code = set_sdk_event_handler(EventHandler);
    RETURN_IF_ERR(err_code);

    err_code = start_transfer();
    RETURN_IF_ERR(err_code);

    while(1)
    {
        cout << "Waiting for sensor data" << endl;
        delay(1000);
    }

    return 0;
}

Lock mutex;

int EventHandler(int data_type, int data_len, char *content)
{
    mutex.enter();

    ultrasonic_data* data = (ultrasonic_data*)content;

    // TODO Add mutex to avoid race conditions
    // Apparently the SDK does not ensure callback calls are serialized.
    cout << "distance: " << data->ultrasonic[1] << endl;
    cout << "reliability: " << data->reliability[1] << endl;

    delay(2000);
    mutex.leave();
    return 0;
}