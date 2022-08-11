#include "room.h"

void room::drawWalls()
{
    GLfloat materialColor[] = { 0.4f, 0.65f, 0.75f, 1.0f }; 
    GLfloat wallSpect[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, wallSpect);
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
    //The color of the squere
    GLfloat FloorColor[] = { 0.3f, 0.5f, 0.7f, 1.0f };
    GLfloat FloorSpect[] = { 0.1f, 0.1f, 0.1f, 1.0f };
    GLfloat LineCOLOR[] = { 0.0f, 0.0f, 0.0f, 0.0f };
    GLfloat mat_shininess[] = { 20.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, FloorColor);
    glBegin(GL_POLYGON);
    glNormal3i(0, 1, 0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(0.0, -1.0, 200.0);
    glVertex3f(200.0, -1.0, 200.0);
    glVertex3f(200.0, -1.0, 0.0);
    glEnd();
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, FloorColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, FloorSpect);
    glBegin(GL_QUADS);
    GLfloat squreColor[] = { 0.3f, 0.5f, 0.7f, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, squreColor);
    float slot = 0.5;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            glVertex3f(10 * i+slot, 0.0, j*10 + slot);
            glVertex3f(10 * (i+1), 0.0, j * 10+slot);
            glVertex3f(10 * (i + 1), 0.0, (j+1) * 10);
            glVertex3f(10 * i+slot , 0.0, (j + 1) * 10 );
       }
    }
    
    glEnd();
}

void room::createCilingLight(GLfloat lightPos0[4] , int lightNum)
{
    GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(lightNum, GL_SPECULAR, specular);
    GLfloat lightColor0[] = { 0.5f, 0.4f, 0.4f, 1.0f }; //cream color
    glLightfv(lightNum, GL_DIFFUSE, lightColor0);
    glLightfv(lightNum, GL_POSITION, lightPos0);
    glEnable(lightNum);
}

void room::createLight()
{
    createAmbidentLight();
    GLfloat specular[] = { 0.5, 0.5, 0.5, 1.0 };
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
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
}

void room::createAmbidentLight()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    GLfloat ambientColor[] = { 0.1f, 0.1f, 0.1f, 1.0f }; //Color(0.2, 0.2, 0.2)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
}

room::room()
{
}

void room::drawRoom()
{
 
    createLight();
    drawFloor();
    drawWalls();
}
