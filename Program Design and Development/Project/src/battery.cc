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
Battery::~Battery(){}

float Battery::getBatteryLevel()
{
    return batteryLevel;
}

void Battery::recharge(double dt)
{
    while (batteryLevel < 100 && dt > 0)
    {
        batteryLevel++;
        dt--;
    }
}

void Battery::useBattery(double dt)
{
    while (batteryLevel > 0 && dt > 0)
    {
        batteryLevel--;
        
        if (batteryLevel == 20)
        {
            std::cout << "Low Battery.\n20% battery remaining\n" ;
        }

        if (batteryLevel == 0)
        {
            std::cout << "No Battery.\nEntity can't move\n" ;
        }

        dt--;
    }
}

bool Battery::checkBattery()
{
    if (batteryLevel = 0) return false;
    else return true;
}