//File : Coin.hpp

#ifndef __COIN_HPP
#define __COIN_HPP

#include <iostream>
using namespace std;

class Coin{
private:
    double value;
    double xPos;
    double yPos;
public:
    //konstruktor
    Coin();
    Coin(double,double,double);
    //getter
    double getXPos() const;
    double getYPos() const;
    double getValue() const;
    Coin operator=(const Coin& C);
    //move
    void move(double t);

};
#endif