#pragma once
#include "button.h"
/*
* the color button hold 2 dimnsion spectrom of colors in the current britness and use to chosse color
*/
class colorButton : public button
{
public:
	float xStep;
	float yStep;
	colorButton();
	colorButton(float x_minimum, float y_minimum, float x_maximum, float y_maximum, std::string NAME);
	void draw(float power) ;
	void choseColor(float *r , float *g, float *b , int x, int y);

	
};

