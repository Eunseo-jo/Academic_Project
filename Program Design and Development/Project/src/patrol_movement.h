#ifndef PATROL_MOVEMENT_H_
#define PATROL_MOVEMENT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include "movement.h"
#include <vector>

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Patrol Movement: this is the movement patern used by the drone while it is 
 searching for the robot
 */

class PatrolMovement : public Movement
{
    public:
    /**
	  * @brief Constructor for the patrol movement class
	  *
	  * @return 
	*/ 
        PatrolMovement();
    /**
	  * @brief This is patrol's movement pattern function
	  *
	  * @return void
	*/ 
        void movementPattern(double dt, Vector3& position, Vector3& direction);
};

#endif