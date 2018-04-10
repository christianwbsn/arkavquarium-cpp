#ifndef __PIRANHA_HPP
#define __PIRANHA_HPP
#include "Fish.hpp"
#include "Guppy.hpp"
using namespace std;

class Piranha : public Fish{
    public:
        //konstruktor
        Piranha();
        
        //mengeluarkan coin
        Coin extractCoin();
        //memakan makanan
        void eatFood();
        Piranha operator=(const Piranha& P);
};
#endif