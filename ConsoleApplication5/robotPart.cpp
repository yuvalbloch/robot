#include "robotPart.h"

void robotPart::quad(sides a , sides b ,sides c ,sides d)
{
	glVertex3d(corners[a].x, corners[a].y, corners[a].z);
	glVertex3d(corners[b].x, corners[b].y, corners[b].z);
	glVertex3d(corners[c].x, corners[c].y, corners[c].z);
	glVertex3d(corners[d].x, corners[d].y, corners[d].z);

}

void robotPart::tranform(glm::mat4 trans)
{
	for (int i = 0; i < 8; i++) {
		corners[i] = trans* corners[i] ;
	}
	glutPostRedisplay();
	glFlush();
}

void robotPart::rotateOverAxis(glm::vec3 a, glm::vec3 b ,float angle)
{
	glm::vec3 axis = b - a;
	glm::mat4 Identity = glm::mat4(1.);
	glm::mat4 translate = glm::translate(Identity, a * -1.0f);
	glm::mat4 rotate = glm::rotate(Identity, angle, axis);
	glm::mat4 transform = glm::inverse(translate) * rotate * translate;
	
	tranform(transform);
}

 robotPart::robotPart(double x0, double y0, double z0, double xSize, double ySize, double zSize) {
	corners[back_bottom_left] = glm::vec4(x0,y0,z0 ,1);
	corners[back_bottom_right] = glm::vec4(x0 +xSize, y0, z0,1);
	corners[back_top_left] = glm::vec4(x0, y0 +ySize, z0,1);
	corners[front_bottom_left] = glm::vec4(x0, y0, z0+zSize,1);
	corners[front_top_left] = glm::vec4(x0, y0 + ySize, z0 + zSize,1);
	corners[back_top_right] = glm::vec4(x0 + xSize, y0 + ySize, z0,1);
	corners[front_bottom_right] = glm::vec4(x0 + xSize, y0, z0 + zSize,1);
	corners[front_top_right] = glm::vec4(x0 + xSize, y0 + ySize,z0+ zSize,1);
		
}
robotPart::robotPart(const robotPart& r) {
	for (int i = 0; i < 8; i++) {
		corners[i] = r.corners[i];
	}
	
}

robotPart::robotPart()
{
}

void robotPart::draw()
{
	

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	quad(back_bottom_left, back_bottom_right, back_top_right, back_top_left);
	quad(front_bottom_left, front_bottom_right, front_top_right, front_top_left);
	glColor3f(0.0, 1.0, 0.0);
	quad(back_bottom_left, back_bottom_right, front_bottom_right, front_bottom_left);
	quad(back_top_left, back_top_right, front_top_right, front_top_left);
	glColor3f(0.0, 0.0, 1.0);
	quad(back_bottom_left, back_top_left, front_top_left, front_bottom_left);
	quad(back_bottom_right, back_top_right, front_top_right, front_bottom_right);
	glEnd();
	glFlush();
}


