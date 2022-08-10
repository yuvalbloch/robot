#pragma once
#include "world.h"


world myWorld;
void keyboard(unsigned char key, int x, int y) {

    myWorld.keyboard(key);
}
void spicelKeyboard(int key, int x, int y) {
    myWorld.spicelKeyboard(key);
}
void Init(void) {
    myWorld.Init();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(spicelKeyboard);

   
}
void display() {
    myWorld.display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



