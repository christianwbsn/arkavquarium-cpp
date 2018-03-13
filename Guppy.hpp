// File: Guppy.hpp
#ifndef __GUPPY__HPP
#define __GUPPY__HPP

#include "Fish.hpp"
using namespace std;

class Guppy : public Fish{
    private:
        const int coinTime;
    public:
        Guppy();
        void eatFood();
        void move();
};

#endif