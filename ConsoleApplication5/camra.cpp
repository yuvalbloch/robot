#include "camra.h"

/* 
* the camra constructor set up the position of the camra ans its dirction
* to first values that give us a comfarble way to see the robot 
*/
camra::camra() {
	eyePostion = glm::vec4(200.0, 100.0, 200.0, 1.0);
	refPostion = glm::vec4(0.0, 0.0, 0.0, 1.0);
	upVector = glm::vec4(0.0, 1.0, 0.0, 1.0);
	xwMin = -16.0, ywMin = -16.0, xwMax = 16.0, ywMax = 16.0;
	 dnear = 5, dfar = 800;

	yAxis = 0;
}
/*
* the rander function use the current values of the camra to set up the look of the world
*/
void camra::rander()
{
	if (state == normal_eye) {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eyePostion.x, eyePostion.y, eyePostion.z, refPostion.x, refPostion.y, refPostion.z, upVector.x, upVector.y, upVector.z);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(90, 1, dnear, dfar);
	}
	else if (state == robot_eye) {

	}
}
void camra::robotEye()
{
	state = robot_eye;
	rander();
}
void camra::myEye() {
	state = normal_eye;
	rander();
}
//************************************************the tranformation function******************
void camra::rotate_to_side(float angle) {
	rotate(angle, (eyePostion + upVector), eyePostion);
}
void camra::rotate_up_down(float angle) {
	if (yAxis + angle <PI / 2 && yAxis + angle >(-0.5) * PI) {
		glm::vec4 axis(1.0);
		utility::vecMultyple(&axis, (eyePostion - refPostion), upVector);
		axis = axis + eyePostion;
		yAxis += angle;
		rotate(angle, axis, eyePostion);
	}

}

void camra::rotate(float angle , glm::vec4 a, glm::vec4 b)
{
	glm::vec4 axis(1.0f);
	glm::mat4 trans = glm::mat4(1.0);
	utility::matrix_for_rotation_over_axis(&trans, a, b, angle);
	refPostion = trans * refPostion ;
}
void camra::moveForwerd(float way) {
	eyePostion += ((glm::normalize(refPostion - eyePostion)) * way);
}

void camra::moveAside(float way) {
	glm::vec4 dirction(1.0);
	utility::vecMultyple(&dirction, (eyePostion - refPostion), upVector);
	dirction= glm::normalize(dirction);
	eyePostion += (dirction * way);
}
//************************************************keyBoard event handle****************************************



void camra::keyBoard(unsigned char key)
{
	switch(key){
	case 'a':
		rotate_to_side(-0.02);
		break;
	case 'd':
		rotate_to_side(0.02);
		break;
	case 's':
		rotate_up_down(-0.02);
		break;
	case 'w':
		rotate_up_down(0.02);
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
	switch (key) {
	case GLUT_KEY_UP:
		eyePostion+= upVector;
		break;
	case GLUT_KEY_DOWN:
		eyePostion = eyePostion -  upVector;
		break;
	case GLUT_KEY_LEFT:
		moveAside(1);
		break;
	case GLUT_KEY_RIGHT:
		moveAside(-1);
		break;
	}
	rander();
	glutPostRedisplay();
	glFlush();
}

