#pragma once
#include <GL/glut.h>
#include <iostream>
#include <string.h>
/*
* the text class hold text and its postion and use for draw
*/
class text
{
	int x0;
	int y0;
	std::string theText;
public:
	text(std::string newText, int x, int y);
	void draw(int maxX);
};

