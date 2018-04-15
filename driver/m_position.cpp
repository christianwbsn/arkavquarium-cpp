#include "../src/Position.hpp"
#include <iostream>
using namespace std;

int main() {
    Position P1, P2(100,200);
    cout << "P1(" << P1.getXPos() << "," << P1.getYPos() << ")" << endl;
    cout << "P2(" << P2.getXPos() << "," << P2.getYPos() << ")" << endl;
    P1.setXPos(20); cout << "Set P1 X to 20" << endl;
    cout << "P1(" << P1.getXPos() << "," << P1.getYPos() << ")" << endl;
    P2.setYPos(20); cout << "Set P2 Y to 20" << endl;
    cout << "P2(" << P2.getXPos() << "," << P2.getYPos() << ")" << endl;
    return 0;
}