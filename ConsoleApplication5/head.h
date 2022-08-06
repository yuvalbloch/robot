#include "robotPart.h"


/*
* the head of the robor is a robot part with 2 eye 
* the head can rotate up and down and left and right
*/
class head :
    public robotPart
{
private:
    void drawEye();
    double sumVerticalAngle = 0;
    double sumHoriznalAngle = 0;
   robotPart neck;
public:
    virtual void draw()  override;
    head(double, double, double, double, double, double);
    void rotate_up_down(float angle);
    void rotate_left_right(float angle);
};


