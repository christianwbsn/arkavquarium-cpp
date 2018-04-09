#ifndef __FISH_HPP
#define __FISH_HPP

#include <iostream>

#include "Coin.hpp"
using namespace std;

class Fish{
protected:
    double xPos;
    double yPos;
    double xDest;
    double yDest;
    double moveTime;
    int foodEaten;
    bool direction;
    int hungerTime;
    const int fullTimeLimit = 60;
    const int speed = 40;

public:
    //constructor
    Fish();
    Fish& operator=(const Fish& F);
    //mengeluarkan koin setiap C waktu
    virtual Coin extractCoin()=0;
    //memakan makanan
    virtual void eatFood()=0;
    //Bergerak sesuai dengan status
    void move(double, double, double, bool);

    //Getter
    double getXPos() const;
    double getYPos() const;
    int getSize() const;
    int getFoodEaten() const;
    bool getDirection() const;
    int getHungerTime() const;
    int getFoodNeeded() const;
    int getFullTimeLimit() const;
    int getSpeed() const;

    bool isHungry() const;
};
#endif