#include "head.h"
void head::drawEye()
{
	
	glm::vec4 leftEye  = ((corners[front_bottom_left] + corners[front_top_left]) * 2.0f + corners[front_top_right] + corners[front_bottom_right]) * 0.166666f;
	glm::vec4  rightEye = ((corners[front_bottom_right] + corners[front_top_right]) * 2.0f + corners[front_top_left] + corners[front_bottom_left]) * 0.166666f;
	glPointSize(7.0);
	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);
	glVertex3f(leftEye.x,leftEye.y,leftEye.z);
	glVertex3f(rightEye.x, rightEye.y, rightEye.z);
	glEnd();
	glFlush();

}

void head::draw()
{
	robotPart::draw() ;
	neck.draw();
	drawEye();
}

head::head(double x0, double y0, double z0, double sX, double sY, double sZ) : robotPart(x0,y0+sY/2,z0,sX,sY,sZ)
{
	neck = robotPart(x0 + sX * 0.4, y0, z0 + sZ * 0.4, sX / 5, sY / 2, sZ / 5);
}

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
