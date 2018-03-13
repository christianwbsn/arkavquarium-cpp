// File: Piranha.hpp
#ifndef __PIRANHA__HPP
#define __PIRANHA__HPP

#include "Fish.hpp"
using namespace std;

class Piranha : public Fish{
public:
        // Constructor
        Piranha();
        void eatFood();
        void move();
};

#endif