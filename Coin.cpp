Coin :: Coin(double _value, double _xpos, double _ypos){
    value = _value;
    xPos= _xpos;
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