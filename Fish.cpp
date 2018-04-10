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
    this->xDest = 0.0;
    this->yDest = 0.0;
    this->moveTime = 0;
    this->foodEaten = 0;
    this->direction = true;
    this->hungerTime = 60;
}

Fish& Fish :: operator=(const Fish& F){
    xPos = F.getXPos();
    yPos = F.getYPos();
    this->xDest = 0.0;
    this->yDest = 0.0;
    this->moveTime = 0;
    this->foodEaten = 0;
    this->direction = true;
    this->hungerTime = 50;
    return *this;
}
void Fish::move(double x, double y, double t, bool huntFood){
    if(huntFood){
        this->moveTime = (rand()%45 + 5)*0.1;
        this->xDest = x;
        this->yDest = y;
        if(this->xPos - this->xDest > 0){
            this->direction = true;
        }else{
            this->direction = false;
        }
    }else if(this->moveTime <= t || (abs(this->xDest - this->xPos) < 3 && abs(this->yDest - this->yPos) < 3)){
        this->hungerTime -= 2;
        this->moveTime = (rand()%45 + 5)*0.1;
        this->xDest = x;
        this->yDest = y;
        if(this->xPos - this->xDest > 0){
            this->direction = true;
        }else{
            this->direction = false;
        }
    }else{
        this->moveTime -= t;
    }
    double a = atan2(this->xDest-xPos,this->yDest-yPos);
    this->xPos += this->speed*sin(a)*t;
    this->yPos += this->speed*cos(a)*t;
    // cout << x << ":" << y << ":" << a << endl;
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

bool Fish::isHungry() const{
    return this->hungerTime < this->fullTimeLimit;
}