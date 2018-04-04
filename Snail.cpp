#include<math>
//konstruktor
Snail :: Snail(double _xpos, double _ypos){
    xPos = _xpos;
    yPos = _ypos;
}

//getter
double Snail :: getXPos() const{
    return xPos;
}
double Snail :: getYPos() const{
    return yPos;
}
    
//menggerakkan snail
void move(double _y, double _x, double t){
    double a = atan2(_x-xPos,_y-yPos);
    x = x + cos(a)*t;

}