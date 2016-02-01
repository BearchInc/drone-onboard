#include "Sensors.h"
#include "Brain.h"

using namespace droneonboard;

int main(int argc, char *argv[]) {
    Sensors sensors;
    Drone drone("/dev/ttyLOL", 2345434);

    Brain brain(drone, sensors);

    brain.Think(); // Blocks until program ends...
    return 0;
}