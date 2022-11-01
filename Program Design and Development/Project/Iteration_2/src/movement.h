#ifndef MOVEMENT_H_
#define MOVEMENT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

//TODO: Add all necessary includes
#include "drone.h"
#include "entity.h"

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The interface class for movement
 */ 

class Movement
{
    public:
    /**
	  * @brief This a virtual function for the movement pattern of an entity
	  *
	  * @return void
	*/ 
        virtual void movementPattern(Drone* drone, double dt, double position[3]) = 0;
};

#endif