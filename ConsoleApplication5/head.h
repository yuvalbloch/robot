#pragma once

#include "robotPart.h"



/*
* the head of the robor is a robot part with 2 eye 
* the head can rotate up and down and left and right
*/
class head :
    public robotPart
{
private:
    // draw 2 point on the front side of the head that reprasent eyes
    void drawEye();
    // The sums are used to identify and prevent deviations from the normal angles of the neck  
    double sumVerticalAngle = 0;
    double sumHoriznalAngle = 0;
    /*
    * the neck is a thin robot part that connect batwin the headand the body
    * the neck totate with the head to left and right but not up and down
    */
   robotPart neck;
public:
    //the draw function draw 3 part the head himself the eyes and the neck
    virtual void draw()  override;
    head(double, double, double, double, double, double);
    head();
    //rotate around axis that connect the middels off the 2 sides pannel
    void rotate_up_down(float angle);
    //rotate over axis parlal to y axis, totate the head an the neck 
    void rotate_left_right(float angle);
    void transformWithNeck(glm::mat4 trans);
};


