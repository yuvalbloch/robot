#include "room.h"

void room::drawWalls()
{
    glColor3f(0.3,0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 100.0);
    glVertex3f(0.0, 100.0, 100.0);
    glVertex3f(0.0, 100.0, 0.0);
    glEnd();
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glVertex3f(100.0, 100.0, 0.0);
    glVertex3f(0.0, 100.0, 0.0);
    glEnd();
}

void room::drawFloor()
{
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(0.0, -1.0, 100.0);
    glVertex3f(100.0, -1.0, 100.0);
    glVertex3f(100.0, -1.0, 0.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    for (int i = 0; i <= 10; i++) {
        glVertex3f(10 * i, 0.0, 0.0);
        glVertex3f(10 * i, 0.0, 100.0);
        glVertex3f(0.0, 0.0, 10 * i);
        glVertex3f(100.0, 0.0, 10 * i);
    }
    glEnd();
}

void room::drawRoom()
{
    drawFloor();
    drawWalls();
}
