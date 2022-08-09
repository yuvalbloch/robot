#include "room.h"

void room::drawWalls()
{
    GLfloat materialColor[] = { 0.4f, 0.65f, 0.75f, 1.0f }; 
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialColor);
    glBegin(GL_POLYGON);
    glNormal3i(1, 0, 0);
    glVertex3f(0.0,-1.0, 0.0);
    glVertex3f(0.0,-1.0, 200.0);
    glVertex3f(0.0, 200.0, 200.0);
    glVertex3f(0.0, 200.0, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glNormal3i(0, 0, 1);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(200.0,-1.0, 0.0);
    glVertex3f(200.0, 200.0, 0.0);
    glVertex3f(0.0, 200.0, 0.0);
    glEnd();
}

void room::drawFloor()
{
    //The color of the sphere
    GLfloat materialColor[] = { 0.4f, 0.6f, 0.8f, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialColor);
    glBegin(GL_POLYGON);
    glNormal3i(0, 1, 0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(0.0, -1.0, 200.0);
    glVertex3f(200.0, -1.0, 200.0);
    glVertex3f(200.0, -1.0, 0.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    for (int i = -0; i <= 20; i++) {
        glVertex3f(10 * i, 0.0, 0.0);
        glVertex3f(10 * i, 0.0, 200.0);
        glVertex3f(0.0, 0.0, 10 * i);
        glVertex3f(200.0, 0.0, 10 * i);
    }
    glEnd();
}

void room::createCilingLight(GLfloat lightPos0[4] , int lightNum)
{
    GLfloat lightColor0[] = { 0.5f, 0.4f, 0.4f, 1.0f }; //cream color
    glLightfv(lightNum, GL_DIFFUSE, lightColor0);
    glLightfv(lightNum, GL_POSITION, lightPos0);
    glEnable(lightNum);
}

void room::drawRoom()
{
 
    GLfloat lightPos0[4] = { 100, 80,100, 1.0f }; //above room center
    createCilingLight(lightPos0, GL_LIGHT0);
    GLfloat lightPos1[4] = { 200, 80,200, 1.0f }; //front corner
    createCilingLight(lightPos1, GL_LIGHT1);
    GLfloat lightPos2[4] = { 10, 80,200, 1.0f }; //side
    createCilingLight(lightPos2, GL_LIGHT2);
    GLfloat lightPos3[4] = { 200, 80,10, 1.0f }; //side
    createCilingLight(lightPos3, GL_LIGHT3);
    GLfloat lightPos4[4] = { 10, 80,0, 1.0f }; //back
    createCilingLight(lightPos4, GL_LIGHT4);

    drawFloor();
    drawWalls();
}
