#include "Fish.hpp"
#include <cstdlib>
#include <cmath>

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

Fish& Fish :: operator=(const Fish& F){
    xPos = F.getXPos();
    yPos = F.getYPos();
    this->foodEaten = 0;
    this->direction = rand()%2 == 0? true:false;
    this->hungerTime = 100;
    return *this;
}
void Fish::move(double x, double y, double t){
    double a = atan2(x-xPos,y-yPos);
    xPos = xPos + cos(a)*t;
    yPos = yPos + cos(a)*t;
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