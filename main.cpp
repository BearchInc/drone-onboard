#include <iostream>
#include <stdio.h>
#include <string.h>
#include "control.h"

int main(int argc,char **argv)
{
	hello_world();
	int activation_result = ActivateUser();
	printf("Account creation response: %d\n", activation_result);
	return 0;
}