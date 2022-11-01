//drone.cc
/**
 * @file drone.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/ 
#include "drone.h"
#include "movement.h"
/*******************************************************************************
 * Member Functions
 ******************************************************************************/ 
Drone::Drone()
{
	speed = 0.0;
	movement = nullptr;
	totalDistance = 0.0;
}


Drone::Drone(picojson::object EntityData)
{
	speed = EntityData["speed"].get<double>();
	movement = nullptr;
	totalDistance = 0.0;

}
Drone::~Drone()
{
	delete movement;
}

std::string Drone::getType()
{
	std::string myType = "Drone";
	return myType;
}

void Drone::Update(double dt)
{	
	Vector3 newPosition;
	// If the "p" key is pressed then switch the movement type to patrol

	// If the "m" key is pressed then switch the movement type to manual

	if(movementType == "patrol")
	{	
		// Set the movement pointer to a patrol object
		movement = new PatrolMovement;
	}
	totalDistance += dt;
	 if (pos == rechargeLocation->getPosition()) {}
	// {
	// 	battery.level = 100;
	// 	movementType = "patrol";
	// }
	// else if (battery.level <= 10)
	//{
		//setMovementType(beeline);
	//}
	
	// Check if the movement pattern is set to beeline
	else if(movementType == "beeline")
	{
		//if (battery.level <= 10)
		//{
			//update to move to rechargeLocation
			//beeline.movementPattern( dt, pos, rechargeLocation->pos);
		//}

		// Set the movement pointer to a beeline object
		movement = new BeelineMovement(newPosition);
		
	}
	if(movementType == "manual")
	{
		// Set the movement pointer to a manual object
		//movement = new ManualMovement();
	}
	
	// Call the current movement pattern
	movement->movementPattern(dt, *pos, *dir);
	
	Logger::Instance().Log(totalDistance);
}

void Drone::setMovementType(std::string movementType)
{
	this->movementType = movementType;
}

void Drone::setRecharge (Entity * recharge)
{
	rechargeLocation = recharge;
}

Entity * Drone::getRecharge ()
{
	return rechargeLocation;
}
