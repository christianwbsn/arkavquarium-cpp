#include "Guppy.hpp"

Guppy :: Guppy():Fish() {
	this->size = 1;
	this->coinTime = baseCoinTime;
	this->coinValue = 0;
	this->foodEaten = 0;
}

double Guppy::getCoinTime() const{
	return coinTime;
}
int Guppy::getSize() const {
	return this->size;
}
int Guppy::getCoinValue() const{
	return this->coinValue;
}

void Guppy::setCoinTime(double t){
	coinTime-=t;
}
Guppy Guppy :: operator=(const Guppy& G){
	this->size = G.size;
	this->coinTime = G.coinTime;
	this->coinValue = G.coinValue;
	this->foodEaten = G.foodEaten;
	Fish::operator=(G);
	return *this;
}

void Guppy::eatFood() {
	this->foodEaten++;
	this->hungerTime+=60;
	if ((this->foodEaten == 2) or (this->foodEaten == 5)) {
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
	coinTime = baseCoinTime;
	return Coin(coinValue, this->getXPos(), this->getYPos());
}
