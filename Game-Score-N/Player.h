#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <list>
#include<iostream>
using namespace std;
class Player{
    private:
        string name;
        int score;
        bool inGame;
    public:
        Player(string name);
        ~Player(){};

        int throwDices();
        void exitGame();
        bool isInGame();
        string getName();
        int getScore();
        void sumScore(int sum);
        friend ostream& operator<< (ostream &stream, Player* player);
};

#endif