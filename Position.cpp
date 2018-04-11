#include "Position.hpp"

Position::Position() {
    this->xPos = 0.0;
    this->yPos = 0.0;
}
Position::Position(double _x, double _y){
    this->xPos = _x;
    this->yPos = _y;
}
Position::~Position(){
    
}
double Position::getXPos() { return this->xPos; }
double Position::getYPos() { return this->yPos; }
void Position::setXPos(double _x) {
    this->xPos = _x;
}
void Position::setYPos(double _y){
    this->yPos = _y;
}