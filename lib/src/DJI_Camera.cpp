#include "DJI_Camera.h"

using namespace DJI::onboardSDK;

Camera::Camera(CoreAPI *ContorlAPI) { api = ContorlAPI; }

void Camera::setCamera(Camera::CAMERA_CODE camera_cmd)
{
    unsigned char send_data = 0;
    api->send(0, 1, SET_CONTROL, camera_cmd, &send_data, 1);
}

void Camera::setGimbalAngle(GimbalAngleData *data)
{
    api->send(0, 1, SET_CONTROL, Camera::CODE_GIMBAL_ANGLE,
              (unsigned char *)data, sizeof(GimbalAngleData));
}

void Camera::setGimbalSpeed(GimbalSpeedData *data)
{
    data->reserved = 0x80;
    api->send(0, 1, SET_CONTROL, Camera::CODE_GIMBAL_SPEED,
              (unsigned char *)data, sizeof(GimbalSpeedData));
}

GimbalData Camera::getGimbal() const { return api->getBroadcastData().gimbal; }

float32_t Camera::getYaw() const { return api->getBroadcastData().gimbal.yaw; }

float32_t Camera::getRoll() const
{
    return api->getBroadcastData().gimbal.roll;
}

float32_t Camera::getPitch() const
{
    return api->getBroadcastData().gimbal.pitch;
}

bool Camera::isYawLimit() const
{
    return api->getBroadcastData().gimbal.is_yaw_limit ? true : false;
}

bool Camera::isRollLimit() const
{
    return api->getBroadcastData().gimbal.is_roll_limit ? true : false;
}

bool Camera::isPitchLimit() const
{
    return api->getBroadcastData().gimbal.is_pitch_limit ? true : false;
}

CoreAPI *Camera::getApi() const { return api; }

void Camera::setApi(CoreAPI *value) { api = value; }
