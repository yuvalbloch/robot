#include "vertex3d.h"
#include <GL/freeglut.h>
enum sides {
	front_top_left = 0, front_top_right =1, front_bottom_left =2 , front_bottom_right =3, back_top_left = 4, back_top_right = 5, back_bottom_left = 6, back_bottom_right = 7
};
class robotPart
{
private:
	myVertex3d corners[8];
	void quad(sides a, sides b, sides c, sides d);
public:
	robotPart(double x0, double yo, double z, double xSize, double ySize, double zSize);
	robotPart(const robotPart& );
	void draw();

};

