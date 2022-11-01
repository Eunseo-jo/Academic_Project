//drone.cc
#include "drone.h"
Drone::Drone()
{
	// pos[0] = 0.0;
	// pos[1] = 0.0;
	// pos[2] = 0.0;
	
	// dir[0] = 0.0;
	// dir[1] = 0.0;
	// dir[2] = 0.0;
	
	// id = 0.0;
	speed = 0.0;
}


Drone::Drone(picojson::object EntityData)
{

  	// int id = static_cast<int>(o.find["entityId"]->second.get<double>());
  	// picojson::array arr = o.find["position"]->second.get<picojson::array>();
	// std::vector<float> position = {0, 0, 0};
	// for (int i = 0; i < arr.size(); i++) {
    // position.at(i) = static_cast<float>(arr[i].get<double>());
	// }
	// picojson::value val(EntityData);
	// id = static_cast<double>(EntityData.find["entityId"]->second.get<double>());
	// speed = EntityData.find["speed"]->second.get<float>();
	
	// picojson::array position = EntityData.find["position"]->second.get<picojson::array>();
	// //static_cast<double>(arr[i].get<double>());
	// pos[0] = static_cast<double>(position[0].get<double>());
	// pos[1] = static_cast<double>(position[1].get<double>());
	// pos[2] = static_cast<double>(position[1].get<double>());

	// // Get the direction as an array
	// picojson::array dir = EntityData.find["direction"]->second.get<picojson::array>();
	// dir[0] = static_cast<double>(dir[0].get<double>());
	// dir[1] = static_cast<double>(dir[1].get<double>());
	// dir[2] = static_cast<double>(dir[1].get<double>());

	// picojson::value val(EntityData);
	// id = EntityData["entityId"].get<double>();
	speed = EntityData["speed"].get<double>();
	// Get the position as an array
	// picojson::array position = EntityData["position"].get<picojson::array>();

	// pos[0] = position[0].get<double>();
	// pos[1] = position[1].get<double>();
	// pos[2] = position[1].get<double>();

	// // Get the direction as an array
	// picojson::array direction = EntityData["direction"].get<picojson::array>();
	// dir[0] = direction[0].get<double>();
	// dir[1] = direction[1].get<double>();
	// dir[2] = direction[1].get<double>();

}

Drone::~Drone()
{
	
}

std::string Drone::getType()
{
	std::string myType = "Drone";
	return myType;
}

double Drone::GetSpeed()
{
	return speed;
}

double Drone::GetXPos()
{
	return xPos;
}

double Drone::GetYPos()
{
	return yPos;
}

double Drone::GetZPos()
{
	return zPos;
}

void Drone::UpdatePosition(double position[3])
{
	xPos = position[0];
	yPos = position[1];
	zPos = position[2];
}

void Drone::UpdateDirection(double direction[3])
{
	xDir = direction[0];
	yDir = direction[1];
	zDir = direction[2];
}