#include "gtest/gtest.h"
#include "Factory.h"
#include "entity.h"
#include "drone.h"
#include "robot.h"
#include "hospital.h"
#include "rechargeStation.h"

class FactoryTest : public ::testing::Test {
public:
  void SetUp( ) { 
  }
protected:
};

TEST_F(FactoryTest, CreateDrone) {  
  EntityFactory entityFactory = EntityFactory();
  Entity * testDrone;
  testDrone = entityFactory.createEntity("drone");
  Drone correctDrone = Drone ();
  EXPECT_EQ( testDrone->getType(), correctDrone.getType());
  
}

TEST_F(FactoryTest, CreateRobot) {  
  EntityFactory entityFactory = EntityFactory();
  Entity * testRobot;
  testRobot = entityFactory.createEntity("robot");
  Robot correctRobot = Robot ();
  EXPECT_EQ( testRobot->getType(), correctRobot.getType());
  
}

TEST_F(FactoryTest, CreateHospital) {  
  EntityFactory entityFactory = EntityFactory();
  Entity * testHospital;
  testHospital = entityFactory.createEntity("hospital");
  Hospital correctHospital = Hospital ();
  EXPECT_EQ( testHospital->getType(), correctHospital.getType());
  
}

TEST_F(FactoryTest, CreateRechargeStation) {  
  EntityFactory entityFactory = EntityFactory();
  Entity * testRechargeStation;
  testRechargeStation = entityFactory.createEntity("recharge station");
  RechargeStation correctRechargeStation = RechargeStation ();
  EXPECT_EQ( testRechargeStation->getType(), correctRechargeStation.getType());
  
}

// TEST_F(FactoryTest, DroneValues)// need to write get functions for drone values
// {
//   EntityFactory entityFactory = EntityFactory();
//   Entity * testDrone;
//   testDrone = entityFactory.createEntity("drone");
//   Drone correctDrone = Drone ();
//   EXPECT_EQ( testDrone->getType(), correctDrone.getType());

// }

// TEST_F(FactoryTest, CreateJSONDrone) 
// {  
//   picojson::object info;
//   info["name"] = picojson::value("drone");
//   info["entityID"] = picojson::value(1.0);
//   picojson::object o;
//   o["params"] = picojson::value(info);
//   picojson::value v(o);
//   //this->Send(v);

//   EntityFactory entityFactory = EntityFactory();
//   Entity * testDrone;
//   testDrone = entityFactory.createEntity(o);
//   Drone correctDrone = Drone ();
//   EXPECT_NE (*testDrone, NULL);
//   EXPECT_EQ( testDrone->getType(), correctDrone.getType());
// }
// This creates the following JSON value.
// ```
// [
//     "notification": {
//         "type": "battery",
//         "data": 1.0
//     }
// ]
// TEST_F(FactoryTest, CreateJSONDrone) {  
//   { "command": "reset", "params": {}},
//     {
//         "command": "createEntity",
//       	"params": {
//             "entityId": 0,
//             "name": "drone",
//             "type": "actor",
//       	    "path": "drone.glb",
//       	    "position": [0, 264, 0],
//       	    "scale": [0.15, 0.15, 0.15],
//       	    "rotation": [0, 0, 0],
//             "direction": [0, 0, 0],
//             "charge": 20.0,
//             "speed": 4.0,
//             "radius": 1.0,
//             "start": 2.0,
//             "duration": 2.0,
//             "offset": [0, 0.6, 0]
//     	  }
//     },
//   EntityFactory entityFactory = EntityFactory();
//   Entity * testDrone;
//   testDrone = entityFactory.createEntity("drone");
//   Drone correctDrone = Drone ();
//   EXPECT_EQ( testDrone->getType(), correctDrone.getType());
  
// }