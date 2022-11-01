#include "gtest/gtest.h"
#include "Factory.h"
#include "entity.h"
#include "drone.h"
#include "robot.h"
#include "hospital.h"
#include "rechargeStation.h"
#include "web_app.h"
#include "battery.h"
#include "movement.h"
#include "beeline_movement.h"
#include "patrol_movement.h"
#include "vector3.h"
#include "image_facade.h"
#include "image.h"
#include "color.h"
#include "kernel.h"


class FactoryTest : public ::testing::Test {
public:
  void SetUp( ) {}
protected:
};

TEST_F(FactoryTest, CreateDrone) {  // Integration Test #1
  EntityFactory entityFactory = EntityFactory();
  Entity * testDrone;
  testDrone = entityFactory.createEntity("drone");
  Drone correctDrone = Drone ();
  EXPECT_EQ( testDrone->getType(), correctDrone.getType());
  
}

TEST_F(FactoryTest, CreateRobot) {  // Integration Test #2 
  EntityFactory entityFactory = EntityFactory();
  Entity * testRobot;
  testRobot = entityFactory.createEntity("robot");
  Robot correctRobot = Robot ();
  EXPECT_EQ( testRobot->getType(), correctRobot.getType());
  
}

TEST_F(FactoryTest, CreateHospital) {  // Integration Test #3 
  EntityFactory entityFactory = EntityFactory();
  Entity * testHospital;
  testHospital = entityFactory.createEntity("hospital");
  Hospital correctHospital = Hospital ();
  EXPECT_EQ( testHospital->getType(), correctHospital.getType());
  
}

TEST_F(FactoryTest, CreateRechargeStation) {  // Integration Test #4 
  EntityFactory entityFactory = EntityFactory();
  Entity * testRechargeStation;
  testRechargeStation = entityFactory.createEntity("recharge station");
  RechargeStation correctRechargeStation = RechargeStation ();
  EXPECT_EQ( testRechargeStation->getType(), correctRechargeStation.getType());
  
}

TEST_F(FactoryTest, CreateJSONRobot) // Integration Test #5
{  
  picojson::object info;
  info["name"] = picojson::value("robot");
  info["entityID"] = picojson::value(1.0);
  picojson::array pos;
  pos.push_back(picojson::value(1.0));
  pos.push_back(picojson::value(1.0));
  pos.push_back(picojson::value(1.0));
  info["pos"] = picojson::value(pos);
  picojson::array dir;
  dir.push_back(picojson::value(1.0));
  dir.push_back(picojson::value(1.0));
  dir.push_back(picojson::value(1.0));
  info["dir"] = picojson::value(dir);
  picojson::object o;
  o["params"] = picojson::value(info);
  picojson::value v(o);

  EntityFactory entityFactory = EntityFactory();

  Entity * testRobot;
  testRobot = entityFactory.createEntity(info);
  Robot correctRobot = Robot (info);
  EXPECT_TRUE (testRobot != nullptr);
  EXPECT_EQ( testRobot->getType(), correctRobot.getType());
}

TEST_F(FactoryTest, CreateJSONDrone) // Component  Test #1
{  
  picojson::object info;
  info["name"] = picojson::value("drone");
  info["entityID"] = picojson::value(1.0);
  info["speed"] = picojson::value(1.0);
  picojson::array pos;
  pos.push_back(picojson::value(1.0));
  pos.push_back(picojson::value(1.0));
  pos.push_back(picojson::value(1.0));
  info["pos"] = picojson::value(pos);
  picojson::array dir;
  dir.push_back(picojson::value(1.0));
  dir.push_back(picojson::value(1.0));
  dir.push_back(picojson::value(1.0));
  info["dir"] = picojson::value(dir);
  picojson::object o;
  o["params"] = picojson::value(info);
  picojson::value v(o);

  EntityFactory entityFactory = EntityFactory();

  Entity * testDrone;
  testDrone = entityFactory.createEntity(info);
  Drone correctDrone = Drone (info);
  EXPECT_TRUE (testDrone != nullptr);
  EXPECT_EQ( testDrone->getType(), correctDrone.getType());
}

class RechargeTest : public ::testing::Test {
public:
  void SetUp( ) {}
protected:
};

