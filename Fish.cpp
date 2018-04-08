#include "Fish.hpp"
#include <cstdlib>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

using namespace std;

Fish::Fish()
{
    this->xPos = (double)(rand() % SCREEN_WIDTH + 1);
    this->yPos = (double)(rand() % SCREEN_HEIGHT + 1);
    this->foodEaten = 0;
    this->direction = rand()%2 == 0? true:false;
    this->hungerTime = 100;
}
)
void Fish::move(double dx, double dy){
    this->xPos += dx;
    this->yPos += dy;
}

double Fish::getXPos() const{
    return this->xPos;
}

double Fish::getYPos() const{
    return this->yPos;
}
bool Fish::getDirection() const{
    return this->direction;
}
int Fish::getHungerTime() const{
    return this->hungerTime;
}

int Fish::getSpeed() const{
    return this->speed;
}