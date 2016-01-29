#pragma once

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>	

#include "DJI_Pro_Hw.h"
#include "DJI_Pro_Rmu.h"
#include "DJI_Pro_App.h"
#include "DJI_Pro_Link.h"
#include "DJI_Pro_Codec.h"
#include "DJI_Pro_Config.h"

#include "brain.h"

class Drone
{
private:
    static void RequestControl();
public:
    //activate
    //open serial
    //take control
    //connect brain
    bool Connect(int app_id, char* key);
    //release control
    //disconnect brain
    bool Disconnect();
    Drone(Brain);
    bool TakeOff();
    bool Land();
    void MoveBack();
    void MoveFoward();
    void MoveRight();
    void MoveLeft();

};