TEST_F(RechargeTest, setRecharge) {  // Component Test #2
	picojson::object info;
	info["name"] = picojson::value("recharge station");
	info["entityID"] = picojson::value(2.0);
	picojson::array pos;
	pos.push_back(picojson::value(1.0));
	pos.push_back(picojson::value(1.0));
	pos.push_back(picojson::value(1.0));
	info["pos"] = picojson::value(pos);
	picojson::array dir;
	dir.push_back(picojson::value(1.0));
	dir.push_back(picojson::value(1.0));
	dir.push_back(picojson::value(1.0));
	info["dir"] = picojson::value(dir);
	picojson::object o;
	o["params"] = picojson::value(info);
	picojson::value v(o);

	EntityFactory entityFactory = EntityFactory();
	Entity * testRecharge;
	testRecharge = entityFactory.createEntity(info);
	
  picojson::object infoD;
  infoD["name"] = picojson::value("drone");
  infoD["entityID"] = picojson::value(1.0);
  infoD["speed"] = picojson::value(1.0);
  picojson::array posD;
  posD.push_back(picojson::value(1.0));
  posD.push_back(picojson::value(1.0));
  posD.push_back(picojson::value(1.0));
  infoD["pos"] = picojson::value(pos);
  picojson::array dirD;
  dirD.push_back(picojson::value(1.0));
  dirD.push_back(picojson::value(1.0));
  dirD.push_back(picojson::value(1.0));
  infoD["dir"] = picojson::value(dir);
  picojson::object oD;
  o["params"] = picojson::value(info);
  picojson::value vD(oD);


  Drone correctDrone = Drone (infoD);
	correctDrone.setRecharge(testRecharge);
	EXPECT_TRUE (testRecharge != nullptr);
	EXPECT_TRUE (correctDrone.getRecharge() != nullptr);
	EXPECT_EQ( testRecharge, correctDrone.getRecharge());
}

class BatteryTest : public ::testing::Test {
public:
  void SetUp() {}
protected:
};

TEST_F(BatteryTest, CheckInitialBattery) // Unit Test #1
{
    Battery battery;
    EXPECT_EQ(100, battery.getBatteryLevel());
}

TEST_F(BatteryTest, CheckUseBattery) // Unit Test #2
{
    Battery battery;
    double dt = 10;
    battery.useBattery(dt);
    EXPECT_EQ(90,battery.getBatteryLevel() );
}

TEST_F(BatteryTest, CheckBatteryRecharge) // Unit Test #3
{
    Battery battery;
    double dt_use = 100;
    double dt_recharge = 50;
    battery.useBattery(dt_use);
    battery.recharge(dt_recharge);
    
    EXPECT_EQ(50, battery.getBatteryLevel());
}

TEST_F(BatteryTest, CheckBatteryStatue) // Unit Test #4
{
    Battery battery;
    double dt = 100.0;
    battery.useBattery(dt);
    EXPECT_TRUE(battery.checkBattery());
}

TEST_F(BatteryTest, CheckBatteryRange) // Regression Test #1
{
    Battery lowbattery;
    double dt = 120.0;
    lowbattery.useBattery(dt);

    Battery highbattery;
    highbattery.recharge(dt);

    EXPECT_EQ(0, lowbattery.getBatteryLevel());
    EXPECT_EQ(100, highbattery.getBatteryLevel());
}

// This tests the movement classes
class MovementTest : public ::testing::Test {
public:
  void SetUp( ) {}
protected:
};

TEST_F(MovementTest, CreateMovement) // Unit Test #5
{
  Movement* movement;
  movement = nullptr;
  EXPECT_TRUE(movement == nullptr);
}

TEST_F(MovementTest, CreateBeelineMovement) // Component Test #3
{ 
  Vector3 newPosition;
  Movement* movement = new BeelineMovement(newPosition);
  EXPECT_TRUE(movement != nullptr);
  delete movement;
}

TEST_F(MovementTest, CreatePatrolMovement) // Regression Test #2
{ 
  Movement* movement = new PatrolMovement();
  EXPECT_TRUE(movement != nullptr);
  delete movement;
}


// This tests the Vector3 class
class Vector3Test : public ::testing::Test {
public:
  void SetUp( ) {}
protected:
};

TEST_F(Vector3Test, TestVector3DefaultConstructor) // Unit Test #6
{
  Vector3 vec;
  EXPECT_TRUE(vec[0] == 0.0 && vec[1] == 0.0 && vec[2] == 0.0);
}

TEST_F(Vector3Test, TestVector3Constructor) // Regression Test #3
{
  Vector3 vec1 = Vector3(1.1, 1.1, 1.1);
  Vector3 vec2 = Vector3(1.1, 2.2, 3.3);
  Vector3 vec3 = Vector3(-1.1, -1.1, -1.1);
  EXPECT_TRUE(vec1[0] == 1.1 && vec1[1] == 1.1 && vec1[2] == 1.1);
  EXPECT_TRUE(vec2[0] == 1.1 && vec2[1] == 2.2 && vec2[2] == 3.3);
  EXPECT_TRUE(vec3[0] == -1.1 && vec3[1] == -1.1 && vec3[2] == -1.1);
}

