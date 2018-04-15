#include "Coin.hpp"

Coin :: Coin():Position(){
    value = 0.0;
}
Coin :: Coin(double _value, double _xpos, double _ypos):Position(_xpos,_ypos){
    value = _value;

}


double Coin :: getValue() const{
    return value;
}
void Coin :: move(double t){
    yPos+= 20*t;
}


Coin Coin :: operator=(const Coin& C){
    this->xPos = C.getXPos();
    this->yPos = C.getYPos();
    this->value = C.value;
    return *this;
}