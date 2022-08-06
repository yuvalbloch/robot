#pragma once

#include<glm/glm/glm.hpp>
#include <glm/glm/gtx/string_cast.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <GL/freeglut.h>
#include<iostream>
#include <math.h>
# define PI       3.141592653589793238462643383279502884L
/*
* the robot part are boxes that use to assmble the robot
* every body part made of 8 vertex3d one for every corner
* the side of the robotPart made in diffrent color for orintion:
* front and back red, top and bottom green sides blue
*/
enum sides {
	front_top_left = 0, front_top_right =1, front_bottom_left =2 , front_bottom_right =3, back_top_left = 4, back_top_right = 5, back_bottom_left = 6, back_bottom_right = 7
};
class robotPart
{
protected:
	void quad(sides a, sides b, sides c, sides d);
	void tranform(glm::mat4 trans);
public:
	glm::vec4 corners[8];
	robotPart(double x0, double y0, double z0, double xSize, double ySize, double zSize);
	robotPart(const robotPart& );
	robotPart();
	virtual void draw();
	void rotateOverAxis(glm::vec3 a, glm::vec3 b, float angle);


};

