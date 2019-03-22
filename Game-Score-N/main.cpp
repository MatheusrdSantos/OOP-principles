#include <iostream>
#include <list>
#include "GameController.h"
#include "Player.h"
#include "Dice.h"

int main(int argc, char const *argv[]){
    GameController game(30);
    game.start();
    return 0;
}
