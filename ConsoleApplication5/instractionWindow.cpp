#include "instractionWindow.h"
#include "GL/glut.h"
instractionWindow::instractionWindow()
{
}
void instractionWindow::init()
{
    glutInitWindowSize(200, 400);
    glutInitWindowPosition(0, 0);
    
}

void instractionWindow::display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    exit = button(20, 20, 100, 60);
    exit.draw();
    glFlush();
    glutSwapBuffers();
}

void instractionWindow::setUp()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200, 0.0, 400);
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!
* to do: set verible to win size and use it in u setting
*/
int instractionWindow::mouseFunc(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (exit.press(x,400- y)) {
            std::cout << "exit push";
        }
    }
    return 0;
}
