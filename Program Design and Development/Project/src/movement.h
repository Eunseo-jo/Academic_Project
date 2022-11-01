#ifndef MOVEMENT_H_
#define MOVEMENT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "vector3.h"

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
        virtual void movementPattern(double dt, Vector3& position, Vector3& direction) = 0;
};

#endif