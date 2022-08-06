#include "robot.h"
void robot::draw()
{
	std::cout << to_string(corners[0]) << "asasdasd";
	robotPart::draw();
	myHead.draw();
}
robot::robot(double x0, double y0, double z0, double sX, double sY, double sZ) : robotPart(x0, y0  , z0, sX, sY, sZ) {
	myHead = head(x0 + sX * (0.2), y0 + sY, z0 + sZ * 0.2, sX * 0.6, sY / 2, sZ * 0.6);
}
void robot::move( float fari) {
	glm::vec3 dirctionVector = (corners[back_bottom_left] - corners[front_bottom_left]) * fari;
	glm::mat4 translate = glm::translate( glm::mat4(1.0), dirctionVector);
	std::cout << glm::to_string(translate);
	tranform(translate);
	myHead.transformWithNeck(translate);
}
void robot::rotate(float angle) {
	glm::vec3 mid = (corners[front_bottom_right] + corners[front_bottom_left] + corners[back_bottom_right] + corners[back_bottom_left])/4.0f;
	rotateOverAxis(mid, mid + glm::vec3(0, 1, 0), angle);
	myHead.rotateOverAxis(mid, mid + glm::vec3(0, 1, 0), angle);
}