//Factory.h
#ifndef FACTORY_H_
#define FACTORY_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include <string>
#include <picojson.h>
#include "entity.h"
#include "drone.h"
#include "robot.h"
#include "hospital.h"
#include "rechargeStation.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief EntityFactory Class is an abstract class used to instantiate various entities, calls on factory subclasses to create each specific kind
 */ 
class EntityFactory 
{
	public:
		/**
		* @brief Constructor for the EntityFactory class, does nothing
		*
		* @return none
		*/
		EntityFactory();
		/**
		* @brief virtual function createEntity will call the specified type of factory based on parameter type in order to create the correct type of entity
		*
		* @return Entity of type Entity based on default construtor
		*/
		virtual Entity * createEntity (std::string type);
		/**
		* @brief virtual function createEntity will extract the name of the entity (aka its type) and create an entity based off that type
		* 
		* @return Entity of type Entity based on JSON construtor
		*/
		virtual Entity * createEntity (picojson::object EntityData);
};
/**
 * @brief DroneFactory Class is a subclass of EntityFactory used to instantiate drones
 */ 
class DroneFactory : public EntityFactory
{
	public:
		/**
		* @brief Constructor for the DroneFactory class, does nothing
		*
		* @return none
		*/
		DroneFactory();
		/**
		* @brief virtual function createEntity will calls the default constructor for Drone to make a new Drone
		*
		* @return Entity of type Drone based on default construtor
		*/
		virtual Entity * createEntity ();
		/**
		* @brief virtual function createEntity will calls the JSON constructor for Drone to make a new Drone
		*
		* @return Entity of type Drone based on JSON construtor
		*/
		virtual Entity * createEntity (picojson::object EntityData);
};
/**
 * @brief RobotFactory Class is a subclass of EntityFactory used to instantiate robots
 */ 
class RobotFactory : public EntityFactory 
{
	public:
		/**
		* @brief Constructor for the RobotFactory class, does nothing
		*
		* @return none
		*/
		RobotFactory();
		/**
		* @brief virtual function createEntity will calls the default constructor for Robot to make a new Robot
		*
		* @return Entity of type Robot based on default construtor
		*/
		virtual Entity * createEntity();
		/**
		* @brief virtual function createEntity will calls the JSON constructor for Robot to make a new Robot
		*
		* @return Entity of type Robot based on JSON construtor
		*/
		virtual Entity * createEntity (picojson::object EntityData);
		
};
/**
 * @brief HospitalFactory Class is a subclass of EntityFactory used to instantiate hospitals
 */ 
class HospitalFactory : public EntityFactory 
{
	public:
		/**
		* @brief Constructor for the HospitalFactory class, does nothing
		*
		* @return none
		*/
		HospitalFactory();
		/**
		* @brief virtual function createEntity will calls the default constructor for Hospital to make a new Hospital
		*
		* @return Entity of type Hospital based on default construtor
		*/
		virtual Entity * createEntity();
		/**
		* @brief virtual function createEntity will calls the JSON constructor for Hospital to make a new Hospital
		*
		* @return Entity of type Hospital based on JSON construtor
		*/
		virtual Entity * createEntity(picojson::object EntityData);
		
};
/**
 * @brief RechargeStationFactory Class is a subclass of EntityFactory used to instantiate recharge stations
 */ 
class RechargeStationFactory : public EntityFactory 
{
	public:
		/**
		* @brief Constructor for the RechargeStationFactory class, does nothing
		*
		* @return none
		*/
		RechargeStationFactory();
		/**
		* @brief virtual function createEntity will calls the default constructor for RechargeStation to make a new RechargeStation
		*
		* @return Entity of type RechargeStation based on default construtor
		*/
		virtual Entity * createEntity();
		/**
		* @brief virtual function createEntity will calls the JSON constructor for RechargeStation to make a new RechargeStation
		*
		* @return Entity of type RechargeStation based on JSON construtor
		*/
		virtual Entity * createEntity (picojson::object EntityData);
		
};

#endif
