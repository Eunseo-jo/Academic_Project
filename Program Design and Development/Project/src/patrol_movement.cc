/**
 * @file patrol_movement.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "patrol_movement.h"
#include "movement.h"

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
 // Constructor
 PatrolMovement::PatrolMovement() {}

 void PatrolMovement::movementPattern(double dt, Vector3& position, Vector3& direction)
 {  
    //double velocity;
    Vector3 velocity;
    Vector3 distanceTraveled;
    double speed = 4.0;


    // Create a set of points for the corners of the movement pattern
    vector<Vector3> points = {Vector3(1000.0, 264.0, 800.0), Vector3(1000.0, 264.0, -800.0), Vector3(-1000.0, 264.0, -800.0), Vector3(-1000.0, 264.0, 800.0)};

    // Move drone to first point (1000, 264, 800)
    while(position != points[0])
    {
        direction = points[0] - position;
        direction.Normalize();
        velocity = direction * speed;
        distanceTraveled = velocity * dt;
        position = position + distanceTraveled;
    }

    // Move drone to second point (1000, 264, -800)
    while(position != points[1])
    {
        direction = points[1] - position;
        direction.Normalize();
        velocity = direction * speed;
        distanceTraveled = velocity * dt;
        position = position + distanceTraveled;
    }

    // Move drone to third point (-1000, 264, -800)
    while(position != points[2])
    {
        direction = points[2] - position;
        direction.Normalize();
        velocity = direction * speed;
        distanceTraveled = velocity * dt;
        position = position + distanceTraveled;
    }

    // Move drone to fourth point (-1000, 264, 800)
    while(position != points[3])
    {
        direction = points[3] - position;
        direction.Normalize();
        velocity = direction * speed;
        distanceTraveled = velocity * dt;
        position = position + distanceTraveled;
    }

    // Move drone to fifth point (1000, 264, 800)
    while(position != points[0])
    {
        direction = points[0] - position;
        direction.Normalize();
        velocity = direction * speed;
        distanceTraveled = velocity * dt;
        position = position + distanceTraveled;
    }
    
 }