#include <cmath>
#include "Snail.hpp"
//konstruktor
Snail :: Snail():Position(0.0,450.0){
    xDest = 0.0;
    moveTime = 0;
    direction = true;
}
Snail :: Snail(double _xpos) : Position(_xpos,450.0){
    xDest = 0.0;
    moveTime = 0;
    direction = true;
}

Snail Snail :: operator=(const Snail& S) {
    double _x = S.getXPos();
    this->xPos = _x;
    this->xDest = 0.0;
    return *this;
}

//menggerakkan snail
void Snail :: move(double _x, double t, bool huntcoin){
    if(huntcoin){
        this->moveTime = (rand()%45 + 5)*0.1;
        this->xDest = _x;
        if(abs(this->xDest - this->xPos) < 10){
            //Do nothing
            
        }
        else if(this->xPos - this->xDest > 0){
            this->direction = true;
        }else{
            this->direction = false;
        }   
    }
    //~ else if(this->moveTime <= t){
        //~ this->moveTime = 3;
        //~ this->xDest = _x;
        //~ if(this->xPos - this->xDest > 0){
            //~ this->direction = true;
        //~ }else{
            //~ this->direction = false;
        //~ }
    //~ }else{
        //~ this->moveTime -= t;
    //~ }
    
    if((!(abs(this->xDest - this->xPos) < 5)) and (huntcoin)){
        double a = atan2(this->xDest-xPos, 0.0);
        xPos = xPos + 20*sin(a)*t;
    }
    
}

bool Snail :: getDirection() const{
    return this->direction;
}
