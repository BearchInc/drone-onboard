#include "Sensors.h"
#include <DJI_guidance.h>

using namespace droneonboard;

namespace droneonboard {
    vector<DataHandler> handlers;

    int on_board_event_handler(int data, int len, char *content) {
        for (int i = 0; i < handlers.size(); i++) {
            handlers[i](data, len, content);
        }

        return 0;
    }
}

void Sensors::Connect() {
    // TODO
    // Register the remaining data events
    select_ultrasonic();
    select_obstacle_distance();
    set_sdk_event_handler(&on_board_event_handler);
    start_transfer();
}

void Sensors::Disconnect() {
    stop_transfer();
    release_transfer();
}

void Sensors::OnData(DataHandler handler) {
    handlers.push_back(handler);
}