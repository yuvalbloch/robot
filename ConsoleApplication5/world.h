#pragma once
#include <stdlib.h>
#include<GL/freeglut.h>
#include "include\GL\glui.h"
#include "room.h"
#include "robotPart.h"
#include "head.h"
#include "robot.h"
#include "camra.h"
/*
* the world hold the robot the room and the camra its draw the objects
* it also bouild to direct the key board event to the current object  in refrence to the state  
*/
class world
{
public:
	enum control { robotControl  , camraControl};
	GLint winHigh, WinWidth ; //window size
	robot roby ;
	camra kamy ;
	room lab;
	bool control;
	world();
	void setUp();
	void display();
	void Init(void);
	void keyboard(unsigned char key);
	void spicelKeyboard(int key);
};

