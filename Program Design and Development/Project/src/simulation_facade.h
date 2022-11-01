#ifndef SIMULATION_FACADE_H_
#define SIMULATION_FACADE_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/ 

#include <picojson.h>
#include "WebServer.h"
#include "Factory.h"
#include "entity.h"
#include <vector>


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the facade class for the simulation.
 */ 
class simulation_facade
{
  public:
    /**
		* @brief function createEntity based on JSON data stored as an object.
		*
		* @return None.
	
    */
    void CreateEntity(picojson::object& entityData);
    /**
		* @brief function Update about entity by the time passed.
		*
		* @return None.
	
    */
    void Update(double dt);
    /**
		* @brief function FinishUpdate called after all entity's updating is done. Entity should be returned to the UI.
		*
		* @return None.
	
    */
    void FinishUpdate(picojson::object& returnValue);

    protected:
      Entity *new_entity;
      std::vector<Entity*> VecEntity;
      EntityFactory* create_entity;

};

#endif
