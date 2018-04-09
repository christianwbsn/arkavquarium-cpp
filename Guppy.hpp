#ifndef __GUPPY_HPP
#define __GUPPY_HPP
#include "Fish.hpp"
using namespace std;

class Guppy : public Fish{
    private:
        int size;
        int coinTime;
        int coinValue;
        int foodEaten;
        const int baseCoinTime = 3;
    public:
        Guppy();
        Guppy operator=(const Guppy& G);
        int getSize() const;
        
        void eatFood();
        void grow();
        Coin extractCoin();
        
};
#endif
