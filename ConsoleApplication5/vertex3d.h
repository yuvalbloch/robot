#include <iostream>
#include<glm/glm/glm.hpp>
#pragma once
/*
* vertex are the foundomantal building blocks of the program
* they reprasent point in the space made from 3 dordinate that give as double
* you can do a vector oprtion on vertex
*/
class myVertex3d
{
public:
	glm::vec4 position;
	myVertex3d();
	myVertex3d(double x, double y, double z );
	myVertex3d( const myVertex3d&);
	~myVertex3d();
	myVertex3d& operator + (myVertex3d); // act as += of vector
	myVertex3d& operator * (double); // act as *= of vector
	double getX();
	double getY();
	double getZ();
	
		void printData();


};

