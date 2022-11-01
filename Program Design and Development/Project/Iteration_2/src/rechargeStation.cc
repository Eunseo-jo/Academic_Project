//robot.cc
#include "rechargeStation.h"

RechargeStation::RechargeStation()
{

}

RechargeStation::RechargeStation(picojson::object EntityData)
{

}

RechargeStation::~RechargeStation()
{
	
}

std::string RechargeStation::getType()
{
	std::string myType = "Robot";
	return myType;
}
