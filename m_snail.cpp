#include "Snail.hpp"
#include <iostream>
using namespace std;

int main(){
    Snail S1(100); cout << "Constructor Called" << endl;
    cout << "Snail X Position: " << S1.getXPos() << endl;
    cout << "Snail Y Position: " << S1.getYPos() << endl;
    cout << "Snail Direction: " << S1.getDirection() << endl;
    return 0;
}
