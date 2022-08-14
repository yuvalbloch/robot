#include "text.h"

text::text(std::string newText, int x, int y)
{
	x0 = x;
	y0 = y;
	theText = newText;
}

void text::draw(int maxX)
{
	glColor3f(0.0, 0.0, 0.0);
	std::cout << y0;
	glRasterPos2f(x0 , y0);
	int line = 0;
	for (int i = 0; i < theText.length(); i++) {
		std::cout << theText[i];
		int rasterpos[4];
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, theText[i]);
		glGetIntegerv(GL_CURRENT_RASTER_POSITION, rasterpos);
		if (rasterpos[0] > maxX-80 && theText[i] == ' ') {
			line++;
			glRasterPos2f(x0, y0 - line*20);

		}

		
	}
	glFlush();
}
