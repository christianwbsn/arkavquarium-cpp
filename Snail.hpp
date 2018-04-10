#ifndef __SNAIL_HPP
#define __SNAIL_HPP

#include <iostream>
using namespace std;

class Snail{
private:
    double xPos;
    double xDest;
    double moveTime;
    bool direction;
    const double yPos = 450.0;
public:
    //konstruktor
    Snail();
    Snail(double);
    Snail operator=(const Snail& S);
    //getter
    double getXPos() const;
    double getYPos() const;
    bool getDirection() const;
    //menggerakkan snail
    void move(double, double, bool);
};
#endif