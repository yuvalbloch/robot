#pragma once

#include "button.h"
#include <iostream>
#include "colorButton.h"
#include <string>
#include "powerButton.h"
#include "text.h"
enum page { greeting , helpPage , lightPannal };
class instractionWindow
{
private:
	// light color setter information
	float  r =0.5, g =0.5, b=0.5, power =1.0; 
	int lightNum = 0;
	int lightAmount = 4;
	button light[4];

	//window size
	int height = 550, width = 200;

	// window
	int  winId, world;

	//get index and return light
	int LightID();  
	//the currntt page is the page that rander on the window
	page current = greeting;

	//function for greeting page 
	void displayGreeting();

	//function for light pannal page
	void displayLightPannal();
	//function for the help page
	void display_help_page();
	
	//the button are on when they display what mean that you push them and this function use to shout them off
	void offAllButton();


public:
	//initilaize and setUp 
	instractionWindow();
	void init();
	void setUp(int id, int world);


	//runtime function
	void display();
	int mouseFunc(int button , int state , int x, int y);

private:
	/*
	* -----------------------------------------------------------------------------------------------------
	* button list
	* -----------------------------------------------------------------------------------------------------
	*/
	button exit = button(20, 20, 120, 60, "exit");
	button adujt_light= button(20, 80, 120, 120, "adujt light");
	button help =  button(20, 140, 120, 180, "help");
	button back =  button(20, 20, 120, 60, "back");
	button applay = button(20, 80, 120, 120, "applay");
	colorButton color = colorButton(20, 200, 180, 360, "color");
	powerButton lightPower = powerButton(20, 140, 180, 180,"lightPower");
	button smallBack = button(80, 20, 140, 60, "back");
	/*
	* -----------------------------------------------------------------------------------------------------
	* text list
	* -----------------------------------------------------------------------------------------------------
	*/
	text greetingText = text("hallo I am roby the labratory robot and I her to help you navigate trow my lab what do you want to do:",10, height -20 );
	text choselightText = text("in my lab there is 4 light ball which one do you want to adjust:", 10, height - 20);
	text choseColorText = text("chose color:", 10, 390);
	text helpText = text("In the lab you control things through the keyboard "
		"tere are 3 control state that you chose using the number keys "
		" 1 use to conrl the robot. keys [a,s,d,w]  rotate the head "
		"keys [u,j,i,k,o,l]  rotate the hand and the arrow  move the robot. "
		"2 use to control the camra  [a,s,w,d] rotate [+,-] move in and out and the arrows move around. "
		"after you press 3 you see the world through the eyes of the robot", 10, height - 20);
};

