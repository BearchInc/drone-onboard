#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "control.h"

int main(int argc,char **argv)
{

	int main_operate_code = 0;
	int temp32 = 0;
	bool valid_flag = false;

	// printf("Opening serial port...");
	// if (OpenSerialPort() < 0) {
	// 	perror("UAV Serial Port Open ERROR\n");
	// 	return 0;
	// }
	


	while (1) {

		temp32 = getchar();
		if(temp32 != 10) {
			if(valid_flag == false)
			{
				main_operate_code = temp32;
				valid_flag = true;
			} else {

			}
			continue;
		}
		switch(main_operate_code)
		{
			case 'a':
			printf("Activating user...\n");
			ActivateUser();
			break;
			case 'b':
			printf("Requesting control...\n");
			RequestControl();
			break;
			case 'c':
			printf("Taking off...\n");
			TakeOff();
			break;
			case 'd':
			printf("Landing...\n");
			Land();
			break;
			
		}
		main_operate_code = -1;
		valid_flag = false;	
	}
	return 0;
}
