#pragma once

#include <vector>

using namespace std;

namespace droneonboard {
    typedef void (*DataHandler)(int, int, char *);

    vector<DataHandler> handlers;

    void on_board_event_handler(int data, int len, char *content) {
        for (int i = 0; i < handlers.size(); i++) {
            handlers[i](data, len, content);
        }
    }

    class Sensors {
    public:
        int Connect();

        int Disconnect();

        AddDataHandler(DataHandler);
    };
}
