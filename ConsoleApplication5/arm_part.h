#pragma once
#include "robotPart.h"
/*
* this class use to create any one of the 3 part of the arms 
* any part remamber the next part so they will be able to move togther
*/
class arm_part :
    public robotPart
{
public:
    // the next part the arm ( in the case af the hand its mullptr)
    arm_part* next;
    //the current angle use to limit the move of the diffrent part in a nutral possible way
    float cur_angle;
    //counstructors
    arm_part(double, double, double, double, double, double ,arm_part *next);
    arm_part();
    // rotate the arm part himself
    bool rotate(float angle);
    //rotate the arm part and the parts that came after in recursia
    bool rotateOverAxisWithSibling(glm::vec3 a, glm::vec3 b, float angle);
    // check colissin for himself and the parts that came after him
    bool checkCollision(glm::mat4);
};

