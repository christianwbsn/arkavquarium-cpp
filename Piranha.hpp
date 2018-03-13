#ifndef __PIRANHA_HPP
#define __PIRANHA_HPP
#include "Fish.hpp"
#include "Guppy.hpp"
using namespace std;

class Piranha : public Fish{
    public:
        Piranha();
        
        void extractCoin(int);
        void eatFood();
};
#endif