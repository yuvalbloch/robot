#include <iostream>
#pragma once

class myVertex3d
{
public:
	double x, y, z;
	myVertex3d();
	myVertex3d(double x, double y, double z );
	myVertex3d( const myVertex3d&);
	~myVertex3d();
	myVertex3d operator + (myVertex3d);
	myVertex3d operator * (double);
	myVertex3d operator * (myVertex3d);
	
		void printData();


};

