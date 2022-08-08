#pragma once
#include "head.h"
#include "arm.h"
#include "robotPart.h"
class robot :
    public robotPart
{
public:
    head myHead;
    arm myArm;
    virtual void draw()  override;
    robot(double, double, double, double, double, double);
    void rotate(float angle);
    void move(float far);
    void keyBoard(unsigned char key);

};

