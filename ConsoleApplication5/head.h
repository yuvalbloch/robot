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
public:
    virtual void draw()  override;
    head(double, double, double, double, double, double);
    void a();
};


