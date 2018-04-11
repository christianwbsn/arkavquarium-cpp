#ifndef __SNAIL_HPP
#define __SNAIL_HPP

#include "Position.hpp"
#include <iostream>
using namespace std;

class Snail:public Position{
private:
    double xDest;
    double moveTime;
    bool direction;
public:
    //konstruktor
    Snail();
    Snail(double);
    Snail operator=(const Snail& S);
    //getter
    bool getDirection() const;
    //menggerakkan snail
    void move(double, double, bool);
};
#endif
