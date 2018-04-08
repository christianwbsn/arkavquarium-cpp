#ifndef __FISH_HPP
#define __FISH_HPP

#include <iostream>

#include "Coin.hpp"
using namespace std;

class Fish{
private:
    double xPos;
    double yPos;
    int foodEaten;
    bool direction;
    int hungerTime;

    const int fullTimeLimit = 60;
    const int speed = 3;

public:
    //constructor
    Fish();
    //mengeluarkan koin setiap C waktu
    virtual Coin extractCoin()=0;
    //memakan makanan
    virtual void eatFood()=0;
    //Bergerak sesuai dengan status
    void move(double, double);

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

    bool isHungry();
};
#endif