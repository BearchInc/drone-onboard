//
// Created by Diego Borges on 2/1/16.
//

#include <iostream>
#include <wiringPi.h>
#include "Brain.h"

using namespace std;
using namespace droneonboard;

void Brain::Think() {
    // TODO implement AI...

    sensors.OnData([&](int data, int len, char* content) {
        cout << drone.Greet("Mah Oe... Lisardinho") << endl;
    });

    while(1) delay(500);
}