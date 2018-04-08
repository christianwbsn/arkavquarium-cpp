#include "FishFood.hpp"


FishFood :: FishFood(double _xpos,double _ypos) : xPos(_xpos){
    yPos= _ypos;
}

double FishFood :: getXPos() const{
    return xPos;
}

double FishFood :: getYPos() const{
    return yPos;
}

void FishFood :: move(){
    yPos--;
}