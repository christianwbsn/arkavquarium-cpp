#include "Piranha.hpp"

Piranha::Piranha():Fish(){
	
}

Piranha Piranha::operator=(const Piranha& P){
	Fish::operator=(P);
	return *this;
}

Coin Piranha::extractCoin(int val) {
	val = 100 * (val + 1);
	return Coin(val, this->getXPos(), this->getYPos());
}

void Piranha::eatFood() {
	this->hungerTime=60;
}