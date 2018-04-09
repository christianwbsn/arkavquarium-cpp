#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include "Aquarium.hpp"
const double speed = 50; // pixels per second

int main( int argc, char* args[] )
{
    init();
    Aquarium tank;
    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

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
        draw_image("Aquarium4.jpg", 320.0, 240.0);
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        if(get_change_click()){
            reset_click_change();
            click_x = get_click_x();
            click_y = get_click_y();
            FishFood food(click_x,click_y);
            tank.listOfFishFood.add(food);
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
            case SDLK_r:
                cy = SCREEN_HEIGHT / 2;
                cx = SCREEN_WIDTH / 2;
                break;
            // x untuk keluar
            case SDLK_x:
                running = false;
                break;
            
            case SDLK_f:
                Guppy ikan;
                tank.listOfGuppy.add(ikan);
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

        // Gambar ikan di posisi yang tepat.
        draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        draw_text("tujuan", 18, 50, 450, 0, 0, 0);
        for(int i=0;i<tank.listOfFishFood.getSize();i++){
            draw_image("images/Food.png",tank.listOfFishFood.get(i).getXPos(),tank.listOfFishFood.get(i).getYPos());
        }
        for(int i=0;i<tank.listOfGuppy.getSize();i++){
            draw_image("Guppsy.png",tank.listOfGuppy.get(i).getXPos(),tank.listOfGuppy.get(i).getYPos());
        }
        draw_image("Guppsy.png", cx, cy);
        draw_image("Guppsy.png", 250.0, cy);
        update_screen();
        for(int i=0;i<tank.listOfFishFood.getSize();i++){
            // cout<<tank.listOfFishFood.get(i).getYPos()<<endl;
            tank.listOfFishFood.get(i).move();
        }
        double xx;
        double yy;
        double sebelum = time_since_start();
        for(int i=0;i<tank.listOfGuppy.getSize();i++){
            // cout << time_since_start()<< endl;
                // double tandax = rand()%2;
                // tandax = tandax==0?-1.0:1.0;
                // double tanday = rand()%2;
                // tanday = tanday==0?-1.0:1.0;
                double xx = (double)(rand() % SCREEN_WIDTH + 1);
                cout << xx << ":";
                double yy = (double)(rand() % SCREEN_HEIGHT + 1);
                cout << yy << endl;
                cout << "masuk" << endl;
            

            // double t = (rand()%45 + 5)*0.1;
            tank.listOfGuppy.get(i).move(50.0,450.0,sec_since_last);       
        }
    }

    close();

    return 0;
}
