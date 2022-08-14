#pragma once
#include <GL/glut.h>
#include <iostream>
#include <string.h>


class button
{
protected:
	
	float minX, minY, maxX, maxY;
	std::string name;
public:
	bool on ;
	button();
	button(float x_minimum, float y_minimum, float x_maximum, float y_maximum, std::string NAME);
	virtual void draw();
	bool press( int x, int y);
	void displayName();
	void off();
};

