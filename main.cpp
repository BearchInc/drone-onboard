#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wiringPi.h>
#include <DJI_guidance.h>

#include "models/drone.h"

using namespace std;

int main(int argc, char **argv)
{
    Brain brain;
	Drone dji(brain);
    dji.Connect(1024746);//, "f28973098ca26058f1c2a81676a49e48fad27a4703728811ffb612526087a2e0");
	return 0;
}