#include "robot.h"
void robot::draw()
{
	robotPart::draw();
	myHead.draw();
	myArm.draw();
}
robot::robot(double x0, double y0, double z0, double sX, double sY, double sZ) : robotPart(x0, y0  , z0, sX, sY, sZ) {
	myHead = head(x0 + sX * (0.2), y0 + sY, z0 + sZ * 0.2, sX * 0.6, sY / 2, sZ * 0.6);
	myArm = arm(x0 + sX, y0 + sY / 2, z0 + sZ / 2, sX / 4,  sY / 4, sZ * 2);
}
void robot::move( float fari) {
	glm::vec3 dirctionVector = (corners[back_bottom_left] - corners[front_bottom_left]) * fari;
	glm::mat4 translate = glm::translate( glm::mat4(1.0), dirctionVector);
	tranform(translate);
	myArm.tranform(translate);
	myHead.transformWithNeck(translate);
}
void robot::keyBoard(unsigned char key)
{
	switch (key) {
	case 'w':
		myHead.rotate_up_down(-0.2);
		break;
	case 's':
		myHead.rotate_up_down(0.2);
		break;
	case 'a':
		myHead.rotate_left_right(-0.2);
		break;
	case 'd':
		myHead.rotate_left_right(0.2);
		break;
	case 'u':
		myArm.rotate_shuolder(0.2);
		break;
	case 'j':
		myArm.rotate_shuolder(-0.2);
		break;
	case 'i':
		myArm.rotate_elbow(0.2);
		break;
	case 'k':
		myArm.rotate_elbow(-0.2);
		break;
	case 'o':
		myArm.rotate_hand(0.2);
		break;
	case 'l':
		myArm.rotate_hand(-0.2);
		break;
	}

	glutPostRedisplay();
}
void robot::rotate(float angle) {
	glm::vec3 mid = (corners[front_bottom_right] + corners[front_bottom_left] + corners[back_bottom_right] + corners[back_bottom_left])/4.0f;
	rotateOverAxis(mid, mid + glm::vec3(0, 1, 0), angle);
	myHead.rotateOverAxis(mid, mid + glm::vec3(0, 1, 0), angle);
	myArm.rotateOverAxis(mid, mid + glm::vec3(0, 1, 0), angle);
}