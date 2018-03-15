//File : Coin.hpp

#ifndef __COIN_HPP
#define __COIN_HPP

#include <iostream>
using namespace std;

class Coin{
private:
    int value;
    const int xPos;
    int yPos;
public:
    //konstruktor
    Coin(int,int,int);
    //getter
    int getXPos() const;
    int getYPos() const;
    
    //move
    void move();

};
#endif