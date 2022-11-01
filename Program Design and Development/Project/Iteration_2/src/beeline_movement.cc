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
// Is this necessary? Can the function be called without an object?
BeelineMovement::BeelineMovement() {}

// Beeline movement pattern
// Should I add position3 and Vector3 classes?
void BeelineMovement::movementPattern(Drone* drone, double dt, double position[3])
{
    double direction[3];
    double directionMagnitude;
    double velocity[3];
    double distanceTraveled[3];

    // Calculate direction
    direction[0] = position[0] - drone->GetXPos();
    direction[1] = position[1] - drone->GetYPos();
    direction[2] = position[2] - drone->GetZPos();

    // Normalize the direction
    directionMagnitude = sqrt((direction[0] * direction[0]) + (direction[1] * direction[1]) + (direction[2] * direction[2]));
    direction[0] = direction[0] / directionMagnitude;
    direction[1] = direction[1] / directionMagnitude;
    direction[2] = direction[2] / directionMagnitude;

    // Calculate the velocity of the drone
    velocity[0] = direction[0] * drone->GetSpeed();
    velocity[1] = direction[1] * drone->GetSpeed();
    velocity[2] = direction[2] * drone->GetSpeed();

    // Calculate the distance traveled over this time step
    distanceTraveled[0] = velocity[0] * dt;
    distanceTraveled[1] = velocity[1] * dt;
    distanceTraveled[2] = velocity[2] * dt;

    // Move the drone using Eularian integration
    drone->UpdateDirection(direction);
    drone->UpdatePosition(distanceTraveled);

}
