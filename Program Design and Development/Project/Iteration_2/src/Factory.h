//Factory.h
#ifndef FACTORY_H_
#define FACTORY_H_

#include <string>
#include <picojson.h>
#include "entity.h"
#include "drone.h"
#include "robot.h"
#include "hospital.h"
#include "rechargeStation.h"


class EntityFactory 
{
	public:
		EntityFactory();
		virtual Entity * createEntity (std::string type);
		virtual Entity * createEntity (picojson::object EntityData);
};

class DroneFactory : public EntityFactory
{
	public:
		DroneFactory();
		virtual Entity * createEntity ();
		virtual Entity * createEntity (picojson::object EntityData);
};

class RobotFactory : public EntityFactory 
{
	public:
		RobotFactory();
		virtual Entity * createEntity();
		virtual Entity * createEntity (picojson::object EntityData);
		
};

class HospitalFactory : public EntityFactory 
{
	public:
		HospitalFactory();
		virtual Entity * createEntity();
		virtual Entity * createEntity(picojson::object EntityData);
		
};

class RechargeStationFactory : public EntityFactory 
{
	public:
		RechargeStationFactory();
		virtual Entity * createEntity();
		virtual Entity * createEntity (picojson::object EntityData);		
};

#endif
