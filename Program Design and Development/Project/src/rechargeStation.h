//rechargeStation.h
#ifndef RECHARGESTATION_H_
#define RECHARGESTATION_H_
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
class RechargeStation: public Entity 
{
	public:
		/**
		* @brief Constructor for the recharge stations class, instantiates recharge stations at pos (0,0,0), direction (0,0,0) and id = 0, should not be practically used
		*
		* @return none
		*/
		RechargeStation();
		/**
		* @brief Constructor for the recharge station class, instantiates recharge staitons with a given postion, direction and ID provided by the JSON input file
		*
		* @return none
		*/ 
		RechargeStation(picojson::object EntityData);
		/**
		* @brief Destructor for the recharge station class, does nothing
		*
		* @return none
		*/
		~RechargeStation();
		/**
		* @brief getType is mainly for testing purposes, to determine what entity is returned (in this case always a recharge station)
		*
		* @return string "recharge station"
		*/ 
		virtual std::string getType();
		/**
		* @brief getRechargeLocation returns the position array of the recharge station to the drone
		*
		* @return Vector3 position vector of recharge location's location
		*/ 


		virtual void Update(double dt);

};

#endif
