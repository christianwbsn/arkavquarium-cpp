#include "Position.hpp"
#include <iostream>
using namespace std;

int main() {
    Position P1, P2(100,200);
    cout << "P1(" << P1.getX() << "," << P1.getY() << ")" << endl;
    cout << "P2(" << P2.getX() << "," << P2.getY() << ")" << endl;
    P1.setX(20); cout << "Set P1 X to 20" << endl;
    cout << "P1(" << P1.getX() << "," << P1.getY() << ")" << endl;
    P2.setY(20); cout << "Set P2 Y to 20" << endl;
    cout << "P2(" << P2.getX() << "," << P2.getY() << ")" << endl;
    return 0;
}