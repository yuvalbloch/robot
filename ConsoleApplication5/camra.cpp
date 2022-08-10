#include "camra.h"
#include<iostream>
#include "robotPart.h"
/* 
* the camra constructor set up the position of the camra ans its dirction
* to first values that give us a comfarble way to see the robot 
*/
camra::camra() {
	eyePostion = glm::vec4(120.0, 50.0, 120.0, 1.0);
	refPostion = glm::vec4(0.0, 0.0, 0.0, 1.0);
	upVector = glm::vec4(0.0, 1.0, 0.0, 1.0);
	xwMin = -16.0, ywMin = -16.0, xwMax = 16.0, ywMax = 16.0;
	dnear = 10, dfar = 400;
	yAxis = 0;
}
/*
* the rander function use the current values of the camra to set up the look of the world
*/
void camra::rander()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyePostion.x, eyePostion.y, eyePostion.z, refPostion.x, refPostion.y, refPostion.z, upVector.x, upVector.y, upVector.z);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 1, dnear, dfar);
}

//************************************************the tranformation function******************
void camra::rotate_to_side(float angle) {
	rotate(angle, (eyePostion + upVector), eyePostion);
}
void camra::rotate_up_down(float angle) {
	if (yAxis + angle <PI / 2 && yAxis + angle >(-0.5) * PI) {
		glm::vec4 axis(1.0);
		vecMultyple(&axis, (eyePostion - refPostion), upVector);
		axis = axis + eyePostion;
		yAxis += angle;
		rotate(angle, axis, eyePostion);
	}

}

void camra::rotate(float angle , glm::vec4 a, glm::vec4 b)
{
	glm::vec4 axis(1.0f);
	glm::mat4 trans = glm::mat4(1.0);
	matrix_for_rotation_over_axis(&trans, a, b, angle);
	refPostion = trans * refPostion ;
}
void camra::moveForwerd(float way) {
	eyePostion += ((glm::normalize(refPostion - eyePostion)) * way);
}

//************************************************utilty for tranformation****************************************


void camra::matrix_for_rotation_over_axis(glm::mat4* output, glm::vec3 a, glm::vec3 b, float angle)
{
	glm::vec3 axis = b - a;
	glm::mat4 Identity = glm::mat4(1.0);
	glm::mat4 translate = glm::translate(Identity, a * -1.0f);
	glm::mat4 rotate = glm::rotate(Identity, angle, axis);
	*output = glm::inverse(translate) * rotate * translate;

}
void camra::vecMultyple(glm::vec4* targt, glm::vec4 a, glm::vec4 b)
{
	targt->x = (a.y * b.z) - (a.z * b.y);
	targt->y = (a.x * b.z) - (a.z * b.x);
	targt->z = (a.x * b.y) - (a.y * b.x);
}

void camra::keyBoard(unsigned char key)
{
	switch(key){
	case 'a':
		rotate_to_side(0.02);
		break;
	case 'd':
		rotate_to_side(-0.02);
		break;
	case 's':
		rotate_up_down(0.02);
		break;
	case 'w':
		rotate_up_down(-0.02);
		break;
	case '+':
		moveForwerd(1);
		break;
	case '-':
		moveForwerd(-1);
		break;
	}
	rander();
	glutPostRedisplay();
	glFlush();
		
}
void camra::spicelKeyBoard(unsigned char key) {
//	std::cout << key;
}

