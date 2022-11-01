/**
 * @file beeline_movement.cc
 *
 */
/*******************************************************************************
* Includes
******************************************************************************/
#include "beeline_movement.h"
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
// Constructor
BeelineMovement::BeelineMovement(Vector3 targetPosition) 
{
    this->targetPosition = targetPosition;
}

// Beeline movement pattern
void BeelineMovement::movementPattern(double dt, Vector3& position, Vector3& direction)
{
    //double velocity;
    Vector3 velocity;
    Vector3 distanceTraveled;
    double speed = 4.0;

    while(position != this->targetPosition)
    {
        // Calculate direction
        direction = this->targetPosition - position;

        // Normalize the direction
        direction.Normalize();

        // Calculate the velocity of the drone
        velocity = direction * speed;

        // Calculate the distance traveled over this time step
        distanceTraveled = velocity * dt;

        // Calculate new position
        position = position + distanceTraveled;
    }

}
