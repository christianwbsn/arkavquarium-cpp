#ifndef __FISH_HPP
#define __FISH_HPP
#include <iostream>
#include "Coin.hpp"
using namespace std;

class Fish{
private:
    int xPos;
    int yPos;
    int foodEaten;
    bool direction;
    int hungerTime;

    const int foodNeeded;
    const int fullTimeLimit;
    const int speed;

public:
    //constructor
    Fish();
    //mengeluarkan koin setiap C waktu
    virtual Coin extractCoin();
    //memakan makanan
    virtual void eatFood();
    //Bergerak sesuai dengan status
    void move(int, int);

    //Getter
    int getXPos() const;
    int getYPos() const;
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