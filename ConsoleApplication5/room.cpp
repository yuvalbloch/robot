#include "room.h"


room::room()
{
}

void room::drawRoom()
{
    drawWindows();
    drawFloor();
    drawWalls();
}
/*----------------------------------------------------------
* create light
* ----------------------------------------------------------
*/
// creat all light
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

}
//create one light ball 
void room::createCilingLight(GLfloat lightPos0[4], int lightNum)
{
    GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(lightNum, GL_SPECULAR, specular);
    GLfloat lightColor0[] = { 0.6f, 0.5f, 0.5f, 1.0f }; //cream color
    glLightfv(lightNum, GL_DIFFUSE, lightColor0);
    glLightfv(lightNum, GL_POSITION, lightPos0);
    glEnable(lightNum);
}
//create ambident light
void room::createAmbidentLight()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    GLfloat ambientColor[] = { 0.1f, 0.1f, 0.1f, 1.0f }; //Color(0.2, 0.2, 0.2)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
}
/*-----------------------------------------------------
* draw diffrent part of the room
* -------------------------------------------------------
*/
void room::drawWalls()
{
    matrial iron = matrial();
    iron.setToIron();
    iron.use();
    glBegin(GL_POLYGON);
    glNormal3i(1, 0, 0);
    glVertex3f(0.0,-1.0, 0.0);
    glVertex3f(0.0,-1.0, size);
    glVertex3f(0.0, size, size);
    glVertex3f(0.0, size, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glNormal3i(0, 0, 1);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(size,-1.0, 0.0);
    glVertex3f(size, size, 0.0);
    glVertex3f(0.0, size, 0.0);
    glEnd();
}

void room::drawFloor()
{
    matrial carmic = matrial();
    carmic.setToCramic();
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, carmic.color);
    glBegin(GL_POLYGON);
    glNormal3i(0, 1, 0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(0.0, -1.0, size);
    glVertex3f(size, -1.0, size);
    glVertex3f(size, -1.0, 0.0);
    glEnd();
    carmic.use();
    glBegin(GL_QUADS);
    GLfloat squreColor[] = { 0.3f, 0.5f, 0.7f, 1.0f };
    float slot = 0.5;
    for (int i = 0; i < size/10; i++) {
        for (int j = 0; j < size / 10; j++) {
            glVertex3f(10 * i+slot, 0.0, j*10 + slot);
            glVertex3f(10 * (i+1), 0.0, j * 10+slot);
            glVertex3f(10 * (i + 1), 0.0, (j+1) * 10);
            glVertex3f(10 * i+slot , 0.0, (j + 1) * 10 );
       }
    }
    
    glEnd();
}

void room::drawWindows()
{
    {
        matrial iron = matrial();
        iron.setToIron();
        matrial glass = matrial();
        glass.setToGlass();
        glass.use();
        //draw the windows
        glBegin(GL_QUADS);
     
        glNormal3i(-1, 0, 0);
        glVertex3f(size, -1.0, 0.0);
        glVertex3f(size, -1.0, size-10);
        glVertex3f(size, size-10, size-10);
        glVertex3f(size, size-10, 0.0);
        glNormal3i(0, 0, -1);
        glVertex3f(0.0, -1.0, size);
        glVertex3f(size-10, -1.0, size);
        glVertex3f(size - 10, size - 10, size);
        glVertex3f(0.0, size - 10, size);
        //draw the roof
        glNormal3i(0, -1, 0);
        glVertex3f(0.0, size, 0.0);
        glVertex3f(0.0, size, size);
        glVertex3f(size, size, size);
        glVertex3f(size, size, 0.0);
        //draw the iron above the window
        iron.use();
        glNormal3i(0, 0, -1);
        glVertex3f(0.0, size - 10, size);
        glVertex3f(0.0, size, size);
        glVertex3f(size, size, size);
        glVertex3f(size, size - 10, size);
        glNormal3i(-1, 0, 0);
        glVertex3f(size, size - 10, 0.0);
        glVertex3f(size, size, 0.0);
        glVertex3f(size, size, size);
        glVertex3f(size, size - 10, size);
        glNormal3i(0, 0, -1);
        //draw the iron batwin the windows
        glVertex3f(size-10, 0.0, size);
        glVertex3f(size, 0.0, size);
        glVertex3f(size, size, size);
        glVertex3f(size - 10, size, size);
        glNormal3i(-1, 0, 0);
        glVertex3f(size, 0.0, size);
        glVertex3f(size, 0.0, size);
        glVertex3f(size, size, size);
        glVertex3f(size, size, size - 10);
        glEnd();

    }
}


