// File: Aquarium.hpp
#ifndef __AQUARIUM__HPP
#define __AQUARIUM__HPP

#include "LinkedList.hpp"
#include "Fish.hpp"
#include "Snail.hpp"

class Aquarium {
friend Fish;
friend Snail;
private:
    LinkedList<Piranha> listOfPiranha;
    LinkedList<Guppy> listOfGuppy;
    LinkedList<Coin> listOfCoin;
    LinkedList<Food> listOfFood;
    Snail snail;
public:
    
    Aquarium();
    // Constructor akuarium yang menerima parameter input width dan height
    ~Aquarium();

    // getter ukuran dari akuarium
    LinkedList<Piranha> getListOfPiranha() const;
    LinkedList<Guppy> getListOfGuppy() const;
    LinkedList<Coin> getListOfCoin() const;
    LinkedList<Food> getListOfFood() const;  


    // getter object in position (x,y)
    Guppy getGuppy(double, double) const;
    Coin getCoin(double, double) const;
    Food getFood(double, double) const;
};

#endif
