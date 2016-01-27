cmake_minimum_required(VERSION 3.3)
project(drone_onboard)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    DJI_LIB/DJI_Pro_App.cpp
    DJI_LIB/DJI_Pro_App.h
    DJI_LIB/DJI_Pro_Codec.cpp
    DJI_LIB/DJI_Pro_Codec.h
    DJI_LIB/DJI_Pro_Config.h
    DJI_LIB/DJI_Pro_Hw.cpp
    DJI_LIB/DJI_Pro_Hw.h
    DJI_LIB/DJI_Pro_Link.cpp
    DJI_LIB/DJI_Pro_Link.h
    DJI_LIB/DJI_Pro_Rmu.cpp
    DJI_LIB/DJI_Pro_Rmu.h
    libs/includes/wiringPi.h
    libs/includes/wiringPiI2C.h
    libs/includes/wiringPiSPI.h
    control.cpp
    control.h
    main.cpp)

add_executable(drone_onboard ${SOURCE_FILES})