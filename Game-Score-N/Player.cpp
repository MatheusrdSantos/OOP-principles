#include "Player.h"

Player::Player(string name){
    this->name = name;
    this->score = 0;
    this->inGame = true;
}

// remove player from match (the player choose to stop)
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

// overload operator <<
std::ostream& operator<<(std::ostream &stream, Player* const player){
    stream<<endl<<"Name: "<<player->name<<endl;
    stream<<"Score: "<<player->score<<endl<<endl;
    return stream;
}

// add score
void Player::sumScore(int sum){
    this->score+=sum;
}