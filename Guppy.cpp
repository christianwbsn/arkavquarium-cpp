#include "Guppy.hpp"

Guppy :: Guppy():Fish() {
	this->size = 1;
	this->coinTime = 1;
	this->coinValue = 0;
	this->foodEaten = 0;
	this->baseCoinTime;
}

int Guppy::getSize() const {
	return this->size;
}

void Guppy::eatFood() {
	this->foodEaten++;
	if ((this->foodEaten == 3) or (this->foodEaten == 10)) {
		grow();
	}
}

void Guppy::grow() {
	this->size++;
	if (this->coinValue == 0) {
		this->coinValue = 50;
	}
	else if (this->coinValue == 50) {
		this->coinValue = 100;
	}
}

Coin Guppy::extractCoin() {
	int val;
	
	if (this->size == 2) {
		val = 50;
	}
	else if (this->size == 3) {
		val = 100;
	}
	
	return Coin(val, this->getXPos(), this->getYPos());;
}
