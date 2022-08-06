#include "vertex3d.h"
myVertex3d::myVertex3d()
{
	position[0] = 0;
	position[1] = 0;
	position[2] = 0;
	position[3] = 1;
	
}

myVertex3d::myVertex3d(double X, double Y, double Z )
{	
	position[0] = X;
	position[1] = Y;
	position[2] = Z;
	position[3] = 1;
}

myVertex3d::myVertex3d(const myVertex3d& v)
{
	position[0] = v.position[0];
	position[1] = v.position[1];
	position[2] = v.position[2];
	position[3] = 1;
}

myVertex3d::~myVertex3d()
{
}
//act as +=
myVertex3d& myVertex3d::operator + (myVertex3d v)
{
	position[0] += v.position[0];
	position[1] += v.position[1];
	position[2] += v.position[2];
	return *this;
}
//sct as *=
myVertex3d& myVertex3d::operator*(double d)
{
	position[0] *= d;
	position[1] *=d;
	position[2] *= d;
	return *this;
}
//sct as *=


double myVertex3d::getX()
{
	return position[0];
}

double myVertex3d::getY()
{
	return position[1];
}

double myVertex3d::getZ()
{
	return position[2];
}

void myVertex3d::printData()
{
	std::cout << "\n x = " << position[0] << "\n";
	std::cout << "\n y = " << position[1] << "\n";
	std::cout << "\n z = " << position[2] << "\n";
}
