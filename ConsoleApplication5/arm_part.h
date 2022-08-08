#pragma once
#include "robotPart.h"
class arm_part :
    public robotPart
{
public:
    arm_part* next;
    float cur_angle;
    arm_part(double, double, double, double, double, double ,arm_part *next);
    arm_part();
    void rotate(float angle);
    void rotateOverAxisWithSibling(glm::vec3 a, glm::vec3 b, float angle);
};

