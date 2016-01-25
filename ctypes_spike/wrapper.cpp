#include <iostream>
#include <string.h>

extern "C" void hello(char * message)
{
    std::cout << "Hello " << message << std::endl;
}