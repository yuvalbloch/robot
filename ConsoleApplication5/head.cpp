#include "head.h"
/* 
* the eye are two red dot in the front of the head
*  this function culculte they position base on the coenrs of the front qoud of the head
 */

// the rander function draw every part of the head
void head::draw()
{

	robotPart::draw() ;
	neck.draw();
	GLfloat materialColorEYE[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialColorEYE);
	leftEye.draw();
	rightEye.draw();
	if (robotEye) {
		see();
	}
}
//constructors
head::head(double x0, double y0, double z0, double sX, double sY, double sZ) : robotPart(x0,y0+sY/2,z0,sX,sY,sZ)
{
	neck = robotPart(x0 + sX * 0.4, y0, z0 + sZ * 0.4, sX / 5, sY / 2, sZ / 5);
	leftEye = robotPart(x0 + (0.2 * sX), y0 + (0.9 * sY),z0+sZ, sX * 0.2, sY * 0.2, sZ * 0.1);
	rightEye = robotPart(x0 + (0.6 * sX), y0 + (0.9 * sY), z0 + sZ, sX * 0.2, sY * 0.2, sZ * 0.1);
}

head::head()
{
	head(0, 0, 0, 0, 0, 0);
}
void head::see()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glm::vec4 eyePostion = (corners[front_bottom_left] + corners[front_bottom_right] + corners[front_top_left] + corners[front_top_right]) / 4.0f;
	glm::vec4 refPostion(1.0);
	utility::vecMultyple(&refPostion, corners[front_bottom_left] - corners[front_bottom_right], corners[front_bottom_left] - corners[front_top_left]);
	refPostion += eyePostion;
	gluLookAt(eyePostion.x, eyePostion.y, eyePostion.z, refPostion.x, refPostion.y, refPostion.z, 0, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 1, 10, 250);
}
void head::startSee()
{
	robotEye = true;
	see();
}

/*
* there is 2 possible rotition to the head 
* up_down rotate on a vertical axis that cross trogh the middle of the head
* left_right rotate on verical axis in the middle of the head, the axis dont move in up_down rotatin 
*/
void head::rotate_up_down(float angle)
{
	if (sumVerticalAngle < PI/6 && angle>0 || sumVerticalAngle > -PI/6 && angle < 0)  {
		sumVerticalAngle += angle;
		glm::vec3 midLeft = (corners[front_top_left] + corners[front_bottom_left] + corners[back_bottom_left] + corners[back_top_left]) / 4.0f;
		glm::vec3 midRight = (corners[front_top_right] + corners[front_bottom_right] + corners[back_bottom_right] + corners[back_top_right]) / 4.0f;
		rotateOverAxis(midLeft, midRight, angle);
		leftEye.rotateOverAxis(midLeft, midRight, angle);
		rightEye.rotateOverAxis(midLeft, midRight, angle);
	}
}
void head::rotate_left_right(float angle)
{
	if (sumHoriznalAngle < PI / 2 && angle>0 || sumHoriznalAngle > -PI / 2 && angle < 0) {
		sumHoriznalAngle += angle;
		glm::vec3 midNeck = (neck.corners[front_top_right] + neck.corners[front_top_left] + neck.corners[back_top_left] + neck.corners[back_top_left]) / 4.0f;
		rotateOverAxis(midNeck, midNeck + glm::vec3(0, 1, 0), angle);
		neck.rotateOverAxis(midNeck, midNeck + glm::vec3(0, 1, 0), angle);
		leftEye.rotateOverAxis(midNeck, midNeck + glm::vec3(0, 1, 0), angle);
		rightEye.rotateOverAxis(midNeck, midNeck + glm::vec3(0, 1, 0), angle);

	}
	
}
// run the basic transformtion from robot part on the head and the neck
void head::transformWithNeck(glm::mat4 trans)
{
	tranform(trans);
	neck.tranform(trans);
	leftEye.tranform(trans);
	rightEye.tranform(trans);
}

bool head::rotateOverAxisWithNeck(glm::vec3 a, glm::vec3 b, float angle)
{
	std::cout << "rotateOverAxisWithNeck";
	leftEye.rotateOverAxis(a, b, angle);
	rightEye.rotateOverAxis(a, b, angle);
	neck.rotateOverAxis(a, b, angle);
	return (rotateOverAxis(a, b, angle) );
}
