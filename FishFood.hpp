#ifndef __FISHFOOD_HPP
#define __FISHFOOD_HPP
#include <iostream>
using namespace std;

class FishFood{
private:
    const double xPos;
    double yPos;
public:
    //konstruktor
    FishFood(double,double);
    //getter
    double getXPos() const;
    double getYPos() const;
    void move();
};
#endif