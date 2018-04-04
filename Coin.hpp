//File : Coin.hpp

#ifndef __COIN_HPP
#define __COIN_HPP

#include <iostream>
using namespace std;

class Coin{
private:
    double value;
    const double xPos;
    double yPos;
public:
    //konstruktor
    Coin(double,double,double);
    //getter
    double getXPos() const;
    double getYPos() const;
    
    //move
    void move();

};
#endif