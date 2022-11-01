//drone.h
#ifndef DRONE_H_
#define DRONE_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include "entity.h"
#include <picojson.h>
#include "rechargeStation.h"
#include "vector3.h"
#include "logger.h"
#include "movement.h"
#include "beeline_movement.h"
#include "patrol_movement.h"
// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Kernel Class is used by many filters to get a small set of pixels surronding any given pixel
 */ 

class Drone : public Entity 
{
	public:
		/**
		* @brief Constructor for the drone class, instantiates drones at pos (0,0,0), direction (0,0,0) and id = 0, should not be practically used
		*
		* @return none
		*/
		Drone(); // done will spawn at map spot 0.0, 0.0, 0.0
		/**
		* @brief Constructor for the drone class, instantiates drones with a given postion, direction and ID provided by the JSON input file
		*
		* @return none
		*/ 
		Drone(picojson::object EntityData); // new drone from json object
		/**
		* @brief Destructor for the drone class, does nothing
		*
		* @return none
		*/
		~Drone();
		/**
		* @brief getType is mainly for testing purposes, to determine what entity is returned (in this case always a drone)
		*
		* @return string "drone"
		*/ 
		virtual std::string getType();

		// This is drone's version of update
		virtual void Update(double dt);

		// This sets the movement pattern type
		void setMovementType(std::string movementType);

		/**
		* @brief This shares the info about the recharge station with the drone
		*
		* @return none
		*/ 
		void setRecharge (Entity * recharge);
		/**
		* @brief This accesses the info about the recharge station 
		*
		* @return recharge station for drone to access
		*/ 
		Entity * getRecharge ();
	private:
		//Battery droneBattery; 
		//Camera droneCamera;
		Movement* movement;
		double speed;
		Entity * rechargeLocation;
		std::string movementType; // This stores the current movement pattern of the drone
		double totalDistance; // total distance travelled is tracked for the log

};

#endif