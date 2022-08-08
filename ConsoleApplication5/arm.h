#pragma once
#include "robotPart.h"
#include "arm_part.h"
class arm:
	public robotPart
{
public:
	arm_part* upper_arm;
	arm_part* forearm;
	arm_part* hand;
	arm(double x0, double y0, double z0, double sX, double sY, double sZ);
	arm();
	void draw();
	void rotate_shuolder(float angle);
	void rotate_elbow(float angle);
	void rotate_hand(float angle);
	void tranform(glm::mat4 trans);
	void rotateOverAxis(glm::vec3 a, glm::vec3 b, float angle);
};

