#include "Coin.hpp"
#include <iostream>
using namespace std;

int main() {
    Coin C1(100,100,50);
    Coin C2(200,50,50);
    Coin C3;
    cout << "Coin C1:" << C1.getValue() << endl;
    cout << "Position: (" << C1.getXPos() << "," << C1.getYPos() << ")" << endl;
    cout << "Coin C2:" << C2.getValue() << endl;
    cout << "Position: (" << C2.getXPos() << "," << C2.getYPos() << ")" << endl;
    cout << "Coin C3:" << C3.getValue() << endl;
    cout << "Position: (" << C3.getXPos() << "," << C3.getYPos() << ")" << endl;
    for(int t = 0 ; t < 5; t++){
        C3.move(t);
        cout << "C3 Moving: (" << C3.getXPos() << "," << C3.getYPos() << ")" << endl;
    }
    return 0;
}