#include <cmath>
#include "Snail.hpp"
//konstruktor
Snail :: Snail(double _xpos, double _ypos) : yPos(_ypos){
    xPos = _xpos;
}

//getter
double Snail :: getXPos() const{
    return xPos;
}
double Snail :: getYPos() const{
    return yPos;
}
    
//menggerakkan snail
void Snail :: move(double _y, double _x, double t){
    double a = atan2(_x-xPos,_y-yPos);
    xPos = xPos + cos(a)*t;

}