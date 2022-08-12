#pragma once
#include <GL/glut.h>
#include <iostream>

class button
{
private:
	float minX, minY, maxX, maxY;
public:
	button();
	button(float x_minimum, float y_minimum, float x_maximum, float y_maximum);
	void draw();
	bool press( int x, int y);
};

