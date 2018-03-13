// File: Aquarium.hpp
#ifndef __AQUARIUM__HPP
#define __AQUARIUM__HPP

#include "LinkedList.hpp"

class Aquarium{
private:
    const int width,height; 
    LinkedList<Piranha> listOfPiranha;
    LinkedList<Guppy>  listOfGuppy;
    LinkedList<Coin> listOfCoin;
    LinkedList<Food> listOfFood;
public:
    // Constructor akuarium yang menerima parameter input width dan height
    Aquarium(int,int);
    // Copy constructor akuarium
    Aquarium(const Akuarium&);
    // Destruktor akuarium dan seluruh object di dalamnya
    ~Aquarium();

    // getter ukuran dari akuarium
    int getWidth() const;
    int getHeight() const;

    // getter object in position (x,y)
    Guppy getGuppy(int, int) const;
    Coin getCoin(int, int) const;
    Food getFood(int, int) const;
};

#endif
