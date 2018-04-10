#include "Coin.hpp"

Coin :: Coin(){
    value = 0.0;
    xPos = 0.0;
    yPos = 0.0;
}
Coin :: Coin(double _value, double _xpos, double _ypos){
    value = _value;
    yPos= _ypos;
    xPos= _xpos;
}

double Coin :: getXPos() const{
    return xPos;
}

double Coin :: getYPos() const{
    return yPos;
}

double Coin :: getValue() const{
    return value;
}
void Coin :: move(){
    yPos+= 0.17;
}

Coin Coin :: operator=(const Coin& C){
    this->xPos = C.getXPos();
    this->yPos = C.getYPos();
    this->value = C.value;
    return *this;
}