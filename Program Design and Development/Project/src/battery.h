#ifndef BATTERY_H_
#define BATTERY_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the battery class for Entity.
 */
class Battery : public Entity 
{
  public:
    /**
    * @brief Constructor for the Battery class
    *
    * @return None
    */
    Battery();
    /**
    * @brief Deconstructor for the Battery class
    *
    * @return None
    */
    ~Battery();
    /**
    * @brief Get the batteryLevel
    *
    * @return float value of battery level
    */
    float getBatteryLevel();
    /**
    * @brief Function recharges the battery
    *
    * @return none
    */
    void recharge(double dt);
    /**
    * @brief Function uses the battery by time
    *
    * @return none
    */
    void useBattery(double dt);
    /**
    * @brief Function check battery whether can move or not
    *
    * @return if entity can move return true, else false
    */
    bool checkBattery(); //Do I Need it?
  private:
    float batteryLevel;
};
#endif