#include "Sensors.h"
#include "Brain.h"

using namespace droneonboard;

int main(int argc, char *argv[]) {
    DJIAccount account("123123", "ASdf34SDf345Dfgh");
    Drone drone("/dev/ttyLOL", 2345434, account);
    Brain brain(drone, Sensors());

    brain.WakeUp(); // Blocks until program ends...
    return 0;
}