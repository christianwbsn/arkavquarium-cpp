#ifndef __FISHFOOD_HPP
#define __FISHFOOD_HPP
#include <iostream>
using namespace std;

class FishFood{
private:
    const int xPos;
    int yPos;
public:
    //konstruktor
    FishFood();
    //getter
    int getXPos() const;
    int getYPos() const;
};
#endif