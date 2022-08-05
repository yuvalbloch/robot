#include "head.h"
void head::drawEye()
{
	myVertex3d leftEye = myVertex3d(0,0,0);
	myVertex3d rightEye = myVertex3d(0, 0, 0);
	((((((leftEye + corners[front_bottom_left]) + corners[front_top_left]) * 2) + corners[front_top_right]) + corners[front_bottom_right]) * (0.166666));
	((((((rightEye + corners[front_bottom_right]) + corners[front_top_right]) * 2) + corners[front_top_left]) + corners[front_bottom_left]) * (0.166666));
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
	drawEye();
}

head::head(double x0, double y0, double z0, double sX, double sY, double sZ) : robotPart(x0,y0,z0,sX,sY,sZ)
{
}

