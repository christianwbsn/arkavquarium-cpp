//~ #ifndef __PIRANHA_HPP
//~ #define __PIRANHA_HPP
//~ #include "Fish.hpp"
//~ #include "Guppy.hpp"
//~ using namespace std;

//~ class Piranha : public Fish{
    //~ public:
        //~ //konstruktor
        //~ Piranha();
        
        //~ //mengeluarkan coin
        //~ Coin extractCoin(int);
        //~ //memakan makanan
        //~ void eatFood();
//~ };
//~ #endif


#include "Piranha.hpp"

Piranha::Piranha():Fish(){
}

Coin Piranha::extractCoin() {
	int val;
	val = 100 * (10000 + 1);
	
	return Coin(val, this->getXPos(), this->getYPos());
}

void Piranha::eatFood() {
	//nanti
}
