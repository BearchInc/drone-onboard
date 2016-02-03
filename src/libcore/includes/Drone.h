#pragma once

#include <string>

namespace droneonboard {

    class DJIAccount
    {
        std::string id;
        std::string key;
        std::string bundle_id;

    public:
        DJIAccount(std::string id = "", std::string key = "", std::string bundle_id = "") : id(id), key(key), bundle_id(bundle_id) {}
    };


    class Drone {
        std::string device;
        int baudrate;
    public:
        Drone(std::string device, int baudrate, DJIAccount account) : device(device), baudrate(baudrate) {}
        void Connect();
        void Disconnect();
        std::string Say(std::string name);
    };
}
