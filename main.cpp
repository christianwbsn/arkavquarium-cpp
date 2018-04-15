#include "src/oop.hpp"
#include "src/Aquarium.hpp"
#include <iostream>
#include <math.h>
#include <sstream>

double calculateDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(int argc, char *args[])
{
    init();
    //initiate var that will be static every loop
    bool running = true;
    double prevtime = time_since_start();
    double click_x = 0;
    double click_y = 0;
    bool win = false;
    bool lose = false;

    //initiate Aquarium
    Aquarium tank;

    while (running)
    {
        clear_screen();

        //Add background
        draw_image("assets/images/Aquarium4.jpg", 320.0, 240.0);

        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();

        //win condition
        if (tank.getEgg() == 3)
        {
            win = true;
        }

        // lose condition
        if (tank.listOfCoin.getSize() == 0 &&
            tank.listOfGuppy.getSize() == 0 &&
            tank.listOfPiranha.getSize() == 0 &&
            tank.getMoney() < 50)
        {
            lose = true;
        }

        for (auto key : get_tapped_keys())
        {
            if (key == SDLK_x)
            {
                running = false;
            }
        }

        if (win)
        {
            draw_image("assets/images/Win.png", 320, 240);
        }
        else if (lose)
        {
            draw_image("assets/images/Lose.png", 320, 240);
        }
        else
        {
            // Handle keyboard input
            for (auto key : get_tapped_keys())
            {
                switch (key)
                {
                // f to buy guppy
                case SDLK_f:
                {
                    if (tank.getMoney() >= 50)
                    {
                        tank.decreaseMoney(50);
                        Guppy ikan;
                        tank.listOfGuppy.add(ikan);
                    }
                    break;
                }

                // p to buy piranha
                case SDLK_p:
                {
                    if (tank.getMoney() >= 100)
                    {
                        tank.decreaseMoney(100);
                        Piranha pir;
                        tank.listOfPiranha.add(pir);
                    }
                    break;
                }

                // e to buy egg
                case SDLK_e:
                {
                    if (tank.getEgg() == 0 && tank.getMoney() >= 200)
                    {
                        tank.buyEgg();
                        tank.decreaseMoney(200);
                    }
                    else if (tank.getEgg() == 1 && tank.getMoney() >= 350)
                    {
                        tank.buyEgg();
                        tank.decreaseMoney(350);
                    }
                    else if (tank.getEgg() == 2 && tank.getMoney() >= 500)
                    {
                        tank.buyEgg();
                        tank.decreaseMoney(500);
                    }
                }
                }
            }

            // Handle mouse input
            if (get_change_click())
            {
                reset_click_change();
                click_x = get_click_x();
                click_y = get_click_y();
                bool isCoin = false;
                for (int i = 0; i < tank.listOfCoin.getSize(); i++)
                {
                    double coinX = tank.listOfCoin.get(i).getXPos();
                    double coinY = tank.listOfCoin.get(i).getYPos();
                    double tempDist = calculateDistance(coinX, coinY, click_x, click_y);
                    if (tempDist < 15)
                    {
                        tank.increaseMoney(tank.listOfCoin.get(i).getValue());
                        tank.listOfCoin.remove(tank.listOfCoin.get(i));
                        isCoin = true;
                        break;
                    }
                }
                if (!isCoin)
                {
                    if (tank.getMoney() >= 10)
                    {
                        tank.decreaseMoney(10);
                        FishFood food(click_x, click_y);
                        tank.listOfFishFood.add(food);
                    }
                }
            }

            // Fish action
            double xx;
            double yy;
            // Guppy
            for (int i = 0; i < tank.listOfGuppy.getSize(); i++)
            {
                bool huntFood = false;

                // Kill guppy if hunger < 20
                if (tank.listOfGuppy.get(i).getHungerTime() < 20)
                {
                    tank.listOfGuppy.remove(tank.listOfGuppy.get(i));
                }
                else
                {
                    // guppy hungry and food is available
                    if (tank.listOfGuppy.get(i).isHungry() && !tank.listOfFishFood.isEmpty())
                    {
                        huntFood = true;
                        double currX = tank.listOfGuppy.get(i).getXPos();
                        double currY = tank.listOfGuppy.get(i).getYPos();
                        double minDistance = __LDBL_MAX__;
                        for (int j = 0; j < tank.listOfFishFood.getSize(); j++)
                        {
                            double tempX = tank.listOfFishFood.get(j).getXPos();
                            double tempY = tank.listOfFishFood.get(j).getYPos();
                            double tempDist = calculateDistance(tempX, tempY, currX, currY);
                            if (tempDist < minDistance)
                            {
                                minDistance = tempDist;
                                xx = tempX;
                                yy = tempY;
                            }
                            // eat food
                            if (tempDist < 15)
                            {
                                tank.listOfFishFood.remove(tank.listOfFishFood.get(j));
                                tank.listOfGuppy.get(i).eatFood();
                                break;
                            }
                        }
                    }
                    else
                    {
                        xx = (double)(rand() % SCREEN_WIDTH + 1);
                        yy = (double)(rand() % SCREEN_HEIGHT + 1);
                    }

                    // Generate coin if coin time <= 0
                    if (tank.listOfGuppy.get(i).getSize() >= 2 && tank.listOfGuppy.get(i).getCoinTime() <= 0)
                    {
                        tank.listOfCoin.add(tank.listOfGuppy.get(i).extractCoin());
                    }
                    // move guppy
                    tank.listOfGuppy.get(i).move(xx, yy, sec_since_last, huntFood);
                    // reduce guppy coin time
                    tank.listOfGuppy.get(i).setCoinTime(sec_since_last);
                }
            }

            for (int i = 0; i < tank.listOfPiranha.getSize(); i++)
            {
                bool huntFood = false;

                //kill piranha if hunger < 20
                if (tank.listOfPiranha.get(i).getHungerTime() < 20)
                {
                    tank.listOfPiranha.remove(tank.listOfPiranha.get(i));
                }
                else
                {
                    // piranha is hungry and food is available
                    if (tank.listOfPiranha.get(i).isHungry() && !tank.listOfGuppy.isEmpty())
                    {
                        huntFood = true;
                        double currX = tank.listOfPiranha.get(i).getXPos();
                        double currY = tank.listOfPiranha.get(i).getYPos();
                        double minDistance = __LDBL_MAX__;
                        for (int j = 0; j < tank.listOfGuppy.getSize(); j++)
                        {
                            double tempX = tank.listOfGuppy.get(j).getXPos();
                            double tempY = tank.listOfGuppy.get(j).getYPos();
                            double tempDist = calculateDistance(tempX, tempY, currX, currY);
                            if (tempDist < minDistance)
                            {
                                minDistance = tempDist;
                                xx = tempX;
                                yy = tempY;
                            }
                            // eat food
                            if (tempDist < 15)
                            {
                                tank.listOfPiranha.get(i).eatFood();
                                // extract coin
                                tank.listOfCoin.add(tank.listOfPiranha.get(i).extractCoin(tank.listOfGuppy.get(j).getSize()));
                                tank.listOfGuppy.remove(tank.listOfGuppy.get(j));
                                break;
                            }
                        }
                    }
                    else
                    {
                        xx = (double)(rand() % SCREEN_WIDTH + 1);
                        yy = (double)(rand() % SCREEN_HEIGHT + 1);
                    }
                    tank.listOfPiranha.get(i).move(xx, yy, sec_since_last, huntFood);
                }
            }

            // Snail
            bool huntcoin;
            if (!(tank.listOfCoin.isEmpty()))
            {
                huntcoin = true;
                double minDistance = __LDBL_MAX__;
                for (int j = 0; j < tank.listOfCoin.getSize(); j++)
                {
                    double currX = tank.getSnail().getXPos();
                    double currY = tank.getSnail().getYPos();
                    double tempX = tank.listOfCoin.get(j).getXPos();
                    double tempY = tank.listOfCoin.get(j).getYPos();
                    double tempDist = calculateDistance(tempX, tempY, currX, currY);
                    if (tempDist < minDistance)
                    {
                        minDistance = tempDist;
                        xx = tempX;
                        yy = tempY;
                    }
                    if (tempDist < 15)
                    {
                        tank.increaseMoney(tank.listOfCoin.get(j).getValue());
                        tank.listOfCoin.remove(tank.listOfCoin.get(j));
                    }
                }
            }
            else
            {
                xx = (double)(rand() % SCREEN_WIDTH + 1);
                huntcoin = false;
            }
            tank.getSnail().move(xx, sec_since_last, huntcoin);

            // Fish Food
            for (int i = 0; i < tank.listOfFishFood.getSize(); i++)
            {
                if (tank.listOfFishFood.get(i).getXPos() > SCREEN_WIDTH || tank.listOfFishFood.get(i).getXPos() < 0 || tank.listOfFishFood.get(i).getYPos() >= 450.0 || tank.listOfFishFood.get(i).getYPos() < 0)
                {
                    tank.listOfFishFood.remove(tank.listOfFishFood.get(i));
                }
                else
                {
                    tank.listOfFishFood.get(i).move(sec_since_last);
                }
            }
            // Coin
            for (int i = 0; i < tank.listOfCoin.getSize(); i++)
            {
                if (tank.listOfCoin.get(i).getYPos() >= 450.0)
                {
                    tank.listOfCoin.get(i).setYPos(450.0);
                }
                else
                {
                    tank.listOfCoin.get(i).move(sec_since_last);
                }
            }
            
            // DRAWING
            // Draw Text
            std::ostringstream temp1;
            temp1 << "Money: ";
            temp1 << tank.getMoney();
            std::string money_text = temp1.str();

            std::ostringstream temp2;
            temp2 << tank.getEgg() * 150 + 200;
            std::string egg_text = temp2.str();

            std::ostringstream temp3;
            temp3 << "Egg Bought: ";
            temp3 << tank.getEgg();
            std::string egg_bought = temp3.str();

            // Show current money
            draw_text(money_text, 18, 40, 10, 0, 0, 0);
            // Show current egg
            draw_text(egg_bought, 12, 535, 50, 0, 0, 0);

            // Show Price List
            draw_text("Price:", 15, 40, 35, 0, 0, 0);
            // Guppy
            draw_text("Guppy  :", 13, 40, 60, 0, 0, 0);
            draw_text("50", 13, 130, 60, 0, 0, 0);
            // Piranha
            draw_text("Piranha:", 13, 40, 80, 0, 0, 0);
            draw_text("100", 13, 130, 80, 0, 0, 0);
            // Egg
            draw_text("Egg        : ", 13, 40, 100, 0, 0, 0);
            draw_text(egg_text, 13, 130, 100, 0, 0, 0);

            // Show keyboard function
            draw_text("Press E to buy Egg", 11, 175, 10, 0, 0, 0);
            draw_text("Press F to buy Guppy", 11, 300, 10, 0, 0, 0);
            draw_text("Press P to buy Piranha", 11, 430, 10, 0, 0, 0);

            //Draw Piranha
            for (int i = 0; i < tank.listOfPiranha.getSize(); i++)
            {
                if (tank.listOfPiranha.get(i).isHungry())
                {
                    if (tank.listOfPiranha.get(i).getDirection())
                    {
                        draw_image("assets/images/Piranha_Hungry_left_side.png", tank.listOfPiranha.get(i).getXPos(), tank.listOfPiranha.get(i).getYPos());
                    }
                    else
                    {
                        draw_image("assets/images/Piranha_Hungry_right_side.png", tank.listOfPiranha.get(i).getXPos(), tank.listOfPiranha.get(i).getYPos());
                    }
                }
                else
                {
                    if (tank.listOfPiranha.get(i).getDirection())
                    {
                        draw_image("assets/images/Piranha_left_side.png", tank.listOfPiranha.get(i).getXPos(), tank.listOfPiranha.get(i).getYPos());
                    }
                    else
                    {
                        draw_image("assets/images/Piranha_right_side.png", tank.listOfPiranha.get(i).getXPos(), tank.listOfPiranha.get(i).getYPos());
                    }
                }
            }

            //Draw Guppy
            for (int i = 0; i < tank.listOfGuppy.getSize(); i++)
            {
                if (tank.listOfGuppy.get(i).isHungry())
                {
                    if (tank.listOfGuppy.get(i).getSize() == 1)
                    {
                        if (tank.listOfGuppy.get(i).getDirection())
                        {
                            draw_image("assets/images/Small_Hungry_Guppsy_left_side.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                        else
                        {
                            draw_image("assets/images/Small_Hungry_Guppsy_right_side.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                    }
                    else if (tank.listOfGuppy.get(i).getSize() == 2)
                    {
                        if (tank.listOfGuppy.get(i).getDirection())
                        {
                            draw_image("assets/images/Medium_Hungry_Guppsy_left_side.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                        else
                        {
                            draw_image("assets/images/Medium_Hungry_Guppsy_right_side.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                    }
                    else if (tank.listOfGuppy.get(i).getSize() == 3)
                    {
                        if (tank.listOfGuppy.get(i).getDirection())
                        {
                            draw_image("assets/images/Hungry_Guppsy_left_side.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                        else
                        {
                            draw_image("assets/images/Hungry_Guppsy_right_side.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                    }
                }
                else
                {
                    if (tank.listOfGuppy.get(i).getSize() == 1)
                    {
                        if (tank.listOfGuppy.get(i).getDirection())
                        {
                            draw_image("assets/images/Small_Guppsy_left_side.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                        else
                        {
                            draw_image("assets/images/Small_Guppsy_right_side.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                    }
                    else if (tank.listOfGuppy.get(i).getSize() == 2)
                    {
                        if (tank.listOfGuppy.get(i).getDirection())
                        {
                            draw_image("assets/images/Medium_Guppsy_left_side.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                        else
                        {
                            draw_image("assets/images/Medium_Guppsy_right_side.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                    }
                    else if (tank.listOfGuppy.get(i).getSize() == 3)
                    {
                        if (tank.listOfGuppy.get(i).getDirection())
                        {
                            draw_image("assets/images/Guppsy.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                        else
                        {
                            draw_image("assets/images/Guppsy_right_side.png", tank.listOfGuppy.get(i).getXPos(), tank.listOfGuppy.get(i).getYPos());
                        }
                    }
                }
            }

            //Draw Fish Food
            for (int i = 0; i < tank.listOfFishFood.getSize(); i++)
            {
                draw_image("assets/images/Food.png", tank.listOfFishFood.get(i).getXPos(), tank.listOfFishFood.get(i).getYPos());
            }

            //Draw Coin
            for (int i = 0; i < tank.listOfCoin.getSize(); i++)
            {
                if (tank.listOfCoin.get(i).getValue() == 25)
                {
                    draw_image("assets/images/Silver_coin.png", tank.listOfCoin.get(i).getXPos(), tank.listOfCoin.get(i).getYPos());
                }
                else if (tank.listOfCoin.get(i).getValue() == 50)
                {
                    draw_image("assets/images/Gold_coin.png", tank.listOfCoin.get(i).getXPos(), tank.listOfCoin.get(i).getYPos());
                }
                else
                {
                    draw_image("assets/images/Diamond_coin.png", tank.listOfCoin.get(i).getXPos(), tank.listOfCoin.get(i).getYPos());
                }
            }

            // Draw Snail
            if (tank.getSnail().getDirection())
            {
                if (huntcoin)
                {
                    draw_image("assets/images/Snail_left_side.png", tank.getSnail().getXPos(), tank.getSnail().getYPos());
                }
                else
                {
                    draw_image("assets/images/Snail_shel.png", tank.getSnail().getXPos(), tank.getSnail().getYPos());
                }
            }
            else
            {
                if (huntcoin)
                {
                    draw_image("assets/images/Snail_right_side.png", tank.getSnail().getXPos(), tank.getSnail().getYPos());
                }
                else
                {
                    draw_image("assets/images/Snail_shel_right.png", tank.getSnail().getXPos(), tank.getSnail().getYPos());
                }
            }

            // Draw egg
            if (tank.getEgg() == 0)
            {
                draw_image("assets/images/Egg_L1.png", 570, 30);
            }
            else if (tank.getEgg() == 1)
            {
                draw_image("assets/images/Egg_L2.png", 570, 30);
            }
            else if (tank.getEgg() == 2)
            {
                draw_image("assets/images/Egg_L3.png", 570, 30);
            }
        }
        update_screen();
    }

    close();
}