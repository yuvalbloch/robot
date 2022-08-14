#pragma once
/*
* the power button hold a spectrom of brightness in the current color and use to chose they brithness
*/
#include "button.h"
class powerButton :
    public button
{
	float step;
public:
	powerButton();
	powerButton(float x_minimum, float y_minimum, float x_maximum, float y_maximum, std::string NAME);
	void draw(float r,float g,float b);
	float chosePower(int x , int y);
};

