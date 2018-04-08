#include "Aquarium.hpp"

Aquarium::Aquarium() {
    
}

// Destruktor akuarium dan seluruh object di dalamnya
Aquarium::~Aquarium() {
}

// getter ukuran dari akuarium
LinkedList<Piranha> Aquarium::getListOfPiranha() const {
    return this->listOfPiranha;
}
LinkedList<Guppy> Aquarium::getListOfGuppy() const {
    return this->listOfGuppy;
}
LinkedList<Coin> Aquarium::getListOfCoin() const {
    return this->listOfCoin;
}

LinkedList<Food> Aquarium::getListOfFood() const {
    return this->listOfFood;
}  


// getter object in position (x,y)
Guppy Aquarium::getGuppy(double x, double y) const {

}

Coin Aquarium::getCoin(double x, double y) const {
}

Food Aquarium::getFood(double x, double y) const {
}