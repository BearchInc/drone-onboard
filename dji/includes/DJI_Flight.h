#ifndef DJI_FLIGHT_H
#define DJI_FLIGHT_H

#include "DJI_API.h"

namespace DJI
{
namespace onboardSDK
{

class Flight
{
public:

  public:
    Flight(CoreAPI *ContorlAPI = 0);

    void task(TASK taskname, CallBack TaskCallback = 0);
    void setArm(bool enable, CallBack ArmCallback = 0);
    void setFlight(FlightData *data);

    QuaternionData getQuaternion() const;
    PossitionData getPossition()const;
    VelocityData getVelocity() const;
    CommonData getAcceleration() const;
    CommonData getPalstance() const;
    MagnetData getMagnet() const;

  public: //! @note callbacks
    static void armCallback(CoreAPI *This, Header *header);
    static void taskCallback(CoreAPI *This, Header *header);

  public: //! @note Access method
    CoreAPI *getApi() const;
    void setApi(CoreAPI *value);

  private:
    CoreAPI *api;
    TaskData taskData;
};

} // namespace onboardSDK
} // namespace DJI

#endif // DJI_FLIGHT_H