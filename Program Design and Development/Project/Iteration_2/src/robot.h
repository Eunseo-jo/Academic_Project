//robot.h
#ifndef ROBOT_H_
#define ROBOT_H_

#include "entity.h"
#include <picojson.h>


class Robot : public Entity 
{
	public:
		Robot();
		Robot(picojson::object EntityData);
		~Robot();
		virtual std::string getType();
};

#endif
