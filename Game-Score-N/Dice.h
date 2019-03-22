#ifndef _DICE_H_
#define _DICE_H_

#include <string>
#include <list>
#include <random>
#include <iostream>
using namespace std;
class Dice{
    private:
        int value;
        random_device rd;
        default_random_engine gen;
        uniform_int_distribution<> dis;
    public:
        Dice();
        ~Dice(){};

        int throwDice();
        int getValue();
};

#endif