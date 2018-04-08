#include "Coin.hpp"

Coin :: Coin(double _value, double _xpos, double _ypos) : xPos(_xpos){
    value = _value;
    yPos= _ypos;
}

double Coin :: getXPos() const{
    return xPos;
}

double Coin :: getYPos() const{
    return yPos;
}

void Coin :: move(){
    yPos--;
}