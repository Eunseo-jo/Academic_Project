//entity.h
#ifndef ENTITY_H_
#define ENTITY_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include <string>
#include <picojson.h>
#include "vector3.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Kernel Class is used by many filters to get a small set of pixels surronding any given pixel
 */ 

class Entity 
{
	public:
		/**
		* @brief Constructor for the entity class, instantiates entities at pos (0,0,0), direction (0,0,0) and id = 0, should not be practically used
		*
		* @return none
		*/
		 Entity();
		/**
		* @brief Constructor for the entity class, instantiates entites with a given postion, direction and ID provided by the JSON input file
		*
		* @return none
		*/ 
		Entity(picojson::object EntityData);
		/**
		* @brief Destructor for the entity class, does nothing
		*
		* @return none
		*/
		~Entity();
		/**
		* @brief getType is mainly for testing purposes, to determine what entity is returned (in this case always a entity)
		*
		* @return string "entity"
		*/ 
		virtual std::string getType();

		virtual void Update (double dt){}

		Vector3 * getPosition();
		/**
		* @brief getDirection is used to access an entity's direction
		*
		* @return Vector3 of the direction
		*/ 
		Vector3 * getDirection();
		double getID();
	protected:
		Vector3 * pos;
		Vector3 * dir;
		double id;
};

#endif
