#include <iostream>
#include <unistd.h>
#include "drone.h"


using namespace std;

Drone::Drone()
{
    cout << "Object is being created" << endl;
}

int OpenSerialPort() {
	int baudrate = 230400;
    char port_name[32] = {"/dev/ttyAMA0"};
    if (Pro_Hw_Setup(port_name, baudrate) < 0) {
        return false;
    }

    DJI_Pro_Setup(NULL);
    return true;
}

void OnActivate(unsigned short result) {
    printf("Drone activated with code: %d\n", result);
    usleep(2000000);
    DJI_Pro_Control_Management(1, NULL);
}

bool Drone::Connect(int app_id) 
{
	if(OpenSerialPort()) {
		return false;
	}

	activate_data_t user_act_data;
    user_act_data.app_id = app_id;
    user_act_data.app_api_level = 2;
    strcpy((char *) user_act_data.app_key, "ds");
    DJI_Pro_Activate_API(&user_act_data, &OnActivate);
}

bool Drone::TakeOff() {
	return false;
}
bool Drone::Land() {
	return false;
}
void Drone::MoveBack() {

}
void Drone::MoveForward() {

}
void Drone::MoveRight() {

}
void Drone::MoveLeft() {

}
