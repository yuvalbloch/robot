#include "instractionWindow.h"
#include "GL/glut.h"

instractionWindow::instractionWindow()
{
}

/*
* the diffrent batwin the init and the setup is that the init 
* call before creating the window and the set up after
*/
void instractionWindow::init()
{
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);

}

void instractionWindow::setUp(int id, int World)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, width, 0.0, height);
    for (int i = 0; i < lightAmount; i++) {
        light[i] = button(20 + i * 40, 420, 50 + i * 40, 450, std::to_string(i));
    }
    winId = id;
    world = World;

}
/*
* the display main job is to dicide wich display function to call base on the current page
*/
void instractionWindow::display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (current == greeting) {
        displayGreeting();
    }
    if (current == lightPannal) {
        displayLightPannal();
    }
    if (current == helpPage) {
        display_help_page();
    }
    glFlush();
    glutSwapBuffers();
}


/*--------------------------------------------------------------------------------------
* diffrent dispaly function for diffrent pages
* ---------------------------------------------------------------------------------------
*/
void instractionWindow::displayGreeting()
{
    greetingText.draw(width);

    glColor3f(0.0, 1.0, 0.0);
    help.draw();
    glColor3f(0.0, 1.0, 0.0);
    exit.draw();
    glColor3f(0.0, 1.0, 0.0);
    adujt_light.draw();
    
}

void instractionWindow::displayLightPannal()
{
    choselightText.draw(width);
    glColor3f(r*power, g*power, b*power);
    applay.draw();
    choseColorText.draw(width);
    glColor3f(0.0, 1.0, 0.0);
    color.draw(power);
    glColor3f(0.0, 1.0, 0.0);
    back.draw();
    for (int i = 0; i < lightAmount; i++) {
        if (i == lightNum) {
            glColor3f(0.7, 0.7, 0.7);
        }
        else {
            glColor3f(0.5, 0.5, 0.5);
        }
        light[i].draw();
    }
    lightPower.draw(r, g, b);

}
void instractionWindow::display_help_page()
{
    helpText.draw(width);
    smallBack.draw();
}

/*----------------------------------------------------------------------------------------
* mouse function 
* -----------------------------------------------------------------------------------------
*/
int instractionWindow::mouseFunc(int button, int state, int x, int y)
{ 
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {


        if (exit.press(x, height - y)) {//exit button push

            glutDestroyWindow(world);
            glutDestroyWindow(winId);
        }
        if (adujt_light.press(x, height - y)) {//light button push
            offAllButton();
            current = lightPannal;     
        }
        if (help.press(x, height - y)) {//help button push
            offAllButton();
            current = helpPage;
        }
        if (back.press(x, height - y)) {//back button push
            offAllButton();
            current = greeting;
        }
        if (smallBack.press(x, height - y)) {//back button push
            offAllButton();
            current = greeting;
        }
        if (applay.press(x, height - y)) {//applay button push

            GLfloat lightColor[4] = { r, g,b, 1.0f };
            glutSetWindow(world);
            GLfloat lightColor0[] = { r * power, g * power, b * power, 1.0f };
            glLightfv(LightID(), GL_DIFFUSE, lightColor0);
            glutPostRedisplay();
            glFlush();
            glutSetWindow(winId);
        }
        if (color.press(x, height - y)) {//color button push
            color.choseColor(&r, &g, &b, x, height - y);
        }
        if (lightPower.press(x, height - y)) {//power button push
            power = lightPower.chosePower(x, height - y);
            glutPostRedisplay();

        }
        for (int i = 0; i < lightAmount; i++) {//one of the light ball button are push
            if (light[i].press(x, height - y)) {
                lightNum = i;
                glutPostRedisplay();
            }
        }
    }
    display();
    glFlush();
    return 0;
}

/*----------------------------------------------------------------------------------
* utilty
* -------------------------------------------------------------------------------
*/

/*
* opengl hold diffrent numbers macro to diffrent light source
* I hold the light source in an array with indexs this function translate batwin this 2 system
*/
int instractionWindow::LightID()
{

    switch (lightNum) {
    case 0:
        return GL_LIGHT0;
    case 1:
        return GL_LIGHT1;
    case 2:
        return GL_LIGHT2;
    case 3:
        return GL_LIGHT3;
    case 4:
        return GL_LIGHT4;
    }

}
// set all button to off so you coldent push them
void instractionWindow::offAllButton() {
    help.off();
    exit.off();
    adujt_light.off();
    back.off();
    applay.off();
    color.off();
    lightPower.off();
}


