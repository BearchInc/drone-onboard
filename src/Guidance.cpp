#include <DJI_guidance.h>
#include "guidance.h"

using namespace std;

/*
 * Glue code to hook up DJI guidance SDK with droneonboard API.
 */
namespace guidance {
    vector<UltrasonicDataListener> ultrasonic_data_listeners;
    vector<ObstacleDistanceDataListener> obstacle_distance_listeners;

    void AddUltrasonicDataListener(UltrasonicDataListener listener)
    {
        if (ultrasonic_data_listeners.size() == 0)
            select_ultrasonic();

        ultrasonic_data_listeners.push_back(listener);
    }

    void AddObstacleDistanceDataListener(ObstacleDistanceDataListener listener)
    {
        if (obstacle_distance_listeners.size() == 0)
            select_obstacle_distance();

        obstacle_distance_listeners.push_back(listener);
    }

    int EventHandler(int data, int len, char *content) {
        switch (data) {
            case e_ultrasonic:
                for (int i = 0; i < ultrasonic_data_listeners.size(); i++) {
                    ultrasonic_data_listeners[i]((ultrasonic_data *) content);
                }
                break;

            case e_obstacle_distance:
                for (int i = 0; i < obstacle_distance_listeners.size(); i++) {
                    obstacle_distance_listeners[i]((obstacle_distance *) content);
                }
                break;
        }

        return 0;
    }
}
