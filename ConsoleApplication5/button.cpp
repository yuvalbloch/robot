#include "button.h"

button::button()
{
	minX = 0;
	minY = 0;
	maxX = 0;
	maxY = 0;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
* to do: make better eror handle
*/
button::button(float x_minimum, float y_minimum, float x_maximum, float y_maximum)
{
	if (x_minimum > x_maximum || y_minimum > y_maximum) {
		std::cout << "maximum must be more then minimum";
	}
	else {
		minX = x_minimum;
		minY = y_minimum;
		maxX = x_maximum;
		maxY = y_maximum;
	}
}

void button::draw()
{
	glBegin(GL_QUADS);
	glVertex2f(minX, minY);
	glVertex2f(minX, maxY); 
	glVertex2f(maxX, maxY);
	glVertex2f(maxX, minY);
	glEnd();
	glFlush();
}

bool button::press(int x, int y)
{
	return (x > minX && x < maxX&& y>minY && y < maxY);
}
