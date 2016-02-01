#pragma once

#include "Sensors.h"
#include "Drone.h"

namespace droneonboard {

    class Brain {
        Drone drone;
        Sensors sensors;
    public:
        Brain(Drone d, Sensors s) : drone(d), sensors(s) {}
        void Think();
    };
}

