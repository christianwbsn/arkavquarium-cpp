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
    Coin(int,int,int);

    int getXPos() const;
    int getYPos() const;
    
    void move();

};
#endif