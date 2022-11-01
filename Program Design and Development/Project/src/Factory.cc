//Factory.cc
/**
 * @file Factory.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/ 
#include "Factory.h"
#include <string>
#include <picojson.h>
/*******************************************************************************
 * Member Functions
 ******************************************************************************/ 
EntityFactory::EntityFactory(){}

Entity * EntityFactory::createEntity (std::string type)
{
	Entity * entity;
	DroneFactory dFactory; 
	RobotFactory rFactory;	
	HospitalFactory hFactory;
	RechargeStationFactory rsFactory;
	
	if (type == "drone")
	{
		entity =  dFactory.createEntity();
	}
	else if (type ==  "robot")
	{
		entity =  rFactory.createEntity();
	}
	else if (type ==  "hospital")
	{
		entity =  hFactory.createEntity();
	}
	else if (type ==  "recharge station")
	{
		entity =  rsFactory.createEntity();
	}
		
	return entity;
}


Entity * EntityFactory::createEntity (picojson::object EntityData)
{
	Entity * entity = nullptr;
	DroneFactory dFactory; 
	RobotFactory rFactory;	
	HospitalFactory hFactory;
	RechargeStationFactory rsFactory;

	auto name = EntityData["name"];
	std::string entityName = name.get<std::string>();

    if ( entityName == "drone") 
    {
		entity = dFactory.createEntity(EntityData);
	}
    else if (entityName == "robot") 
    {
		entity = rFactory.createEntity(EntityData);
	}
    else if (entityName == "hospital")
    {
		entity = hFactory.createEntity(EntityData);
	}
	else if (entityName == "recharge station")
	{
		entity = rsFactory.createEntity(EntityData);
	}
	return entity;
}
/////////////////////////// Drone /////////////////////////////////
DroneFactory::DroneFactory(){}

Entity * DroneFactory::createEntity ()
{
	return new Drone();
}
Entity * DroneFactory:: createEntity (picojson::object EntityData)
{
	return new Drone (EntityData);
}
/////////////////////////// Robot /////////////////////////////////
RobotFactory::RobotFactory(){}

Entity * RobotFactory::createEntity ()
{
	return new Robot();
}
Entity * RobotFactory::createEntity (picojson::object EntityData)
{
	return new Robot (EntityData);	 
}
/////////////////////////// Hospital /////////////////////////////////
HospitalFactory::HospitalFactory(){}

Entity * HospitalFactory::createEntity ()
{
	return new Hospital();
}
Entity * HospitalFactory:: createEntity (picojson::object EntityData)
{
	return new Hospital (EntityData);
}
/////////////////////////// Recharge Station /////////////////////////////////
RechargeStationFactory::RechargeStationFactory(){}

Entity * RechargeStationFactory::createEntity ()
{
	return new RechargeStation();
}
Entity * RechargeStationFactory:: createEntity (picojson::object EntityData)
{
	return new RechargeStation (EntityData);
}
