#include "../src/Aquarium.hpp"
#include "../src/Guppy.hpp"
#include "../src/Snail.hpp"
#include "../src/Coin.hpp"
#include <iostream>
using namespace std;


int main() {
    Aquarium tank; cout << "Constructor Aquarium called." << endl;
    Guppy G1,G2,G3;
    Piranha P1, P2, P3, P4;
    Coin C1,C2;
    tank.listOfGuppy.add(G1);
    tank.listOfGuppy.add(G2);
    tank.listOfGuppy.add(G3);
    tank.listOfCoin.add(C1);
    tank.listOfCoin.add(C2);
    tank.listOfPiranha.add(P1);
    tank.listOfPiranha.add(P2);
    tank.listOfPiranha.add(P3);
    tank.listOfPiranha.add(P4);
    cout << "Data Penghuni Aquarium :" << endl;
    cout << "Ada " << tank.getListOfGuppy().getSize() << " Guppy" << endl;
    cout << "Ada " << tank.getListOfCoin().getSize() << " Coin" << endl;
    cout << "Ada " << tank.getListOfPiranha().getSize() << " Piranha" << endl;
    cout << "Ada " << tank.getListOfFishFood().getSize() << " Fish Food" << endl;
    cout << "Ada 1 Snail di " << tank.getSnail().getXPos() << "," << tank.snail.getYPos() << endl;   
    return 0;
}
