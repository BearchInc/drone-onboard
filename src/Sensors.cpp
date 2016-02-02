#include <vector>
#include "Sensors.h"

using namespace std;
using namespace droneonboard;

namespace droneonboard {
    vector<UltrasonicDataHandler> ultrasonic_data_handlers;
    vector<ObstacleDistanceDataHandler> obstacle_distance_data_handlers;

    int on_board_event_handler(int data, int len, char *content) {
        switch (data) {
            case e_ultrasonic:
                for (int i = 0; i < ultrasonic_data_handlers.size(); i++) {
                    ultrasonic_data_handlers[i]((ultrasonic_data *) content);
                }
                break;

            case e_obstacle_distance:
                for (int i = 0; i < obstacle_distance_data_handlers.size(); i++) {
                    obstacle_distance_data_handlers[i]((obstacle_distance *) content);
                }
                break;
        }

        return 0;
    }
}

void Sensors::Connect() {
    set_sdk_event_handler(&on_board_event_handler);
    start_transfer();
}

void Sensors::Disconnect() {
    stop_transfer();
    release_transfer();
}

void Sensors::OnUltrasonicData(UltrasonicDataHandler handler) {
    if (ultrasonic_data_handlers.size() == 0)
        select_ultrasonic();

    ultrasonic_data_handlers.push_back(handler);
}

void Sensors::OnObstacleDistance(ObstacleDistanceDataHandler handler) {
    if (obstacle_distance_data_handlers.size() == 0)
        select_obstacle_distance();

    obstacle_distance_data_handlers.push_back(handler);
}
