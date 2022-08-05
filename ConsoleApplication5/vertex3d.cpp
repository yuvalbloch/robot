#include "vertex3d.h"

myVertex3d::myVertex3d()
{
	x = 0; y = 0; z = 0;
}

myVertex3d::myVertex3d(double X, double Y, double Z )
{	
	x = X;
	y = Y;
	z = Z;
}

myVertex3d::myVertex3d(const myVertex3d& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

myVertex3d::~myVertex3d()
{
}
//act as +=
myVertex3d& myVertex3d::operator + (myVertex3d v)
{
	x = x+ v.x;
	y = y+ v.y;
	z =z+  v.z;
	return *this;
}
//sct as *=
myVertex3d& myVertex3d::operator*(double d)
{
	x *= d;
	y *= d;
	z *= d;
	return *this;
}
//sct as *=
myVertex3d& myVertex3d::operator*(myVertex3d v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

void myVertex3d::printData()
{
	std::cout << "\n x = " << x << "\n";
	std::cout << "\n y = " << y << "\n";
	std::cout << "\n z = " << z << "\n";
}
