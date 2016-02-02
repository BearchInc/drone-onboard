#pragma once

#include <string>

namespace droneonboard {

    class Drone {
        std::string device;
        int baudrate;
    public:
        Drone(std::string device, int baudrate) : device(device), baudrate(baudrate) {}
        void Connect();
        void Disconnect();
        std::string Say(std::string name);
    };
}
