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

Piranha::Piranha() {
}

Coin Piranha::extractCoin(int size) {
	int val;
	val = 100 * (size + 1);
	
	return Coin(val, this->getXPos(), this->getYPos());
}

void Piranha::eatFood() {
	//nanti
}
