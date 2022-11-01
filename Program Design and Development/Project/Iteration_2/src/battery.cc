/*******************************************************************************
* Includes
******************************************************************************/
#include "battery.h"
#include <iostream>

/*******************************************************************************
 * Member Functions
******************************************************************************/
Battery::Battery()
{
    batteryLevel = 100;
}
Battery::~Battery()
{}

float Battery::getBatteryLevel() 
{
    return batteryLevel;
}

void Battery::recharge(double dt)
{
    while (batteryLevel < 100)
    {
        batteryLevel = batteryLevel + dt;
    }
}

void Battery::useBattery(double dt)
{
    while (batteryLevel > 0)
    {
        batteryLevel = batteryLevel - dt;
        
        if (batteryLevel == 20)
        {
            std::cout << "Low Battery.\n20% battery remaining " ;
        }

        if (batteryLevel == 0)
        {
            //Drone can't move
        }
    }
}

bool Battery::checkBattery()
{
    if (batteryLevel = 0) return false;
    else return true;
}
