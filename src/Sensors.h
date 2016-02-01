#pragma once

#include <functional>
#include <DJI_guidance.h>

using namespace std;

namespace droneonboard {
    typedef function<void(ultrasonic_data* data)> UltrasonicDataHandler;
    typedef function<void(obstacle_distance* data)> ObstacleDistanceDataHandler;

    class Sensors {
    public:
        void Connect();
        void Disconnect();
        void OnUltrasonicData(UltrasonicDataHandler);
        void OnObstacleDistance(ObstacleDistanceDataHandler);
    };
}
