#include <iostream>
#include <DJI_Pro_Hw.h>
#include "Drone.h"

using namespace std;

int main(int argc, char *argv[]) {
    Pro_Hw_Setup("lol", 123);

    Drone drone;

    cout << drone.Greet("Diego") << endl;
    return 0;
}