#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_

#include <string>
#include <list>
#include "Player.h"
using namespace std;
class GameController{
    private:
        int limitScore;
        int rounds;
        list<Player*> players;
        int playersRemaining;
    public:
        GameController(int limitScore);
        ~GameController(){};

        void addPlayer(Player* player);
        void nextRound();
        void playerTurn(Player* player);
        void start();
        void displayWinner();
        void displayScores();
};

#endif