#include "Snail.hpp"
#include <iostream>
using namespace std;

int main(){
    Snail S1(100); cout << "Constructor Called" << endl;
    cout << S1.getXPos() << "," << S1.getYPos() << endl;
    cout << S1.getDirection() << endl;
    return 0;
}