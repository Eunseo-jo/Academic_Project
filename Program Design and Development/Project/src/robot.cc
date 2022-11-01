//robot.cc
/**
 * @file robot.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/ 
#include "robot.h"
/*******************************************************************************
 * Member Functions
 ******************************************************************************/ 
Robot::Robot()
{
	// pos[0] = 0.0;
	// pos[1] = 0.0;
	// pos[2] = 0.0;
	
	// dir[0] = 0.0;
	// dir[1] = 0.0;
	// dir[2] = 0.0;
	
	// id = 0.0;
}

Robot::Robot(picojson::object EntityData)
{
  	// int id = static_cast<int>(o.find["entityId"]->second.get<double>());
  	// picojson::array arr = o.find["position"]->second.get<picojson::array>();
	// std::vector<float> position = {0, 0, 0};
	// for (int i = 0; i < arr.size(); i++) {
    // position.at(i) = static_cast<float>(arr[i].get<double>());
	// }
	// picojson::value val(EntityData);
	// id = static_cast<double>(EntityData.find["entityId"]->second.get<double>());
	// //speed = EntityData.find["speed"].->second.get<float>();
	// // Get the position as an array
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

// 	picojson::value val(EntityData);
// 	id = EntityData["entityId"].get<double>();
// 	// Get the position as an array
// 	picojson::array position = EntityData["position"].get<picojson::array>();
// 	pos[0] = position[0].get<double>();
// 	pos[1] = position[1].get<double>();
// 	pos[2] = position[1].get<double>();

// 	// Get the direction as an array
// 	picojson::array direction = EntityData["direction"].get<picojson::array>();
// 	dir[0] = direction[0].get<double>();
// 	dir[1] = direction[1].get<double>();
// 	dir[2] = direction[1].get<double>();
 }


Robot::~Robot()
{
	
}

std::string Robot::getType()
{
	std::string myType = "Robot";
	return myType;
}
