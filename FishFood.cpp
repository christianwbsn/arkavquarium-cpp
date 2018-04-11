#include "FishFood.hpp"

FishFood :: FishFood() : Position(){

}

FishFood :: FishFood(double _xpos,double _ypos) : Position(_xpos,_ypos){

}


void FishFood :: move(double t){
    this->yPos += 20*t;
}

FishFood FishFood :: operator=(const FishFood& F){
    double _y = F.getYPos();
    xPos = F.getXPos();
    this->yPos = _y;
    return *this;
}