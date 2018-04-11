#include "Position.hpp"

Position::Position() {
    this->x = 0.0;
    this->y = 0.0;
}
Position::Position(double _x, double _y){
    this->x = _x;
    this->y = _y;
}
double Position::getX() { return this->x; }
double Position::getY() { return this->y; }
void Position::setX(double _x) {
    this->x = _x;
}
void Position::setY(double _y){
    this->y = _y;
}