#pragma once
#include<GL/freeglut.h>
#include "room.h"
#include "robotPart.h"
#include "head.h"
#include "robot.h"
#include "camra.h"

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
	void display();
	void Init(void);
	void keyboard(unsigned char key);
	void spicelKeyboard(int key);
};

