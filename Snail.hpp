#ifndef __SNAIL_HPP
#define __SNAIL_HPP
#include <iostream>
using namespace std;

class Snail{
private:
    int xPos;
    const int yPos;
public:
    Snail();

    int getXPos() const;
    int getYPos() const;
    
    void move(int, int);
};
#endif