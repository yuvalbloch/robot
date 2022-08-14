#include "colorButton.h"
colorButton::colorButton():button() {
}
colorButton::colorButton(float x_minimum, float y_minimum, float x_maximum, float y_maximum, std::string NAME)
	: button(x_minimum, y_minimum, x_maximum, y_maximum, NAME) {

}
/*
* every point in the color button draw spreatly with a litle diffrent color
*/
void colorButton::draw(float power)
{
	on = true;
	xStep = power / (maxX - minX);
	yStep = power / (maxY - minY);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	for (int x=0; x <= (maxX - minX); x++) {
		for (int y = 0; y < (maxY - minY); y++) {
			glColor3f(x * xStep, y * yStep, (power - (((y * yStep)) + (x * xStep))/2));
			glVertex2i(minX + x, minY + y);
		}
	}
	glEnd();
	glFlush;
}

void colorButton::choseColor(float* r, float* g, float* b , int x ,int y)
{
	int relX = x - minX;
	int relY = 1- (y - minY);
	*r = ((x - minX) * xStep);
	*g = ((y - minY) * yStep);
	*b = 1 - ((((y - minY) * yStep)) + ((x - minX) * xStep) / 2);
	
}
