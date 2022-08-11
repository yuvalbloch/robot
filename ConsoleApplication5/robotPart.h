#pragma once

#include<glm/glm/glm.hpp>
#include <glm/glm/gtx/string_cast.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <GL/freeglut.h>
#include<iostream>
#include <math.h>
#include"matrialList.h"
/*
* the robot part are boxes that use to assmble the robot
* every body part made of 8 glm vector one for every corner
* the side of the robotPart made in diffrent color for orintion:
* front and back red, top and bottom green sides blue
*/

enum sides {
	front_top_left = 0, front_top_right =1, front_bottom_left =2 , front_bottom_right =3, back_top_left = 4, back_top_right = 5, back_bottom_left = 6, back_bottom_right = 7
};
class robotPart
{
protected:

	//take four "sides" enum as indexes for corners and draw qoud batwin them
	void quad(sides a, sides b, sides c, sides d);
	// run of all the corners in the body part and trnfrom them by multypull in matrix 
public:
	glm::vec4 corners[8];
	//constractors
	robotPart(double x0, double y0, double z0, double xSize, double ySize, double zSize);
	robotPart(const robotPart& );
	robotPart();
	//rander function
	virtual void draw();
	//transformtiom
	/*
	*use to rotate the body part around any axis in the space
	* the axis difine with 2 point a and b that on it 
	* a and be can be any 2 diffrent point on the axis
	*/
	bool rotateOverAxis(glm::vec3 a, glm::vec3 b, float angle);
	void matrix_for_rotation_over_axis(glm::mat4* output, glm::vec3 a, glm::vec3 b, float angle);
	virtual bool checkCollision(glm::mat4 trans);
	glm::vec4 findNormal(sides);
	bool tranform(glm::mat4 trans);

};

