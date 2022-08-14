#include "powerButton.h"

powerButton::powerButton() :button() {
}
powerButton::powerButton(float x_minimum, float y_minimum, float x_maximum, float y_maximum, std::string NAME)
	: button(x_minimum, y_minimum, x_maximum, y_maximum, NAME) {
}
/*
* the power button made of spectrom of color that reprasent the color that been cohs in diffren brithness
* the button made of thin line in diffrent brithness stand on beside anther
*/
void powerButton::draw(float r, float g, float b)
{
	float step = 1.0 / (maxX - minX);
	glLineWidth(1.0);
	glBegin(GL_LINES);
	for (float i = minX; i < maxX; i++) {
		glColor3f(r * i * step, g * i * step, b * i * step);
		glVertex2f(i, minY);
		glVertex2f(i, maxY);
	}
	glEnd();
	on = true;
	glFlush();
}
/*
* pressing of any point in thee button return the brithness of this point
*/
float powerButton::chosePower(int x, int y)
{
	float step = 1.0 / (maxX - minX);
	std::cout << step;
	if (press(x, y)) {
		return step * static_cast<float>(x - minX);

	}
	return 0;
}
