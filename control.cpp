#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

static int hello_world()
{
	printf("hello world");
	return 0;
}