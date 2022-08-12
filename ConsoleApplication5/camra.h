#pragma once
#include "utility.h"
#include<GL/freeglut.h>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtx/string_cast.hpp>
#include<iostream>
#include"matrialList.h"
#include "robot.h"
/*
* the camra difine how the user will see the world its have postion vector, dirction vector and vector that tell her where is up
* the view emulate the way that the virtual world look in an imge that took in real camra that place where the virtual camra lay camra lay in
* the cmarmra can move and rotate by user command
* 
*/
class camra
{
private:
	float yAxis;
	//set the camara position
	glm::vec4 eyePostion;
	glm::vec4 refPostion;// refrence vector
	glm::vec4 upVector;
	//the clliping window position
	GLfloat xwMin , ywMin , xwMax , ywMax;
	//set the depth of the clliping
	GLfloat dnear , dfar ;
	enum type  { up_down , side ,robot_eye , normal_eye };
public:
	int state = normal_eye;
	void rander();
	camra();
	void robotEye();
	/* 
	* transformation:
	* the camra cna raotat what mean tha the dirction that it look to will change
	* and it can move what mean that the place that we look from will change
	* the moving dirction is in relateat to to dirction that we look to
	*/
	void rotate(float angle , glm::vec4 a, glm::vec4 b);
	void rotate_up_down(float angle);
	void rotate_to_side(float angle);
	void moveForwerd(float way);
	void moveAside(float way);





	//key board event
	void keyBoard(unsigned char key);
	void spicelKeyBoard(unsigned char key);


};

