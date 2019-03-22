#include "Player.h"

Player::Player(string name){
    this->name = name;
    this->score = 0;
    Dice* d1 = new Dice();
    this->dices.push_back(d1);
    Dice* d2 = new Dice();
    this->dices.push_back(d2);
    this->inGame = true;
}

int Player::throwDices(){
    auto it = this->dices.begin();
    auto end = this->dices.end();
    for(; it!=end; advance(it, 1))
    {
        int value = (*it)->throwDice();
        this->score+=value;
    }
    return this->score;
}

void Player::exitGame(){
    this->inGame = false;
}

bool Player::isInGame(){
    return this->inGame;
}

string Player::getName(){
    return this->name;
}

int Player::getScore(){
    return this->score;
}

std::ostream& operator<<(std::ostream &stream, Player* const player){
    stream<<endl<<"Name: "<<player->name<<endl;
    stream<<"Score: "<<player->score<<endl<<endl;
    return stream;
}