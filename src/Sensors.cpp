#include "Sensors.h"
#include <DJI_guidance.h>

using namespace droneonboard;

vector<DataHandler> handlers;

int on_board_event_handler(int data, int len, char *content) {
    for (int i = 0; i < handlers.size(); i++) {
        handlers[i](data, len, content);
    }

    return 0;
}

int Sensors::Connect() {
    set_sdk_event_handler(&on_board_event_handler);
}

void Sensors::AddDataHandler(DataHandler handler) {
    handlers.push_back(handler);
}