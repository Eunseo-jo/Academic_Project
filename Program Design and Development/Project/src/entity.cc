//entity.cc
/**
 * @file entity.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/ 
#include "entity.h"
/*******************************************************************************
 * Member Functions
 ******************************************************************************/ 
Entity::Entity() 
{
	pos = new Vector3 ();
	dir = new Vector3 ();
	id = 0.0;
}

Entity::~Entity()
{
	delete pos;
	delete dir; 
}

Entity::Entity(picojson::object EntityData)
{
	picojson::value val(EntityData);

	id = EntityData["entityId"].get<double>();
	double x,y,z;
	picojson::array position = EntityData["position"].get<picojson::array>();
	x = position[0].get<double>();
	y = position[1].get<double>();
	z = position[1].get<double>();
	pos = new Vector3 (x,y,z);
	// Get the direction as an array
	picojson::array direction = EntityData["direction"].get<picojson::array>();
	double a,b,c;
	a = direction[0].get<double>();
	b = direction[1].get<double>();
	c = direction[1].get<double>();
	dir = new Vector3(a,b,c);

}

std::string Entity::getType()
{
	std::string myType = "Entity";
	return myType;
}

Vector3 * Entity::getPosition()
{
	return pos;
}

Vector3 * Entity::getDirection()
{
	return dir;
}

double Entity::getID()
{
	return id;
}
