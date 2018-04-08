// File: Aquarium.hpp
#ifndef __AQUARIUM__HPP
#define __AQUARIUM__HPP

#include "LinkedList.hpp"
#include "Fish.hpp"
#include "Snail.hpp"
#include "Piranha.hpp"
#include "Guppy.hpp"
#include "FishFood.hpp"

class Aquarium {
friend Fish;
friend Snail;

private:
    LinkedList<Piranha> listOfPiranha;
    LinkedList<Guppy> listOfGuppy;
    LinkedList<Coin> listOfCoin;
    LinkedList<FishFood> listOfFishFood;
    Snail snail;
public:
    
    Aquarium();
    // Constructor akuarium yang menerima parameter input width dan height
    ~Aquarium();

    // getter ukuran dari akuarium
    LinkedList<Piranha> getListOfPiranha() const;
    LinkedList<Guppy> getListOfGuppy() const;
    LinkedList<Coin> getListOfCoin() const;
    LinkedList<FishFood> getListOfFishFood() const;  


    Snail getSnail();

    // getter object in position (x,y)
    Guppy getGuppy(double, double) const;
    Coin getCoin(double, double) const;
    FishFood getFishFood(double, double) const;
};

#endif
