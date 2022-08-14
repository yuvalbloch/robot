#include "matrialList.h"

matrial::matrial()
{	
}
/*
* applay the matrial to everything that came after that
*/
void matrial::use()
{
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
	glMaterialfv(GL_FRONT, GL_SPECULAR, spect);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
}
/*-----------------------------------------------------------------------------
* free set functions: set the parmter of matrial use to define color that doesnt save in the set to functions
* --------------------------------------------------------------------------
*/
void matrial::setColor(float r, float g, float b, float a)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3]  = a;
}
void matrial::setSpectular(float r, float g, float b, float a)
{
	spect[0] = r;
	spect[1] = g;
	spect[2] = b;
	spect[3] = a;
}
void matrial::setShine(float x)
{
	shine[0] = x;
}
/*------------------------------------------------------------------------
* set to functions: use to set matrial to one of the matrial that the class allready know
* ------------------------------------------------------------------------
*/
void matrial::setToIron()
{
	setColor(0.2f, 0.1f, 0.1f, 1.0f);
	setSpectular(0.1f, 0.1f, 0.1f, 1.0f);
	setShine(10.0);
}

void matrial::setTosteel()
{
	setColor(0.4f, 0.65f, 0.75f, 1.0f);
}

void matrial::setToCramic()
{
	setColor(0.3f, 0.5f, 0.7f, 1.0f);
	setSpectular(0.1f, 0.1f, 0.1f, 1.0f);
	setShine(20.0);
}
void matrial::setToEyeMat() {
	setColor( 1.0f, 0.0f, 0.0f, 1.0f );
	setSpectular(0.2f, 0.2f, 0.2f, 1.0f);
	setShine(3.0);

}
void matrial::setToGlass() {
	setColor(0.1f, 0.4f, 0.6f, 0.4f);
	setSpectular(0.5f, 0.5f, 0.5f, 1.0f);
	setShine(20.0);

}

