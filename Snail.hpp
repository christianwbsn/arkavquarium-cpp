#ifndef __SNAIL_HPP
#define __SNAIL_HPP

#include <iostream>
using namespace std;

class Snail{
private:
    double xPos;
    const double yPos;
public:
    //konstruktor
    Snail(double,double);

    //getter
    double getXPos() const;
    double getYPos() const;
    
    //menggerakkan snail
    void move(double, double,double);
};
#endif