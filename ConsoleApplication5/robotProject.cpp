#pragma once
#include "world.h"
#include "resource.h"
#include <string.h>
#include"instractionWindow.h"
world myWorld;
instractionWindow ins;
void keyboard(unsigned char key, int x, int y) {
    myWorld.keyboard(key);
}
void spicelKeyboard(int key, int x, int y) {
    myWorld.spicelKeyboard(key);
}
void display() {
    myWorld.display();
  
    glutSwapBuffers();

}
void instraction() {
    ins.display();

}
void mouseFunc(int button, int state ,int x,int y ) {
    ins.mouseFunc(button, state, x, y);
}
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
    ins.setUp();
    glutDisplayFunc(instraction);
    glutMouseFunc(mouseFunc);
   
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    Init();
    glutMainLoop();
    return 0;
}



