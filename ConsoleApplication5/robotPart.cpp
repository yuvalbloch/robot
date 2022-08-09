#include "robotPart.h"



//constructors********************************************************************************************************************
 
/*
* the purpuse of the construcrtro is to set up the coridnate of the coenres
* the data get as one point (x0,y0,z0) this is the back left bootom corner
* and tree double (xSize ,ySize ,zSize) that tell how the box screch from those point
*/ 
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
//copy construcor
robotPart::robotPart(const robotPart& r) {
	for (int i = 0; i < 8; i++) {
		corners[i] = r.corners[i];
	}
	
}
//defult constructor use only to set up pointers
robotPart::robotPart()
{

}


//make the appernce****************************************************************************************************************************************************
/*
*the qoud is the foundomantal peaceof the robot part 
* it just a qoud draw from 3 corners in one color
*/ 
void robotPart::quad(sides a, sides b, sides c, sides d)
{
	glm::vec3  normal = findNormal(a);
	glNormal3f(normal.x, normal.y, normal.z);
	glVertex3d(corners[a].x, corners[a].y, corners[a].z);
	normal = findNormal(b);
	glNormal3f(normal.x, normal.y, normal.z);
	glVertex3d(corners[b].x, corners[b].y, corners[b].z);
	normal = findNormal(c);
	glNormal3f(normal.x, normal.y, normal.z);
	glVertex3d(corners[c].x, corners[c].y, corners[c].z);
	normal = findNormal(d);
	glNormal3f(normal.x, normal.y, normal.z);
	glVertex3d(corners[d].x, corners[d].y, corners[d].z);

}
/*
* the draw is the rander function of the robot part it create 1 box from 8 qoud 
* the qoud pear to couples paint in the same color 
* back front
* top bottom
* left right
*/
void robotPart::draw()
{
	glBegin(GL_QUADS);
	GLfloat materialColorBF[] = { 0.4f, 0.2f, 0.2f, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialColorBF);
	quad(back_bottom_left, back_bottom_right, back_top_right, back_top_left);
	quad(front_bottom_left, front_bottom_right, front_top_right, front_top_left);
	GLfloat materialColorTB[] = { 0.5f, 0.35f, 0.35f, 1.0f };
	quad(back_bottom_left, back_bottom_right, front_bottom_right, front_bottom_left);
	quad(back_top_left, back_top_right, front_top_right, front_top_left);
	GLfloat materialColorSide[] = { 0.4f, 0.3f, 0.3f, 1.0f };
	quad(back_bottom_left, back_top_left, front_top_left, front_bottom_left);
	quad(back_bottom_right, back_top_right, front_top_right, front_bottom_right);
	glEnd();
	glFlush();
}
/*
* the find normal function get index for one of the corners and return vector that reprasen its normal
* the normal of the corner is the opsite vector to the avrge of the tree vector that meet in him becouse its a box
* and all the vector meet in 90 degree that method give the same result as the normals averge that use in the phong Ilumntion method
*/
glm::vec4 robotPart::findNormal(sides side)
{
	switch (side) {
	case front_top_left:
		return corners[front_top_right] + corners[front_bottom_left] + corners[back_top_left] - (corners[front_top_left] * 3.0f);
	case front_top_right:
		return corners[front_top_left] + corners[front_bottom_right] + corners[back_top_right] - (corners[front_top_right] * 3.0f);
	case front_bottom_left:
		return corners[front_bottom_right] + corners[front_top_left] + corners[back_bottom_left] - (corners[front_bottom_left] * 3.0f);
	case front_bottom_right:
		return corners[front_bottom_left] + corners[front_top_right] + corners[back_bottom_right] - (corners[front_bottom_right] * 3.0f);
	case back_top_left:
		return corners[back_top_right] + corners[back_bottom_left] + corners[front_top_left] - (corners[back_top_left] * 3.0f);
	case back_top_right:
		return corners[back_top_left] + corners[back_bottom_right] + corners[front_top_right] - (corners[back_top_right] * 3.0f);
	case back_bottom_left:
		return corners[back_bottom_right] + corners[back_top_left] + corners[front_bottom_left] - (corners[back_bottom_left] * 3.0f);
	case back_bottom_right:
		return corners[back_bottom_left] + corners[back_top_right] + corners[front_bottom_right] - (corners[back_bottom_right] * 3.0f);
	}
	return corners[back_bottom_left] + corners[back_top_right] + corners[front_bottom_right] - (corners[back_bottom_right] * 3.0f);
}

//transform*********************************************************** **************************************************************************************
//
bool robotPart::rotateOverAxis(glm::vec3 a, glm::vec3 b, float angle)
{

	glm::mat4 transform = glm::mat4(1.0);
	matrix_for_rotation_over_axis(&transform, a, b, angle);
	if (checkCollision(transform)) {
		tranform(transform);
		return true;
	}
	else {
		return false;
	}
}
void robotPart::matrix_for_rotation_over_axis(glm::mat4 *output,glm::vec3 a, glm::vec3 b, float angle)
{
	glm::vec3 axis = b - a;
	glm::mat4 Identity = glm::mat4(1.);
	glm::mat4 translate = glm::translate(Identity, a * -1.0f);
	glm::mat4 rotate = glm::rotate(Identity, angle, axis);
	*output = glm::inverse(translate) * rotate * translate;

}
bool robotPart::tranform(glm::mat4 trans)
{
	if (checkCollision(trans)) {
		for (int i = 0; i < 8; i++) {
			corners[i] = trans * corners[i];
		}
		glutPostRedisplay();
		glFlush();
		return true;
	}
	return false;

}
// rturn true if there isnt collision risk and the tranformtion can happend freely
bool robotPart::checkCollision(glm::mat4 trans)
{
	for (int i = 0; i < 8; i++) {
		if ((trans * corners[i]).x < 0 || (trans * corners[i]).z < 0 || (trans * corners[i]).x > 200 || (trans * corners[i]).z > 200 || (trans * corners[i]).y < 0) {
			return false;
		}
	}
	return true;
}