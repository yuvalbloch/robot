#include "robot.h"
/*
* the costractor collect the data fot rhe body and also create 2 new pices
* one is the head that put above the middle of the body 
* and one is the arm that put beside the middle of the body
*/
robot::robot(double x0, double y0, double z0, double sX, double sY, double sZ) : robotPart(x0, y0  , z0, sX, sY, sZ) {
	myHead = head(x0 + sX * (0.2), y0 + sY, z0 + sZ * 0.2, sX * 0.6, sY / 2, sZ * 0.6);
	myArm = arm(x0 + sX, y0 + sY / 2, z0 + sZ / 2, sX / 4,  sY / 4, sZ * 2);
}
robot::robot() {

}
// the draw call the draw function for evey one of the part
void robot::draw()
{
	matrial steel = matrial();
	steel.setTosteel();
	glMaterialfv(GL_FRONT, GL_SPECULAR, steel.spect);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, steel.color);
	robotPart::draw();
	myHead.draw();
	myArm.draw();

}
/*
* the body capble of 2 transformation one is rotate over axis that parlal to y axis and put in its middle
* the other is move forward or backward (of course forward and backward difine by its current dirction
*/
void robot::rotate(float angle) {
	glm::vec3 mid = (corners[front_bottom_right] + corners[front_bottom_left] + corners[back_bottom_right] + corners[back_bottom_left]) / 4.0f;
	glm::mat4 transformMat = glm::mat4(1.0f);
	utility::matrix_for_rotation_over_axis(&transformMat, mid, mid + glm::vec3(0, 1, 0), angle);
	if (myArm.checkCollision(transformMat) && checkCollision(transformMat)) {
		tranform(transformMat);
		myArm.tranform(transformMat);
		myHead.transformWithNeck(transformMat);
	}
}
void robot::move(float fari) {
	glm::vec3 dirctionVector = (corners[back_bottom_left] - corners[front_bottom_left]) * fari;
	glm::mat4 translate = glm::translate(glm::mat4(1.0), dirctionVector);
	if (checkCollision(translate) && myArm.checkCollision(translate) && myHead.checkCollision(translate)) {
		tranform(translate);
		myArm.tranform(translate);
		myHead.transformWithNeck(translate);
	}
}
/*
* the key board control system are split to 2 diffrent function keyboard and spaciel keyboard 
* the keyboard handle chrcter key and use to rotate the hand and the arm 
* the spicel keyboard handle the arrows key and use to move and rotate the body
* the reason for the split lay in the way that open gl handle keyboard event
*/
void robot::keyBoard(unsigned char key)
{
	switch (key) {
	case 's':
		myHead.rotate_up_down(-0.2);
		break;
	case 'w':
		myHead.rotate_up_down(0.2);
		break;
	case 'a':
		myHead.rotate_left_right(-0.2);
		break;
	case 'd':
		myHead.rotate_left_right(0.2);
		break;
	case 'u':
		myArm.rotate_shuolder(0.2);
		break;
	case 'j':
		myArm.rotate_shuolder(-0.2);
		break;
	case 'i':
		myArm.rotate_elbow(0.2);
		break;
	case 'k':
		myArm.rotate_elbow(-0.2);
		break;
	case 'l':
		myArm.rotate_hand(0.2);
		break;
	case 'o':
		myArm.rotate_hand(-0.2);
		break;
	}

	glutPostRedisplay();
}
void robot::spicelKeyBoard(unsigned char key){
	switch (key) {
	case GLUT_KEY_UP:
		move(-0.1);
		break;
	case GLUT_KEY_DOWN:
		move(0.1);
		break;
	case GLUT_KEY_LEFT:
		rotate(0.1);
		break;
	case GLUT_KEY_RIGHT:
		rotate(-0.1);
		break;
	}
	glutPostRedisplay();
}
