#include <iostream>
#include "brain.h"

using namespace std;
using namespace brain;

int Brain::Connect(Drone drone) {
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

    err = start_transfer();
    if (err) return err;
}

int Brain::handleDataEvent(int data_type, int data_len, char *content) {
    mutex.enter();

    switch (data_type) {
        case e_ultrasonic: {
            OnUltrasonicData((ultrasonic_data *) content);
            break;
        }

        case e_obstacle_distance: {
            OnObstacleDistanceData((obstacle_distance *) content);
            break;
        }
    }

    mutex.leave();
    return 0;
}

void Brain::RegisterForObstacleDistanceData(ObstacleDistanceDataHandler cb) {
    cout << "Registering on obstacle distance data handler" << endl;
    select_obstacle_distance();
    OnObstacleDistanceData = cb;
}

void Brain::RegisterForUltrasonicData(UltrasonicDataHandler cb) {
    cout << "Registering on ultrasonic data handler" << endl;
    select_ultrasonic();
    OnUltrasonicData = cb;
}

void Brain::StartAntisocialBehaviour() {
    select_ultrasonic();
    OnUltrasonicData = [&](ultrasonic_data* data) {
        //Frontal camera
        if (data->ultrasonic[1] < 200 && data->reliability[1] > 0) {
            drone->MoveBack();
        }
        //Back camera
        if (data->ultrasonic[3] < 200 && data->reliability[3] > 0) {
            drone->MoveForward();
        }
        //Right camera
        if (data->ultrasonic[2] < 200 && data->reliability[2] > 0) {
            drone->MoveLeft();
        }
        //Left camera
        if (data->ultrasonic[4] < 200 && data->reliability[4] > 0) {
            drone->MoveRight();
        }
    };
}