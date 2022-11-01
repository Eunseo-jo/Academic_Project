#ifndef BEELINE_MOVEMENT_H_
#define BEELINE_MOVEMENT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include <cmath>
#include "movement.h"

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Beeline Movement: this is a movement pattern to make an entity head 
 * directly to a desired position
 */

class BeelineMovement : public Movement
{
    public:
    /**
	  * @brief Constructor for the beeline movement class
	  *
	  * @return 
	*/ 
        BeelineMovement();
    /**
	  * @brief This is beeline's movement pattern function
	  *
	  * @return void
	*/ 
        void movementPattern(Drone* drone, double dt, double position[3]);
};

#endif