#include "matrialList.h"

matrial::matrial()
{	
}

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

void matrial::setToIron()
{
	setColor(0.2f, 0.1f, 0.1f, 1.0f);
	setSpectular(0.2f, 0.2f, 0.2f, 1.0f);
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

void matrial::use()
{
	glMaterialfv(GL_FRONT, GL_SHININESS, shine);
	glMaterialfv(GL_FRONT, GL_SPECULAR, spect);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
}
