# TODO
# Make sure we can run on linux

cmake_minimum_required(VERSION 3.3)
project(DroneOnboard)

set(CMAKE_CXX_COMPILER "/usr/local/linaro/arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Add libs directory to the lib search path
link_directories(libs)

# Add libs include files to the include search path
include_directories(
        libs/includes
        src/libcore/includes)

# Add cmake submodules configurations
add_subdirectory(src/libdji)
add_subdirectory(src/libcore)

add_executable(DroneOnboard main.cpp)

target_link_libraries(DroneOnboard core)
