#include "arm_part.h"

void arm_part::rotate(float angle)
{
	cur_angle += angle;
	glm::vec3 b_axis = (corners[back_top_left] + corners[back_bottom_left]) / 2.0f;
	glm::vec3 a_axis = (corners[back_top_right] + corners[back_bottom_right]) / 2.0f;
	rotateOverAxis(a_axis, b_axis , angle);
	if (next != nullptr ) {
		next->rotateOverAxisWithSibling(a_axis,b_axis,angle);
	}
}
void arm_part::rotateOverAxisWithSibling(glm::vec3 a, glm::vec3 b, float angle)
{
	rotateOverAxis( a,  b,  angle);
	if (next != nullptr) {
		next->rotateOverAxisWithSibling(a, b, angle);
	}
}
arm_part::arm_part(double x0, double y0, double z0, double sX, double sY, double sZ , arm_part *Next) :robotPart(x0, y0, z0, sX, sY, sZ) {
	next = Next;
	cur_angle = 0;
}
arm_part::arm_part() {

}
