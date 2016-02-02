#pragma once

#include <functional>
#include <DJI_guidance.h>

namespace droneonboard {
    typedef std::function<void(ultrasonic_data* data)> UltrasonicDataHandler;
    typedef std::function<void(obstacle_distance* data)> ObstacleDistanceDataHandler;

    class Sensors {
    public:
        void Connect();
        void Disconnect();
        void OnUltrasonicData(UltrasonicDataHandler);
        void OnObstacleDistance(ObstacleDistanceDataHandler);
    };
}
