// File: Aquarium.hpp
#ifndef __AQUARIUM__HPP
#define __AQUARIUM__HPP

#include "LinkedList.hpp"
#include "Fish.hpp"
#include "Snail.hpp"
#include "Piranha.hpp"
#include "Guppy.hpp"
#include "FishFood.hpp"
#include "Position.hpp"

class Aquarium {
friend Fish;
friend Snail;

public:
    LinkedList<Piranha> listOfPiranha;
    LinkedList<Guppy> listOfGuppy;
    LinkedList<Coin> listOfCoin;
    LinkedList<FishFood> listOfFishFood;
    Snail snail;
    int money;
    int egg;
public:
    
    Aquarium();
    // Constructor akuarium yang menerima parameter input width dan height
    ~Aquarium();

    // getter ukuran dari akuarium
    LinkedList<Piranha> getListOfPiranha() const;
    LinkedList<Guppy> getListOfGuppy() const;
    LinkedList<Coin> getListOfCoin() const;
    LinkedList<FishFood> getListOfFishFood() const;  


    Snail& getSnail();

    int getMoney();
    int getEgg();
    void buyEgg();
    void increaseMoney(int);
    void decreaseMoney(int);
};

#endif
