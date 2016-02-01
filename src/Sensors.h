#ifndef DRONEONBOARD_SENSORS_H
#define DRONEONBOARD_SENSORS_H

#include <vector>
#include <functional>

using namespace std;

namespace droneonboard {
    typedef function<void(int, int, char*)> DataHandler;

    class Sensors {
    public:
        void Connect();
        void Disconnect();
        void OnData(DataHandler handler);
    };
}

#endif
