#ifndef BEELINE_MOVEMENT_H_
#define BEELINE_MOVEMENT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include "movement.h"

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Beeline Movement: this is a movement pattern to make an entity head 
 * in a straight line to a desired position
 */
class BeelineMovement : public Movement
{
    public:
    /**
	  * @brief Constructor for the beeline movement class, takes a Vector3 as an argument
	  *
	  * @return 
	*/ 
        BeelineMovement(Vector3 targetPosition);

    /**
	  * @brief This is beeline's movement pattern function
	  *
	  * @return void
	*/ 
        void movementPattern(double dt, Vector3& position, Vector3& direction);

	private:
		Vector3 targetPosition;
};

#endif