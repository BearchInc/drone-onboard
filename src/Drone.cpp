#include "Drone.h"

using namespace droneonboard;

void Drone::Connect() { }
void Drone::Disconnect() { }

string Drone::Say(string name)
{
    return "Hello " + name;
};