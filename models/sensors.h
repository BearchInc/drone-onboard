#pragma once

#include <functional>

#include "DJI_Pro_App.h"
#include "DJI_guidance.h"
#include "drone.h"
#include "Lock.h"

using namespace std;
typedef function<void(ultrasonic_data*)> UltrasonicDataHandler;
typedef function<void(obstacle_distance*)> ObstacleDistanceDataHandler;

namespace drones {

    class Sensors {
    public:
        static Lock mutex;
        static UltrasonicDataHandler OnUltrasonicData;
        static ObstacleDistanceDataHandler OnObstacleDistanceData;
        static int handleDataEvent(int data_type, int data_len, char *content);
        static int num;

        static int Connect();
        static int Disconnect();

        static void StartAntisocialBehaviour();
        static void RegisterForUltrasonicData(UltrasonicDataHandler cb);
        static void RegisterForObstacleDistanceData(ObstacleDistanceDataHandler cb);
    };
}