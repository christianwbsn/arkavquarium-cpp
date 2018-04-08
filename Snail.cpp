#include <cmath>
#include "Snail.hpp"
//konstruktor
Snail :: Snail() : yPos(0.0){
    xPos = 0.0;
}
Snail :: Snail(double _xpos, double _ypos) : yPos(_ypos){
    xPos = _xpos;
}

Snail Snail :: operator=(const Snail& S) {
    int _x = S.getXPos();
    int _y = S.getYPos();
    Snail temp(_x, _y);
    return temp;
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