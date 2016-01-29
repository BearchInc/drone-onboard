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
    dji.Connect();

    getchar();
    dji.TakeOff();
	return 0;
}