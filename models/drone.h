#pragma once

//#include <iostream>
//#include <stdio.h>
//#include <unistd.h>
//#include <string.h>

//#include "DJI_Pro_App.h"
//#include "brain.h"

class Drone
{

public:
    //activate
    //open serial
    //take control
    //connect brain
    bool Connect();
    //release control
    //disconnect brain
    bool Disconnect();
    Drone();
    bool TakeOff();
    bool Land();
    void MoveBack();
    void MoveForward();
    void MoveRight();
    void MoveLeft();

};
