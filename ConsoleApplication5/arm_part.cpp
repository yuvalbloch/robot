#include "arm_part.h"
//the arm part can rotate over an axis that lay vertical to the graound in the middle of his meeting with the last arm part
bool arm_part::rotate(float angle)
{
	cur_angle += angle;
	glm::vec3 b_axis = (corners[back_top_left] + corners[back_bottom_left]) / 2.0f;
	glm::vec3 a_axis = (corners[back_top_right] + corners[back_bottom_right]) / 2.0f;
	bool possible = rotateOverAxis(a_axis, b_axis , angle);
	if (possible && (next != nullptr) ) {
		next->rotateOverAxisWithSibling(a_axis,b_axis,angle);
	}
	return true;
}
// use rotate over axis fuctiion to rotate himself and the nexts part
bool arm_part::rotateOverAxisWithSibling(glm::vec3 a, glm::vec3 b, float angle)
{
	bool possible = rotateOverAxis(a, b, angle);
	if (next != nullptr && possible) {
		next->rotateOverAxisWithSibling(a, b, angle);
	}
	return true;
}
// run overide check collision to check collision for himself and his nexts
bool arm_part::checkCollision(glm::mat4 trans)
{
	if (next == nullptr) {
		return (robotPart::checkCollision(trans));
	}
	return (robotPart::checkCollision(trans) && next->checkCollision(trans));
}
/*
* the cunstructor add 2 new parmter to the constructor of robot part 
* the next use to connect to the next part down the arm 
and the cur_angle use to make sure that the angle stay in the possible range 
*/
arm_part::arm_part(double x0, double y0, double z0, double sX, double sY, double sZ , arm_part *Next) :robotPart(x0, y0, z0, sX, sY, sZ) {
	next = Next;
	cur_angle = 0;
}
//empty contructor use only to allocate space
arm_part::arm_part() {

}
