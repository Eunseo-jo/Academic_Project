//entity.h
#ifndef ENTITY_H_
#define ENTITY_H_

//#include "position.h" <- remove position class
#include <string>
#include <picojson.h>
class Entity 
{
	public:
		 Entity();
		~Entity();
		 Entity(picojson::object EntityData);
		virtual std::string getType();
	protected:
		double pos[3];
		double dir[3];
		double id;
};

#endif
