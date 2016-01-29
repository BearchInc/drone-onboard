#pragma once

#include <functional>

#include "DJI_Pro_App.h"
#include "DJI_guidance.h"
#include "drone.h"
#include "Lock.h"

using namespace std;

typedef function<void(ultrasonic_data*)> UltrasonicDataHandler;
typedef function<void(obstacle_distance*)> ObstacleDistanceDataHandler;

namespace brain {

    class Brain {
        Drone* drone;
        Lock mutex;

        UltrasonicDataHandler OnUltrasonicData;
        ObstacleDistanceDataHandler OnObstacleDistanceData;

        int handleDataEvent(int data_type, int data_len, char *content);

    public:
        Brain();

        int Connect(Drone drone);
        int Disconnect();

        void RegisterForUltrasonicData(UltrasonicDataHandler cb);
        void RegisterForObstacleDistanceData(ObstacleDistanceDataHandler cb);

        void StartAntisocialBehaviour();

    };
}