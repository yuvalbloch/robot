
#include<GL/freeglut.h>
#include "room.h"
#include "robotPart.h"
#include "head.h"
#include "robot.h"

GLint winHigh = 600, WinWidth = 1200; //window size

//set the "camara" position

GLfloat x0 = 120.0, Y0 = 50.0, z0 = 120.0; // origin cordinate
GLfloat xref = 0.0, yref = 0.0, zref = 1.0;// refrence vector
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0;

//set the clliping window position
GLfloat xwMin = -16.0, ywMin = -16.0, xwMax = 16.0, ywMax = 16.0;

//set the depth of the clliping
GLfloat dnear = 15, dfar = 32;
robot roby =  robot(50, 0, 50, 20, 30, 20);

void keyboard(unsigned char key, int x, int y) {

    roby.keyBoard(key);
}
void spicelKeyboard(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        roby.move(-0.1);
        break;
    case GLUT_KEY_DOWN:
        roby.move(0.1);
        break;
    case GLUT_KEY_LEFT:
        roby.rotate(0.1);
        break;
    case GLUT_KEY_RIGHT:
        roby.rotate(-0.1);
        break;
    }
    glutPostRedisplay();
}
void Init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(x0, Y0, z0, xref, yref, zref, Vx, Vy, Vz);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(90, 1, 10, 250);
    glLineWidth(4.0);
    glEnable(GL_DEPTH_TEST);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(spicelKeyboard);
}
void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    //draw the room
    room lab = room();
    lab.drawRoom();
    roby.draw();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize(WinWidth, winHigh);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("let see if it work");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



