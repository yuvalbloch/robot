#include "arm.h"


arm::arm(double x0, double y0, double z0, double sX, double sY, double sZ  ) 
{
	hand = new arm_part(x0, y0, z0 + sZ*(2.0/3.0), sX, sY, sZ / 3, nullptr);
	forearm = new arm_part(x0, y0, z0 + sZ / 3, sX, sY, sZ / 3, hand);
	upper_arm =  new arm_part(x0, y0, z0, sX, sY, sZ / 3, forearm);
}

arm::arm()
{
}

void arm::draw()
{
	upper_arm->draw();
	forearm->draw();
	hand->draw();
}

void arm::rotate_shuolder(float angle)
{
	upper_arm->rotate(angle);
}

void arm::rotate_elbow(float angle)
{
	if (forearm->cur_angle + angle > 0 && forearm->cur_angle + angle < PI ) {
		forearm->rotate(angle);
	}
}

void arm::rotate_hand(float angle)
{
	if (hand->cur_angle + angle > -PI  && hand->cur_angle + angle < PI ) {
		hand->rotate(angle);
	}
}

void arm::tranform(glm::mat4 trans)
{
	forearm->tranform(trans);
	upper_arm->tranform(trans);
	hand->tranform(trans);
}

void arm::rotateOverAxis(glm::vec3 a, glm::vec3 b, float angle)
{
	forearm->rotateOverAxis(a,b,angle);
	upper_arm->rotateOverAxis(a, b, angle);
	hand->rotateOverAxis(a, b, angle);
}
