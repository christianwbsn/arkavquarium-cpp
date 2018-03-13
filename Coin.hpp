// File: Coin.hpp
#ifndef __COIN__HPP
#define __COIN__HPP

class Coin{
private:
    int value;
    const int xPos;
    int yPos;
public:
    // Constructor
    Coin();
    // coin movement controller
    void move();
};

#endif