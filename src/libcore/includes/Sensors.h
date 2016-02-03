#pragma once

#include <DJI_guidance.h>
#include "Guidance.h"

namespace droneonboard {
    class Sensors {
    public:
        Sensors() {}
        void Connect();
        void Disconnect();
        void OnUltrasonicData(guidance::UltrasonicDataListener);
        void OnObstacleDistance(guidance::ObstacleDistanceDataListener);
    };
}
