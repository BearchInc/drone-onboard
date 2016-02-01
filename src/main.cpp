#include <iostream>
#include <DJI_Pro_Hw.h>

#include "Drone.h"

using namespace std;
using namespace droneonboard;

int main(int argc, char *argv[]) {
    Pro_Hw_Setup("lol", 123);

    Drone drone;

    cout << "Hello Lisardinho <3" << endl;
    return 0;
}