TEST_F(Vector3Test, TestVector3Addition) // Unit Test #7
{
  double val = 1.1;
  Vector3 vec1 = Vector3(1.1, 1.1, 1.1);
  Vector3 vec2 = Vector3(2.2, 2.2, 2.2);
  Vector3 vec3 = vec1 + vec1;
  Vector3 vec4 = vec1 + val;
  EXPECT_TRUE(vec2 == vec3);
  EXPECT_TRUE(vec2 == vec4);
}

TEST_F(Vector3Test, TestVector3Subtraction) // Unit Test #8
{
  double val = 1.1;
  Vector3 vec1 = Vector3(1.1, 1.1, 1.1);
  Vector3 vec2;
  Vector3 vec3 = vec1 - vec1;
  Vector3 vec4 = vec1 - val;
  EXPECT_TRUE(vec2 == vec3);
  EXPECT_TRUE(vec2 == vec4);
}

TEST_F(Vector3Test, TestVector3Multiplication) // Unit Test #9
{
  double val = 2.0;
  Vector3 vec1 = Vector3(1.0, 1.0, 1.0);
  Vector3 vec2 = Vector3(2.0, 2.0, 2.0);
  Vector3 vec3 = vec1 * vec2;
  Vector3 vec4 = vec1 * val;
  EXPECT_TRUE(vec2 == vec3);
  EXPECT_TRUE(vec2 == vec4);
}

TEST_F(Vector3Test, TestVector3Division) // Unit Test #10
{
  double val = 2.0;
  Vector3 vec1 = Vector3(2.0, 2.0, 2.0);
  Vector3 vec2 = Vector3(1.0, 1.0, 1.0);
  Vector3 vec3 = vec1 / vec1;
  Vector3 vec4 = vec1 / val;
  EXPECT_TRUE(vec2 == vec3);
  EXPECT_TRUE(vec2 == vec4);
}

TEST_F(Vector3Test, TestVector3BracketOperator) // Regression Test #4
{ 
  double val = 0.0;
  Vector3 vec1;
  EXPECT_EQ(vec1[0], val);
  EXPECT_EQ(vec1[1], val);
  EXPECT_EQ(vec1[2], val);
}

// Test == for Vector3
TEST_F(Vector3Test, TestVector3Equality) // Unit Test (extra)
{
  Vector3 vec1;
  Vector3 vec2 = Vector3(0.0, 0.0, 0.0);
  EXPECT_TRUE(vec1 == vec2);
  EXPECT_TRUE(vec2 == vec1);
}

// Test != for Vector3
TEST_F(Vector3Test, TestVector3NotEquality) // Unit Test (extra)
{
  Vector3 vec1;
  Vector3 vec2 = Vector3(1.0, 1.0, 1.0);
  EXPECT_TRUE(vec1 != vec2);
  EXPECT_TRUE(vec2 != vec1);
}

// Test magnitude function for Vector3
TEST_F(Vector3Test, TestVector3Magnitude) // Regression Test #5
{ 
  double val1 = 2.0;
  double val2 = 3.0;
  Vector3 vec1 = Vector3(0.0, 2.0, 0.0);
  Vector3 vec2 = Vector3(3.0, 0.0, 0.0);
  double val3 = vec1.Magnitude();
  double val4 = vec2.Magnitude();
  EXPECT_EQ(val1, val3);
  EXPECT_EQ(val2, val4);
}

// Test normalize function for Vector3
TEST_F(Vector3Test, TestVector3Normalize) // Unit Test (extra)
{
  Vector3 vec1 = Vector3(2.0, 0.0, 0.0);
  Vector3 vec2 = Vector3(3.0, 0.0, 0.0);
  Vector3 vec3 = Vector3(1.0, 0.0, 0.0);
  vec1.Normalize();
  vec2.Normalize();
  EXPECT_TRUE(vec1 == vec3);
  EXPECT_TRUE(vec2 == vec3);
}

class ImageTest : public ::testing::Test {
public:
  void SetUp( ) {}
protected:
};

TEST_F(ImageTest, ImageColorTest) // Component Test #4
{
	Image testImage = Image (1, 1);
	Color green = Color (0.0, 1.0, 0.0, 1.0);
	testImage.SetPixel(0,0, green);
	Color pixel = testImage.GetPixel(0,0);
	EXPECT_TRUE (green == pixel);
}

TEST_F(ImageTest, LargeImageColorTest) // Component Test #5
{
	Image testImage = Image (10, 10);
	Color green = Color (0.0, 1.0, 0.0, 1.0);
	Color blue = Color (0.0, 0.0, 1.0, 1.0);
	for (int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			testImage.SetPixel(i,j, green);
			if (i == 4 && j == 4)
			{
				testImage.SetPixel(i,j, blue);
			}
		}
	}
	Color pixel = testImage.GetPixel(0,0);
	EXPECT_TRUE (green == pixel);
	Color bluepixel = testImage.GetPixel(4,4);
	EXPECT_TRUE (blue == bluepixel);
	
}



