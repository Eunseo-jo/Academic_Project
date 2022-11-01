#ifndef MANUAL_MOVEMENT_H_
#define MANUAL_MOVEMENT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include "movement.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Manual Movement: this is a movement pattern to make the drone move 
 * manually with keyboard input
 */

 class ManualMovement : public Movement
 {
    public:
    /**
	  * @brief Constructor for the manual movement class
	  *
	  * @return 
	*/ 
        ManualMovement();
    /**
	  * @brief This is manual's movement pattern function
	  *
	  * @return void
	*/ 
        void movementPattern(double dt, Vector3& position, Vector3& direction);
};

#endif