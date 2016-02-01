#include <iostream>
#include "sensors.h"

using namespace std;
using namespace drones;

int Sensors::Connect() {
    int err = init_transfer();
    if (err) return err;
    cout << "Guidance module initialized" << endl;

    int online_status[CAMERA_PAIR_NUM];
    err = get_online_status(online_status);
    if (err) return err;
    cout << "Sensors online status: ";
    for (int i = 0; i < CAMERA_PAIR_NUM; i++)
        cout << online_status[i] << ", ";
    cout << endl;

    set_sdk_event_handler(&handleDataEvent);

    err = start_transfer();
    if (err) return err;
}

int Sensors::handleDataEvent(int data_type, int data_len, char *content) {
//    mutex.enter();

    switch (data_type) {
        case e_ultrasonic: {
//            OnUltrasonicData((ultrasonic_data *) content);
            break;
        }

        case e_obstacle_distance: {
//            OnObstacleDistanceData((obstacle_distance *) content);
            break;
        }
    }

//    mutex.leave();
    return 0;
}

void Sensors::RegisterForObstacleDistanceData(ObstacleDistanceDataHandler cb) {
    cout << "Registering on obstacle distance data handler" << endl;
    select_obstacle_distance();
//    OnObstacleDistanceData = cb;
}

void Sensors::RegisterForUltrasonicData(UltrasonicDataHandler cb) {
    cout << "Registering on ultrasonic data handler" << endl;
    select_ultrasonic();
//    OnUltrasonicData = cb;
}