#include "robotPart.h"
class head :
    public robotPart
{
private:
    void drawEye();
public:
    virtual void draw()  override;
    head(double, double, double, double, double, double);
};

