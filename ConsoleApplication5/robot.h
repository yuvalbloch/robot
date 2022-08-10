#pragma once
#include "head.h"
#include "arm.h"
#include "robotPart.h"
/*
* the robot build from body that rander in the robot object himself and two more object
* one is the arm and one is the head the robot object hold in addition to those part the keyboard control
*/
class robot :
    public robotPart
{
public:
    //the robot part
    head myHead;
    arm myArm;
    virtual void draw()  override;
    robot(double, double, double, double, double, double);
    robot();
    //transformation
    void rotate(float angle);
    void move(float far);
    // key board control 
    void keyBoard(unsigned char key);
    void spicelKeyBoard(unsigned char key);
};

