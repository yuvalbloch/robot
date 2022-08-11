#pragma once
#include <GL/freeglut.h>
# define PI       3.141592653589793238462643383279502884L

class matrial
{
public:
	matrial();
	void setColor( float r, float g, float b, float a);
	void setSpectular(float r, float g, float b, float a);
	void setShine(float x);
	void setToIron();
	void setTosteel();
	void setToCramic();
	void use();
	GLfloat color[4] = { 0,0,0,1 };
	GLfloat spect[4] = { 0,0,0,1 };
	GLfloat shine[1] = {0};
};

