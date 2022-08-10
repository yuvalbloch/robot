#include "world.h"

world::world()
{
	control = robotControl;
	winHigh = 600 ;
	WinWidth = 1200; //window size
	roby = robot(50, 5, 50, 20, 30, 20);
	
}
void world::Init(void) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize( WinWidth, winHigh);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("the lab of roby the robot");
	kamy.rander();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
}
void world::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//draw the room
	lab.drawRoom();
	roby.draw();
	glFlush();
}


void world::keyboard(unsigned char key)
{
	if (key == 'p') {
		control = camraControl;
	}
	if (control == robotControl) {
		roby.keyBoard(key);
	}
	else if (control == camraControl) {
		kamy.keyBoard(key);
	}
}
void world::spicelKeyboard(int key) {
	if (key == 'p') {
		control = camraControl;
	}
	if (control == robotControl) {
		roby.spicelKeyBoard(key);
	}
	else if (control == camraControl) {
		kamy.spicelKeyBoard(key);
	}
}
