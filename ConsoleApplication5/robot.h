#pragma once
#include "head.h"
#include "robotPart.h"
class robot :
    public robotPart
{
public:
    head myHead;
    virtual void draw()  override;
    robot(double, double, double, double, double, double);
    void rotate(float angle);
    void move(float far);

};

