#include "robotPart.h"

void robotPart::quad(sides a , sides b ,sides c ,sides d)
{
	glVertex3d(corners[a].x, corners[a].y, corners[a].z);
	glVertex3d(corners[b].x, corners[b].y, corners[b].z);
	glVertex3d(corners[c].x, corners[c].y, corners[c].z);
	glVertex3d(corners[d].x, corners[d].y, corners[d].z);

}

 robotPart::robotPart(double x0, double y0, double z0, double xSize, double ySize, double zSize) {
	corners[back_bottom_left] = myVertex3d(x0,y0,z0);
	corners[back_bottom_right] = myVertex3d(x0 +xSize, y0, z0);
	corners[back_top_left] = myVertex3d(x0, y0 +ySize, z0);
	corners[front_bottom_left] = myVertex3d(x0, y0, z0+zSize);
	corners[front_top_left] = myVertex3d(x0, y0 + ySize, z0 + zSize);
	corners[back_top_right] = myVertex3d(x0 + xSize, y0 + ySize, z0);
	corners[front_bottom_right] = myVertex3d(x0 + xSize, y0, z0 + zSize);
	corners[front_top_right] = myVertex3d(x0 + xSize, y0 + ySize,z0+ zSize);
		
}
robotPart::robotPart(const robotPart& r) {
	for (int i = 0; i < 8; i++) {
		corners[i] = r.corners[i];
	}
	
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
