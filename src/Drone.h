#pragma once

#include <string>

using namespace std;

namespace droneonboard {

    class Drone {
        string device;
        int baudrate;
    public:
        Drone(string device, int baudrate) : device(device), baudrate(baudrate) {}
        void Connect();
        void Disconnect();
        string Say(string name);
    };
}
