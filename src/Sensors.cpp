#include "Sensors.h"

using namespace std;
using namespace droneonboard;

void Sensors::Connect() {
    set_sdk_event_handler(&guidance::EventHandler);
    start_transfer();
}

void Sensors::Disconnect() {
    stop_transfer();
    release_transfer();
}

void Sensors::OnUltrasonicData(guidance::UltrasonicDataListener listener) {
    guidance::AddUltrasonicDataListener(listener);
}

void Sensors::OnObstacleDistance(guidance::ObstacleDistanceDataListener listener) {
    guidance::AddObstacleDistanceDataListener(listener);
}
