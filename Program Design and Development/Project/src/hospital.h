//hospital.h
#ifndef HOSPITAL_H_
#define HOSPITAL_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include "entity.h"
#include <picojson.h>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Kernel Class is used by many filters to get a small set of pixels surronding any given pixel
 */ 

class Hospital: public Entity 
{
	public:
		/**
		* @brief Constructor for the hospital class, instantiates hospitals at pos (0,0,0), direction (0,0,0) and id = 0, should not be practically used
		*
		* @return none
		*/
		Hospital();
		/**
		* @brief Constructor for the hospital class, instantiates hospitals with a given postion, direction and ID provided by the JSON input file
		*
		* @return none
		*/ 
		Hospital(picojson::object EntityData);
		/**
		* @brief Destructor for the hospital class, does nothing
		*
		* @return none
		*/
		~Hospital();
		/**
		* @brief getType is mainly for testing purposes, to determine what entity is returned (in this case always a hospital)
		*
		* @return string "hospital"
		*/ 
		virtual std::string getType();
		virtual void Update(double dt) {}


};

#endif
