#include "world.h"

/*
* while initilaize the keyboard control the robot 
* we also initialize the window size and the robot postion into comftarbale vlue
*/
world::world()
{
	control = robotControl;
	winHigh = 600 ;
	WinWidth = 1200; //window size
	roby = robot(50, 1, 50, 20, 30, 20);
	
}
/*
* the Init function is qouit standart initalize function for opengl graphic function
* we display the buffers enable function that we use set the window and start the camra
*/
void world::Init(void) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize( WinWidth, winHigh);
	glutInitWindowPosition(50, 50);
	glEnable(GL_DEPTH_TEST);

}
void world::setUp()
{
	kamy.rander();
	lab.createLight();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
}
// the display function draw the room and the robot
void world::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	lab.drawRoom();
	roby.draw();


	
}


/*
* the keyboard event handle allow 3 diffren state that hange with number key
* 1: the keyboard direct into the robot key board event handle and we see the world trow the camra
* 2: the keyboard direct into the camra handle event and we also see from her
* 3:the keyboard direct to the robot and we aso see trow his eye
*/
void world::keyboard(unsigned char key)
{
	if (key == '1') {
		roby.myHead.stopSee();
		kamy.myEye();
		control = robotControl;
	}
	if (key == '2') {
		roby.myHead.stopSee();
		kamy.myEye();
		control = camraControl;
	}
	if (key == '3') {
		kamy.robotEye();
		roby.myHead.startSee();
		control = robotControl;
	}
	if (control == robotControl) {
		roby.keyBoard(key);
	}
	else if (control == camraControl) {
		kamy.keyBoard(key);
	}
}
void world::spicelKeyboard(int key) {
	if (control == robotControl) {
		roby.spicelKeyBoard(key);
	}
	else if (control == camraControl) {
		kamy.spicelKeyBoard(key);
	}
}
