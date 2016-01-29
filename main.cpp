#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wiringPi.h>
#include <DJI_guidance.h>

#include "models/drone.h"

using namespace std;

char key[] = "f28973098ca26058f1c2a81676a49e48fad27a4703728811ffb612526087a2e0";
int app_id = 1024746;

int main(int argc, char **argv)
{
    Brain brain;
	Drone dji(brain);
	
    dji.Connect(app_id, key);

    getchar();
    dji.TakeOff();
	return 0;
}