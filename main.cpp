#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "control.h"

int main(int argc,char **argv) {
	if (Pro_Hw_Setup("/dev/ttyAMA0", 230400) < 0) {
		perror("UAV Serial Port Open ERROR");
		return 0;
	}

	DJI_Pro_Setup(&onSetup);

	while (true) {
		int option = getchar();

		switch (option) {
			case 'a':
				printf("###### about to activate user...\n");
				activate_data_t user_data = ActivateUser(&onActivate);
				break;
		}
	}
}
