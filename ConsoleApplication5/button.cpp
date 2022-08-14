#include "button.h"
#include <assert.h>   

/*
* the empty constructor create an theortical unseenable and unpresssable button
* for tamporary reason
*/
button::button()
{
	minX = 0;
	minY = 0;
	maxX = 0;
	maxY = 0;
}
/*
* this is the real constructor it make sure that the button are possible geomatricly and then set up is parmater
*/
button::button(float x_minimum, float y_minimum, float x_maximum, float y_maximum ,std::string NAME)
{
	if (x_minimum > x_maximum || y_minimum > y_maximum) {
		std::cout << "maximum must be more then minimum that not so in "<< NAME;
		button();
	}
	else {
		on = false;
		name = NAME;
		minX = x_minimum;
		minY = y_minimum;
		maxX = x_maximum;
		maxY = y_maximum;
	}
}
/*
* the drw functioncreat the button as a qoud that cover all the pressable area
* and write the name of the button inside
*/
 void button::draw()
{
	glBegin(GL_QUADS);
	glVertex2f(minX, minY);
	glVertex2f(minX, maxY); 
	glVertex2f(maxX, maxY);
	glVertex2f(maxX, minY);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	displayName();
	on =true;
	glFlush();
}

/*
* the press function call when mouse button are press in the right page and check if the press was inside the button 
*/
bool button::press(int x, int y)
{
	return (x > minX && x < maxX&& y>minY && y < maxY)&& on;
}
void button::displayName() {
	glRasterPos2f(minX +10, minY+10);
	for (int i = 0; i < name.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name[i]);
	}
}

void button::off()
{
	on = false;
}
