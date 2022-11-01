//entity.cc
#include "entity.h"
Entity::Entity() 
{
	pos[0] = 0.0;
	pos[1] = 0.0;
	pos[2] = 0.0;
	
	dir[0] = 0.0;
	dir[1] = 0.0;
	dir[2] = 0.0;
	
	id = 0.0;
}



Entity::~Entity()
{
	
}

Entity::Entity(picojson::object EntityData)
{
	picojson::value val(EntityData);

	id = EntityData["entityId"].get<double>();

	picojson::array position = EntityData["position"].get<picojson::array>();
	pos[0] = position[0].get<double>();
	pos[1] = position[1].get<double>();
	pos[2] = position[1].get<double>();

	// Get the direction as an array
	picojson::array direction = EntityData["direction"].get<picojson::array>();
	dir[0] = direction[0].get<double>();
	dir[1] = direction[1].get<double>();
	dir[2] = direction[1].get<double>();

}

std::string Entity::getType()
{
	std::string myType = "Entity";
	return myType;
}
