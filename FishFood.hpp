#ifndef __FISHFOOD_HPP
#define __FISHFOOD_HPP
#include <iostream>
using namespace std;

class FishFood{
private:
    const int xPos;
    int yPos;
public:
    FishFood();
    
    int getXPos() const;
    int getYPos() const;
};
#endif