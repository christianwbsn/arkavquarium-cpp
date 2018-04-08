#ifndef __SNAIL_HPP
#define __SNAIL_HPP

#include <iostream>
using namespace std;

class Snail{
private:
    double xPos;
    const double yPos = 460.0;
public:
    //konstruktor
    Snail();
    Snail(double);
    Snail operator=(const Snail& S);
    //getter
    double getXPos() const;
    double getYPos() const;
    
    //menggerakkan snail
    void move(double, double,double);
};
#endif