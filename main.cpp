#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wiringPi.h>
#include <DJI_guidance.h>

#include "models/Lock.h"
#include "control.h"
#include "models/brain.h"
#include "models/drone.h"

using namespace std;

int main(int argc, char **argv)
{

	Drone dji;
    char key[] = "f28973098ca26058f1c2a81676a49e48fad27a4703728811ffb612526087a2e0";
    dji.Connect(1024746, key);

    getchar();
    dji.TakeOff();
	return 0;
}