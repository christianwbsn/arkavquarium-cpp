#include <cmath>
#include "Snail.hpp"
//konstruktor
Snail :: Snail(){
    xPos = 0.0;
}
Snail :: Snail(double _xpos){
    xPos = _xpos;
}

Snail Snail :: operator=(const Snail& S) {
    double _x = S.getXPos();
    this->xPos = _x;
    return *this;
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