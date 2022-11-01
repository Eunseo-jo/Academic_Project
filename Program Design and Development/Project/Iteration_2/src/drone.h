//drone.h
#ifndef DRONE_H_
#define DRONE_H_

#include "entity.h"
#include <picojson.h>

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
class Drone : public Entity {
public:
	Drone(); // done will spawn at map spot 0.0, 0.0, 0.0
	Drone(picojson::object EntityData); // new drone from json object
	~Drone();
	virtual std::string getType();

	double GetSpeed() const;
	double GetXPos() const;
	double GetYPos() const;
	double GetZPos() const;
	void UpdatePosition(double position[3]);
	void UpdateDirection(double direction[3]);

private:
	// classes to be added later
	//Battery droneBattery; 
	//Camera droneCamera;
	double speed;
	
};

#endif
