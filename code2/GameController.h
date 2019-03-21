#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_

#include <string>
#include <list>
#include "Player.h"
using namespace std;
class GameController{
    private:
        int limitScore; 
        list<Player*> players;
    public:
        GameController(list<Player*> players, int limitScore);
        ~GameController(){};
};

#endif