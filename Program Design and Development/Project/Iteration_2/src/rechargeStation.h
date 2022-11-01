//rechargeStation.h
#ifndef RECHARGESTATION_H_
#define RECHARGESTATION_H_

#include "entity.h"
#include <picojson.h>


class RechargeStation: public Entity 
{
	public:
		RechargeStation();
		RechargeStation(picojson::object EntityData);
		~RechargeStation();
		virtual std::string getType();


};

#endif
