#pragma once
#include <GL/freeglut.h>
# define PI       3.141592653589793238462643383279502884L
/*
* the matrial class define matrial that you can use to draw 
* there is matrial like ion that the class know and you can just set to wite the set to functions
* and if you don find matrial that you like you can use sree set function to define new matrial
*/
class matrial
{
public:
	matrial();
	//free set
	void setColor( float r, float g, float b, float a);
	void setSpectular(float r, float g, float b, float a);
	void setShine(float x);


	//set to
	void setToIron();
	void setTosteel();
	void setToCramic();
	void setToEyeMat();
	void setToGlass();
	void sertToEyeMat();
	void use();
	GLfloat color[4] = { 0,0,0,1 };
	GLfloat spect[4] = { 0,0,0,1 };
	GLfloat shine[1] = {0};
};

