#include <iostream>
using namespace std;

class Coin{
private:
    int value;
    const int xPos;
    int yPos;
public:
    Coin();
    void move();
};
