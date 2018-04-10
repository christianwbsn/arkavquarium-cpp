#ifndef __FISHFOOD_HPP
#define __FISHFOOD_HPP
#include <iostream>
using namespace std;

class FishFood{
private:
    double xPos;
    double yPos;
public:
    //konstruktor
    FishFood();
    FishFood(double,double);
    //getter
    double getXPos() const;
    double getYPos() const;
    void move(double t);
    FishFood operator=(const FishFood& F);
};
#endif