#include <cmath>
#include "Snail.hpp"
//konstruktor
Snail :: Snail(){
    xPos = 0.0;
    xDest = 0.0;
    moveTime = 0;
    direction = true;
}
Snail :: Snail(double _xpos){
    xPos = _xpos;
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
//getter
double Snail :: getXPos() const{
    return xPos;
}
double Snail :: getYPos() const{
    return yPos;
}
    
//menggerakkan snail
void Snail :: move(double _x, double t, bool huntcoin){
    cout << _x << endl;
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
    else if(this->moveTime <= t){
        this->moveTime = 3;
        this->xDest = _x;
        if(this->xPos - this->xDest > 0){
            this->direction = true;
        }else{
            this->direction = false;
        }
    }else{
        this->moveTime -= t;
    }
    
    if(!(abs(this->xDest - this->xPos) < 5)){
        double a = atan2(this->xDest-xPos, 0.0);
        xPos = xPos + 20*sin(a)*t;
    }
    
}

bool Snail :: getDirection() const{
    return this->direction;
}