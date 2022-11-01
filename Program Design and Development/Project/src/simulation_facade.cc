/*******************************************************************************
* Includes
******************************************************************************/ 
#include "simulation_facade.h"
#include "web_app.h"
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void simulation_facade::CreateEntity(picojson::object& entityData) {
  VecEntity.push_back(create_entity->createEntity(entityData));
}

void simulation_facade::Update(double dt) 
{
  for(auto i : VecEntity )
    {
        i -> Update(dt);
    }
}

void simulation_facade::FinishUpdate(picojson::object& returnValue) 
{
   for(auto a : VecEntity )
{
     //Called after all updating is done.
     //Below is an example of how to send the position and direction to the UI.  
     //In general you will want to loop through entities that have changed to update
     //their position and direction:


     
    picojson::object entity;
    entity["entityId"] = picojson::value((double)0);
    double * Posarray = a->getPosition()->getVector();
    // Save the position as an array
    picojson::array pos;
    pos.push_back(picojson::value(Posarray[0]));
    pos.push_back(picojson::value(Posarray[1]));
    pos.push_back(picojson::value(Posarray[2]));
    entity["pos"] = picojson::value(pos);


    double * Dirarray = a->getDirection()->getVector();
    // Save the direction as an array
    picojson::array dir;
    pos.push_back(picojson::value(Dirarray[0]));
    pos.push_back(picojson::value(Dirarray[1]));
    pos.push_back(picojson::value(Dirarray[2]));
    entity["dir"] = picojson::value(dir);

    // Send the compile picojson data to the UI in the returnValue variable
    returnValue["entity"+std::to_string(a->getID())] = picojson::value(entity);
    
}
}
