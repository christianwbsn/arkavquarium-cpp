#ifndef __GUPPY_HPP
#define __GUPPY_HPP
#include "Fish.hpp"
#include "Position.hpp"
using namespace std;

class Guppy : public Fish{
    private:
        int size;
        double coinTime;
        int coinValue;
        int foodEaten;
        const double baseCoinTime = 15.0;
    public:
        Guppy();
        Guppy operator=(const Guppy& G);
        int getSize() const;
        int getCoinValue() const;
        double getCoinTime() const;
        void setCoinTime(double t);
        void eatFood();
        void grow();
        Coin extractCoin();
        
};
#endif
