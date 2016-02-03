#pragma once

#include <functional>
#include <vector>

namespace guidance {
    typedef std::function<void(ultrasonic_data *data)> UltrasonicDataListener;
    typedef std::function<void(obstacle_distance *data)> ObstacleDistanceDataListener;

    int EventHandler(int data, int len, char *content);
    void AddUltrasonicDataListener(UltrasonicDataListener);
    void AddObstacleDistanceDataListener(ObstacleDistanceDataListener);
}
