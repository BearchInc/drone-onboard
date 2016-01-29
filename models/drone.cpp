#include <iostream>
#include <unistd.h>
#include "drone.h"

using namespace std;

Drone::Drone()
{
    cout << "Object is being created" << endl;
}

char port_name[32] = {"/dev/ttyAMA0"};
bool OpenSerialPort() {
	cout << "Openning serial port" << endl;
	int baudrate = 230400;
    
    if (Pro_Hw_Setup(port_name, baudrate) < 0) {
    	cout << "Failed to serial port" << endl;
        return true;
    }

    cout << "DJI Pro Setup" << endl;
    DJI_Pro_Setup(NULL);
    return false;
}

void OnActivate(unsigned short result) {
    printf("Drone activated with code: %d\n", result);
    usleep(2000000);
    cout << "Requesting control" << endl;
    DJI_Pro_Control_Management(1, NULL);
}

bool Drone::Connect(int app_id, char* key) 
{
	cout << "Connecting drone..." << endl;
	if(OpenSerialPort()) {
		return false;
	}

	cout << "Activating drone..." << endl;

	activate_data_t user_act_data;
    user_act_data.app_id = app_id;
    user_act_data.app_api_level = 2;
    strcpy((char *) user_act_data.app_key, key);
    
    DJI_Pro_Activate_API(&user_act_data, &OnActivate);
}

bool Drone::TakeOff() {
	DJI_Pro_Status_Ctrl(4, 0);
	return true;
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
