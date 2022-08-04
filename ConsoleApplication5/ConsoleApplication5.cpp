
//#include "vertex3d.h"
#include<GL/freeglut.h>
#include "vertex3d.h"
#include "room.h"
#include "robotPart.h"
GLint winHigh = 600, WinWidth = 1200; //window size

//set the "camara" position

GLfloat x0 = 120.0, Y0 = 50.0, z0 = 120.0; // origin cordinate
GLfloat xref = 0.0, yref = 0.0, zref = 1.0;// refrence vector
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0;

//set the clliping window position
GLfloat xwMin = -16.0, ywMin = -16.0, xwMax = 16.0, ywMax = 16.0;

//set the depth of the clliping
GLfloat dnear = 15, dfar = 32;

void Init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(x0, Y0, z0, xref, yref, zref, Vx, Vy, Vz);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(90, 1, 0, 50);
    glLineWidth(4.0);
}
void display() {
    glColor3f(0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //draw the room
    room lab = room();
    lab.drawRoom();
    robotPart body = robotPart(50, 0, 50, 20, 30, 20);
    body.draw();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WinWidth, winHigh);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("let see if it work");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



