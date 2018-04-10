#include "Piranha.hpp"

Piranha::Piranha():Fish(){
}

Piranha Piranha::operator=(const Piranha& P){
	Fish::operator=(P);
	return *this;
}

Coin Piranha::extractCoin() {
	int val;
	val = 100 * (10000 + 1);
	
	return Coin(val, this->getXPos(), this->getYPos());
}

void Piranha::eatFood() {
	this->hungerTime+=40;
}
