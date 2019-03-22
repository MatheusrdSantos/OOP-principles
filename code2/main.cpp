#include <iostream>
#include <list>
#include "GameController.h"
#include "Player.h"
#include "Dice.h"

int main(int argc, char const *argv[]){

    Player p1("Matheus");
    Player p2("Joao");
    Player p3("Ricardo");
    GameController game(50);
    game.addPlayer(&p1);
    game.addPlayer(&p2);
    game.addPlayer(&p3);
    game.start();
    //cout<<p.throwDices()<<endl;
    return 0;
}
