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
        const int baseCoinTime;
    public:
        Guppy();

        int getSize() const;
        
        void eatFood();
        void grow();
        Coin extractCoin();
        
};
#endif