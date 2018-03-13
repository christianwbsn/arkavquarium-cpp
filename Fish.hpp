#include <iostream>
using namespace std;

class Fish{
    private:
        int size;
        int coinValue;
        bool direction;

        const int foodNeeded;
        const int fullTime;
        const int hungryTime;
        const int speed;

    public:
        //constructor
        Fish();
        //mengeluarkan koin setiap C waktu
        Coin extractCoin();
        //Memakan makanan
        virtual void eatFood()=0;
        //Bergerak sesuai dengan status
        virtual void move()=0;
        //Menambah size setelah memakan sejumlah makanan
        void grow();
        //Menentukan kapan ikan lapar dan kenyang
        void setStatus();
};