#include <iostream>
#include <wiringPi.h>
#include "Brain.h"

using namespace std;
using namespace droneonboard;

void Brain::Think() {
    // TODO
    // . implement AI...
    // . handle errors try/catch disconnecting components upon failure


    sensors.OnUltrasonicData([this](ultrasonic_data *data) {
        if (data->ultrasonic[0] > 500)
            cout << drone.Say("Object is too close!") << endl;
    });

    sensors.OnObstacleDistance([this](obstacle_distance *data) {
        if (data->distance[0] > 100)
            cout << drone.Say("Oh dear! Object is SUPA close!") << endl;
    });

    this->drone.Connect();
    this->sensors.Connect();
    while (1) delay(500);
}