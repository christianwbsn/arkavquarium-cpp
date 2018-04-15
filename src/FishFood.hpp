#ifndef __FISHFOOD_HPP
#define __FISHFOOD_HPP
#include "Position.hpp"
#include <iostream>
using namespace std;

class FishFood:public Position{
public:
    //konstruktor
    FishFood();
    FishFood(double,double);
    //getter
    void move(double t);
    FishFood operator=(const FishFood& F);
};
#endif
