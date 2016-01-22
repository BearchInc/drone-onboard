
#ifndef ONBOARD_CONTROL_H_
#define ONBOARD_CONTROL_H_

#include "DJI_LIB/DJI_Pro_Codec.h"
#include "DJI_LIB/DJI_Pro_Hw.h"
#include "DJI_LIB/DJI_Pro_Link.h"
#include "DJI_LIB/DJI_Pro_App.h"
#include "DJI_LIB/DJI_Pro_Config.h"
#include "DJI_LIB/DJI_Pro_Rmu.h"

#define MAKE_VERSION(a,b,c,d) (((a << 24)&0xff000000) | ((b << 16)&0x00ff0000) | ((c << 8)&0x0000ff00) | (d&0x000000ff))
#define SDK_VERSION           (MAKE_VERSION(2,3,10,0))

void hello_world(void);
int ActivateUser(void);

#endif