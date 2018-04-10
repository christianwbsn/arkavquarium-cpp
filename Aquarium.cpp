#include "Aquarium.hpp"
#include <iostream>

Aquarium::Aquarium() {
    Snail S(590.0);
    std::cout<<S.getXPos()<<std::endl;
    this->snail = S;
    std::cout<<this->snail.getXPos()<<std::endl;
}

// Destruktor akuarium dan seluruh object di dalamnya
Aquarium::~Aquarium() {
}

// getter ukuran dari akuarium
// LinkedList<Piranha> Aquarium::getListOfPiranha() const {
//     return this->listOfPiranha;
// }
LinkedList<Guppy> Aquarium::getListOfGuppy() const {
    return this->listOfGuppy;
}
LinkedList<Coin> Aquarium::getListOfCoin() const {
    return this->listOfCoin;
}

LinkedList<FishFood> Aquarium::getListOfFishFood() const {
    return this->listOfFishFood;
}  

Snail& Aquarium::getSnail(){
    return this->snail;
}

// getter object in position (x,y)
Guppy Aquarium::getGuppy(double x, double y) const {

}

Coin Aquarium::getCoin(double x, double y) const {
}

FishFood Aquarium::getFishFood(double x, double y) const {
}