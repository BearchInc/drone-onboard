#include "Sensors.h"
#include "Brain.h"

using namespace droneonboard;

int main(int argc, char *argv[]) {
    Drone drone;
    Sensors sensors;

    Brain brain(drone, sensors);

    brain.Think(); // Blocks until program ends...
    return 0;
}