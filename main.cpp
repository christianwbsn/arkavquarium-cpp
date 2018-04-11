#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include "Aquarium.hpp"
const double speed = 50; // pixels per second

double calculateDistance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

int main( int argc, char* args[] )
{
    init();
    Aquarium tank;
    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";
    std::string money_text = "Money: Undefined";

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;

    bool running = true;

    double prevtime = time_since_start();

    Aquarium aq;
    cy = aq.getSnail().getYPos();
    cx = aq.getSnail().getXPos();

    double click_x = 0;
    double click_y = 0;
    double sebelum = 0;
    while (running) {
        clear_screen();
        draw_image("images/Aquarium4.jpg", 320.0, 240.0);
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        if(tank.listOfCoin.getSize() == 0 && tank.listOfGuppy.getSize() == 0 && tank.listOfPiranha.getSize() == 0 && tank.getMoney() == 0){
            draw_text("YOU LOSE", 50, 320, 240, 255, 0, 0);
        }

        if(get_change_click()){
            reset_click_change();
            click_x = get_click_x();
            click_y = get_click_y();
            bool isCoin = false;
            for(int i=0; i<tank.listOfCoin.getSize(); i++){
                double coinX = tank.listOfCoin.get(i).getXPos();
                double coinY = tank.listOfCoin.get(i).getYPos();
                double tempDist = calculateDistance(coinX, coinY, click_x, click_y);
                if(tempDist < 15){
                    tank.increaseMoney(tank.listOfCoin.get(i).getValue());
                    tank.listOfCoin.remove(tank.listOfCoin.get(i));
                    isCoin = true;
                    break;
                }
            }
            if(!isCoin){
                if(tank.getMoney() >= 10){
                    tank.decreaseMoney(10);
                    FishFood food(click_x,click_y);
                    tank.listOfFishFood.add(food);
                }
            }
        }
        
        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.
        for (auto key : get_pressed_keys()) {
            switch (key) {
            case SDLK_UP:
                cy -= speed * sec_since_last;
                break;
            case SDLK_DOWN:
                cy += speed * sec_since_last;
                break;
            case SDLK_LEFT:
                cx -= speed * sec_since_last;
                break;
            case SDLK_RIGHT:
                cx += speed * sec_since_last;
                break;
            }
        }
        double mult;
        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_r:{
                cy = SCREEN_HEIGHT / 2;
                cx = SCREEN_WIDTH / 2;
                break;
            }
            // x untuk keluar
            case SDLK_x:{
                running = false;
                break;
            }
            
            case SDLK_f:{
                if(tank.getMoney() >= 50){
                    tank.decreaseMoney(50);
                    Guppy ikan;
                    tank.listOfGuppy.add(ikan);
                }
                break;
            }

            case SDLK_p:{
                if(tank.getMoney() >= 100){
                    tank.decreaseMoney(100);
                    Piranha pir;
                    tank.listOfPiranha.add(pir);
                }
                break;
            }
            }
        }

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1) {
            std::ostringstream strs;
            strs << "FPS: " ;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();
            fpc_start = now;
            frames_passed = 0;
        }
        draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        std::ostringstream strs;
        strs << "Money: ";
        strs << tank.getMoney();
        money_text = strs.str();
        draw_text(money_text, 18, 10, 50, 0, 0, 0);


        for(int i=0;i<tank.listOfPiranha.getSize();i++){
            cout << "flag 1" << endl;
            double xx;
            double yy;
            bool huntFood = false;
            // cout << tank.listOfGuppy.get(i).getHungerTime() << endl;
            if(tank.listOfPiranha.get(i).getHungerTime() < 20){
                tank.listOfPiranha.remove(tank.listOfPiranha.get(i));
            }else if(tank.listOfPiranha.get(i).isHungry() && !tank.listOfGuppy.isEmpty()){
                huntFood = true;
                cout << "Piranha Lapar" << endl;
                double currX = tank.listOfPiranha.get(i).getXPos();
                double currY = tank.listOfPiranha.get(i).getYPos();
                double minDistance = __LDBL_MAX__;
                for(int j=0;j<tank.listOfGuppy.getSize();j++){
                    double tempX = tank.listOfGuppy.get(j).getXPos();
                    double tempY = tank.listOfGuppy.get(j).getYPos();
                    double tempDist = calculateDistance(tempX, tempY, currX, currY);
                    if(tempDist < minDistance){
                        minDistance = tempDist;
                        xx = tempX;
                        yy = tempY;
                    }
                    if(tempDist < 15){
                        tank.listOfPiranha.get(i).eatFood();
                        tank.listOfCoin.add(tank.listOfPiranha.get(i).extractCoin(tank.listOfGuppy.get(j).getSize()));
                        tank.listOfGuppy.remove(tank.listOfGuppy.get(j));
                    }
                }
            }else{
                xx = (double)(rand() % SCREEN_WIDTH + 1);
                yy = (double)(rand() % SCREEN_HEIGHT + 1);
            }
            tank.listOfPiranha.get(i).move(xx, yy, sec_since_last, huntFood); 
        }
        cout << "flag 2" << endl;

        for(int i=0;i<tank.listOfGuppy.getSize();i++){
            double xx;
            double yy;
            bool huntFood = false;
            
            if(tank.listOfGuppy.get(i).getHungerTime() < 20){
                tank.listOfGuppy.remove(tank.listOfGuppy.get(i));
            }else{
                if(tank.listOfGuppy.get(i).isHungry() && !tank.listOfFishFood.isEmpty()){
                    huntFood = true;
                    cout << "lapar coy" << endl;
                    double currX = tank.listOfGuppy.get(i).getXPos();
                    double currY = tank.listOfGuppy.get(i).getYPos();
                    double minDistance = __LDBL_MAX__;
                    for(int j=0;j<tank.listOfFishFood.getSize();j++){
                        double tempX = tank.listOfFishFood.get(j).getXPos();
                        double tempY = tank.listOfFishFood.get(j).getYPos();
                        double tempDist = calculateDistance(tempX, tempY, currX, currY);
                        if(tempDist < minDistance){
                            minDistance = tempDist;
                            xx = tempX;
                            yy = tempY;
                        }
                        if(tempDist < 15){
                            tank.listOfFishFood.remove(tank.listOfFishFood.get(j));
                            tank.listOfGuppy.get(i).eatFood();
                        }
                    }
                }else{
                    xx = (double)(rand() % SCREEN_WIDTH + 1);
                    yy = (double)(rand() % SCREEN_HEIGHT + 1);
                }
                if(tank.listOfGuppy.get(i).getSize() >= 2 && tank.listOfGuppy.get(i).getCoinTime()<=0){
                    tank.listOfCoin.add(tank.listOfGuppy.get(i).extractCoin());
                    cout << "masuk sini" << endl;
                }
                tank.listOfGuppy.get(i).move(xx, yy, sec_since_last, huntFood);
                tank.listOfGuppy.get(i).setCoinTime(sec_since_last);
            }
        }

        // Gambar ikan di posisi yang tepat.
        for(int i=0;i<tank.listOfPiranha.getSize();i++){
            if(tank.listOfPiranha.get(i).isHungry()){
                if(tank.listOfPiranha.get(i).getDirection()){
                    draw_image("images/Piranha_Hungry_left_side.png",tank.listOfPiranha.get(i).getXPos(),tank.listOfPiranha.get(i).getYPos());
                }else{
                    draw_image("images/Piranha_Hungry_right_side.png",tank.listOfPiranha.get(i).getXPos(),tank.listOfPiranha.get(i).getYPos());
                }    
            }
            else{
                if(tank.listOfPiranha.get(i).getDirection()){
                    draw_image("images/Piranha_left_side.png",tank.listOfPiranha.get(i).getXPos(),tank.listOfPiranha.get(i).getYPos());
                }else{
                    draw_image("images/Piranha_right_side.png",tank.listOfPiranha.get(i).getXPos(),tank.listOfPiranha.get(i).getYPos());
                }
            }
        }
        for(int i=0;i<tank.listOfFishFood.getSize();i++){
            draw_image("images/Food.png",tank.listOfFishFood.get(i).getXPos(),tank.listOfFishFood.get(i).getYPos());
        }
        for(int i=0;i<tank.listOfCoin.getSize();i++){
            if(tank.listOfCoin.get(i).getValue()==25){
                draw_image("images/Silver_coin.png",tank.listOfCoin.get(i).getXPos(),tank.listOfCoin.get(i).getYPos());
            }
            else if(tank.listOfCoin.get(i).getValue()==50){
                draw_image("images/Gold_coin.png",tank.listOfCoin.get(i).getXPos(),tank.listOfCoin.get(i).getYPos());
            }
            else{
                draw_image("images/Diamond_coin.png",tank.listOfCoin.get(i).getXPos(),tank.listOfCoin.get(i).getYPos());
            }
        }
        for(int i=0;i<tank.listOfGuppy.getSize();i++){
            // cout << tank.listOfGuppy.get(i).getDirection() << endl;
            if(tank.listOfGuppy.get(i).isHungry()){
                if(tank.listOfGuppy.get(i).getSize()==1){
                    if(tank.listOfGuppy.get(i).getDirection()){
                        draw_image("images/Small_Hungry_Guppsy_left_side.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }else{
                        draw_image("images/Small_Hungry_Guppsy_right_side.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }
                }
                else if(tank.listOfGuppy.get(i).getSize()==2){
                    if(tank.listOfGuppy.get(i).getDirection()){
                        draw_image("images/Medium_Hungry_Guppsy_left_side.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }else{
                        draw_image("images/Medium_Hungry_Guppsy_right_side.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }
                }
                else if(tank.listOfGuppy.get(i).getSize()==3){
                    if(tank.listOfGuppy.get(i).getDirection()){
                        draw_image("images/Hungry_Guppsy_left_side.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }else{
                        draw_image("images/Hungry_Guppsy_right_side.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }
                }
            }
            else{
                if(tank.listOfGuppy.get(i).getSize()==1){
                    if(tank.listOfGuppy.get(i).getDirection()){
                        draw_image("images/Small_Guppsy_left_side.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }else{
                        draw_image("images/Small_Guppsy_right_side.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }
                }
                else if(tank.listOfGuppy.get(i).getSize()==2){
                    if(tank.listOfGuppy.get(i).getDirection()){
                        draw_image("images/Medium_Guppsy_left_side.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }else{
                        draw_image("images/Medium_Guppsy_right_side.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }
                }
                else if(tank.listOfGuppy.get(i).getSize()==3){
                    if(tank.listOfGuppy.get(i).getDirection()){
                        draw_image("images/Guppsy.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }else{
                        draw_image("images/Guppsy_right_side.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
                    }
                }   
            }
            
        }
        for(int i=0;i<tank.listOfFishFood.getSize();i++){
            if(tank.listOfFishFood.get(i).getXPos() > SCREEN_WIDTH || tank.listOfFishFood.get(i).getXPos() < 0 || tank.listOfFishFood.get(i).getYPos() > SCREEN_HEIGHT || tank.listOfFishFood.get(i).getYPos() < 0){
                tank.listOfFishFood.remove(tank.listOfFishFood.get(i));
            }else{
                tank.listOfFishFood.get(i).move(sec_since_last);
            }
        }
        for(int i=0;i<tank.listOfCoin.getSize();i++){
            if(tank.listOfCoin.get(i).getXPos() > SCREEN_WIDTH || tank.listOfCoin.get(i).getXPos() < 0 || tank.listOfCoin.get(i).getYPos() > SCREEN_HEIGHT || tank.listOfCoin.get(i).getYPos() < 0){
                tank.listOfCoin.remove(tank.listOfCoin.get(i));
            }else{
                tank.listOfCoin.get(i).move(sec_since_last);
            }
        }
        double huntcoin = false;
        double xx;
        double yy;
        if(!(tank.listOfCoin.isEmpty())){
            huntcoin = true;
            double minDistance = __LDBL_MAX__;
                for(int j=0;j<tank.listOfCoin.getSize();j++){
                    double currX = tank.getSnail().getXPos();
                    double currY = tank.getSnail().getYPos();
                    double tempX = tank.listOfCoin.get(j).getXPos();
                    double tempY = tank.listOfCoin.get(j).getYPos();
                    double tempDist = calculateDistance(tempX, tempY, currX, currY);
                    if(tempDist < minDistance){
                        minDistance = tempDist;
                        xx = tempX;
                        yy = tempY;
                    }
                    if(tempDist < 15){
                        tank.increaseMoney(tank.listOfCoin.get(j).getValue());
                        tank.listOfCoin.remove(tank.listOfCoin.get(j));
                        
                    }
                }
        }
        else{
            xx = (double)(rand() % SCREEN_WIDTH + 1);
        }
        cout << xx << endl;
        tank.getSnail().move(xx, sec_since_last,huntcoin);
        if(tank.getSnail().getDirection()){
            draw_image("images/Snail_left_side.png", tank.getSnail().getXPos(), tank.getSnail().getYPos());
        }else{
            draw_image("images/Snail_right_side.png", tank.getSnail().getXPos(), tank.getSnail().getYPos());
        }
        update_screen();
    }

    close();

    return 0;
}
