#pragma once

#include <DJI_guidance.h>
#include "guidance.h"

namespace droneonboard {
    class Sensors {
    public:
        void Connect();
        void Disconnect();
        void OnUltrasonicData(guidance::UltrasonicDataListener);
        void OnObstacleDistance(guidance::ObstacleDistanceDataListener);
    };
}
