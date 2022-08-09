#pragma once
#include "robotPart.h"
#include "arm_part.h"
/*
* the arm of the robot is mobile part that move in tree diffrent joints that part tham into 3 part
* in they way of moving they try to emulate human arms build from upper arm forearm and hand
*/
class arm:
	public robotPart
{
public:
	// part of the arm
	arm_part* upper_arm;
	arm_part* forearm;
	arm_part* hand;
	//constructors
	arm(double x0, double y0, double z0, double sX, double sY, double sZ);
	arm();
	void draw();
	//transformation that came from the diffrent part of the arms
	void rotate_shuolder(float angle);
	void rotate_elbow(float angle);
	void rotate_hand(float angle);
	// base transformatiom
	bool tranform(glm::mat4 trans);
	bool rotateOverAxis(glm::vec3 a, glm::vec3 b, float angle);
	/*
	run the robot part check collison to check collision for each of the arm part
	so the arm can move togther 
	*/
	bool checkCollision(glm::mat4 trans);
};

