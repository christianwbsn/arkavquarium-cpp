//File : Coin.hpp

#ifndef __COIN_HPP
#define __COIN_HPP

#include <iostream>
using namespace std;

class Coin:public Position{
private:
    double value;

public:
    //konstruktor
    Coin();
    Coin(double,double,double);
    double getValue() const;
    Coin operator=(const Coin& C);
    //move
    void move(double t);

};
#endif