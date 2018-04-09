#include "FishFood.hpp"

FishFood :: FishFood(){
    xPos = 0.0;
    yPos = 0.0;
}

FishFood :: FishFood(double _xpos,double _ypos){
    xPos= _xpos;
    yPos= _ypos;
}

double FishFood :: getXPos() const{
    return xPos;
}

double FishFood :: getYPos() const{
    return yPos;
}

void FishFood :: move(){
    this->yPos += 0.25;
}

FishFood FishFood :: operator=(const FishFood& F){
    double _y = F.getYPos();
    xPos = F.getXPos();
    this->yPos = _y;
    return *this;
}