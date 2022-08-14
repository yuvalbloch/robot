#pragma once
#include "world.h"
#include "resource.h"
#include <string.h>
#include"instractionWindow.h"
world myWorld;
instractionWindow ins;

/*-------------------------------------------------------------
* direct event to the right object in addition to the state
* --------------------------------------------------------------
*/
void keyboard(unsigned char key, int x, int y) {
    myWorld.keyboard(key);
}
void spicelKeyboard(int key, int x, int y) {
    myWorld.spicelKeyboard(key);
}
void mouseFunc(int button, int state, int x, int y) {
    ins.mouseFunc(button, state, x, y);
}
/*-------------------------------------------------------------
* use diffrent display in addition to the state
* --------------------------------------------------------------
*/
void display() {
    myWorld.display();
  
    glutSwapBuffers();

}
void instraction() {
    ins.display();

}
/*---------------------------------------------
* initlize bothe window
* ------------------------------------
*/
void Init(void) {
    // create the world window
    myWorld.Init();
    int labWin = glutCreateWindow("the lab of roby the robot");
    myWorld.setUp();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(spicelKeyboard);
    glutDisplayFunc(display);

    //create the instraction window
    ins.init();
    int instrauctionWin = glutCreateWindow("instruction");
    ins.setUp(instrauctionWin, labWin);
    glutDisplayFunc(instraction);
    glutMouseFunc(mouseFunc);
   
}
/*---------------------------------------------
* main
* ------------------------------------
*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    Init();
    glutMainLoop();
    return 0;
}



