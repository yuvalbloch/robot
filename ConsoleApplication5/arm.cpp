#include "arm.h"

/*
* the constructor create 3 boxes that reprasent the 3 diffrent part of the arm
* (upper_arm forearm and hand) the length of evryone of the box in z axis is 1/3 sZ
* and the boxes line up over the z axis so the the length of the z axiz of the arm is sZ as expted
*/
arm::arm(double x0, double y0, double z0, double sX, double sY, double sZ  ) 
{
	hand = new arm_part(x0, y0, z0 + sZ*(2.0/3.0), sX, sY, sZ / 3, nullptr);
	forearm = new arm_part(x0, y0, z0 + sZ / 3, sX, sY, sZ / 3, hand);
	upper_arm =  new arm_part(x0, y0, z0, sX, sY, sZ / 3, forearm);
}
//empty contructor that use to space allotment
arm::arm()
{
}
//the rander function
void arm::draw()
{
	upper_arm->draw();
	forearm->draw();
	hand->draw();
}
/*
* there is 3 possible way to rotate the hand in addition to the part that the moving start from
* any part that rotate rotate the pars that came next to him
*/
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
/*
* the basic tranformtion fuction that implemnt in the robot part over ride her 
* where evry function happnd on all the arm part as once
*/
bool arm::tranform(glm::mat4 trans)
{
	if (checkCollision(trans) )
	{
		forearm->tranform(trans);
		upper_arm->tranform(trans);
		hand->tranform(trans);
		return true;
	}
	return false;

}

bool arm::rotateOverAxis(glm::vec3 a, glm::vec3 b, float angle)
{
	
	if (forearm->rotateOverAxis(a, b, angle)) {
		upper_arm->rotateOverAxis(a, b, angle);
		hand->rotateOverAxis(a, b, angle);
		return true;
	}
	return false;
}

bool arm::checkCollision(glm::mat4 trans)
{
	return (hand->checkCollision(trans) && forearm->checkCollision(trans) && upper_arm->checkCollision(trans));
}
