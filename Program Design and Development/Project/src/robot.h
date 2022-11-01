//robot.h
#ifndef ROBOT_H_
#define ROBOT_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include "entity.h"
#include <picojson.h>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Robot Class is is a subclass of entity that instantiates robots which in this simulation are the "victims" for the drone to find
 */ 
class Robot : public Entity 
{
	public:
		/**
		* @brief Constructor for the robot class, instantiates robots at pos (0,0,0), direction (0,0,0) and id = 0, should not be practically used
		*
		* @return none
		*/ 
		Robot();
		/**
		* @brief Constructor for the robot class, instantiates robots with a given postion, direction and ID provided by the JSON input file
		*
		* @return none
		*/ 
		Robot(picojson::object EntityData);
		/**
		* @brief Destructor for the robot class, does nothing
		*
		* @return none
		*/ 
		~Robot();
		/**
		* @brief getType is mainly for testing purposes, to determine what entity is returned (in this case always a robot)
		*
		* @return string "robot"
		*/ 
		virtual std::string getType();

		virtual void Update(double dt) {}

};

#endif
