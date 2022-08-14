#include<GL/freeglut.h>
#include"matrialList.h"
/*
* the room the the area where the robot can move
it made of 2 walls that reprasnt the furthe edge of the room and floor made out of squre that help for orintion
*/
class room
{
private:
	float size = 400;
	void drawWalls();
	void drawFloor();
	void drawWindows();
	void createCilingLight(GLfloat lightPos0[4], int lightNum);
	void createAmbidentLight();
public:
	room();
	void createLight();
	void drawRoom();


};

