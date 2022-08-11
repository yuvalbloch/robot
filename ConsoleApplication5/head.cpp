#include "head.h"
/* 
* the eye are two red dot in the front of the head
*  this function culculte they position base on the coenrs of the front qoud of the head
 */
void head::drawEye()
{
	GLfloat materialColorBF[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialColorBF);
	glm::vec4 leftEye1 = ((corners[front_top_left] * 0.8f) + (corners[front_top_right] * 0.2f)) * 0.4f + (((corners[front_bottom_left] * 0.8f) + (corners[front_bottom_right] * 0.2f)) * 0.6f);
	glm::vec4 leftEye2 = ((corners[front_top_left] * 0.8f) + (corners[front_top_right] * 0.2f)) * 0.6f + (((corners[front_bottom_left] * 0.8f) + (corners[front_bottom_right] * 0.2f)) * 0.4f);
	glm::vec4 leftEye3 = ((corners[front_top_left] * 0.4f) + (corners[front_top_right] * 0.6f)) * 0.6f + (((corners[front_bottom_left] * 0.4f) + (corners[front_bottom_right] * 0.6f)) * 0.4f);
	glm::vec4 leftEye4 = ((corners[front_top_left] * 0.4f) + (corners[front_top_right] * 0.6f)) * 0.4f + (((corners[front_bottom_left] * 0.4f) + (corners[front_bottom_right] * 0.6f)) * 0.6f);

	glm::vec4  rightEye = ((corners[front_bottom_right] + corners[front_top_right]) * 2.0f + corners[front_top_left] + corners[front_bottom_left]) * 0.166666f;
	glPointSize(7.0);
	glBegin(GL_QUADS);
	
	glVertex3f(leftEye1.x, leftEye1.y, leftEye1.z);
	glVertex3f(leftEye2.x, leftEye2.y, leftEye2.z);
	glVertex3f(leftEye3.x, leftEye3.y, leftEye3.z);
	glVertex3f(leftEye4.x, leftEye4.y, leftEye1.z);
	glEnd();
	glFlush();

}
// the rander function draw every part of the head
void head::draw()
{
	robotPart::draw() ;
	neck.draw();
	drawEye();
	//some light test
}
//constructors
head::head(double x0, double y0, double z0, double sX, double sY, double sZ) : robotPart(x0,y0+sY/2,z0,sX,sY,sZ)
{
	neck = robotPart(x0 + sX * 0.4, y0, z0 + sZ * 0.4, sX / 5, sY / 2, sZ / 5);
}

head::head()
{
	head(0, 0, 0, 0, 0, 0);
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
	}
}
void head::rotate_left_right(float angle)
{
	if (sumHoriznalAngle < PI / 2 && angle>0 || sumHoriznalAngle > -PI / 2 && angle < 0) {
		sumHoriznalAngle += angle;
		glm::vec3 midNeck = (neck.corners[front_top_right] + neck.corners[front_top_left] + neck.corners[back_top_left] + neck.corners[back_top_left]) / 4.0f;
		rotateOverAxis(midNeck, midNeck + glm::vec3(0, 1, 0), angle);
		neck.rotateOverAxis(midNeck, midNeck + glm::vec3(0, 1, 0), angle);
	}
	
}
// run the basic transformtion from robot part on the head and the neck
void head::transformWithNeck(glm::mat4 trans)
{
	tranform(trans);
	neck.tranform(trans);
}

bool head::rotateOverAxisWithNeck(glm::vec3 a, glm::vec3 b, float angle)
{
	
	return (rotateOverAxis(a, b, angle) && neck.rotateOverAxis(a, b, angle));
}
