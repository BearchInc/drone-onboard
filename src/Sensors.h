#ifndef DRONEONBOARD_SENSORS_H
#define DRONEONBOARD_SENSORS_H

#include <vector>

using namespace std;

namespace droneonboard {
    typedef void (*DataHandler)(int, int, char *);

    class Sensors {
    public:
        int Connect();

        int Disconnect();

        void AddDataHandler(DataHandler handler);
    };
}

#endif
