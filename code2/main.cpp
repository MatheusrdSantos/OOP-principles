#include <iostream>
#include <list>
#include "GameController.h"
#include "Player.h"
#include "Dice.h"

int main(int argc, char const *argv[]){

    Player p("Matheus");
    cout<<p.throwDices()<<endl;
    return 0;
}
