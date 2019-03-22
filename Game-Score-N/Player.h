#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <list>
#include <random>
#include "Dice.h"
using namespace std;
class Player{
    private:
        string name;
        int score;
        list<Dice*> dices;
        bool inGame;
    public:
        Player(string name);
        ~Player(){};

        int throwDices();
        void exitGame();
        bool isInGame();
        string getName();
        int getScore();
        friend ostream& operator<< (ostream &stream, Player* player);
};

#endif