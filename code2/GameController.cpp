#include "GameController.h"

GameController::GameController(int limitScore){
    this->limitScore = limitScore;
    this->rounds = 0;
    this->playersRemaining = 0;
}

void GameController::addPlayer(Player* player){
    this->players.push_back(player);
    this->playersRemaining++;
}

void GameController::playerTurn(Player* player){
    cout<<"Player turn: "<<player->getName()<<endl;
    cout<<"Your score: "<<player->getScore()<<endl;
    int command = 0;
    cout<<"Do you wanna play(1) or stop(0): ";
    cin>>command;
    if (command==0) {
        player->exitGame();
        this->playersRemaining--;
    }else{
        player->throwDices();
        cout<<"Your new score: "<<player->getScore()<<endl;
        if(player->getScore()>this->limitScore){
            cout<<"You lose!"<<endl;
            player->exitGame();
            this->playersRemaining--;
        }
    }
}

void GameController::nextRound(){
    auto it = this->players.begin();
    auto end = this->players.end();
    for(; it!=end; advance(it, 1))
    {
        if((*it)->isInGame()){
            playerTurn((*it));
        }
    }
}

void GameController::displayWinner(){
    auto it = this->players.begin();
    auto end = this->players.end();

    // if more than one player has the same score
    list<Player*> winners;
    int winnerScore = 0;
    for(; it!=end; advance(it, 1))
    {
        if((*it)->getScore()>=winnerScore && (*it)->getScore()<=this->limitScore){
            winners.push_back(*it);
            winnerScore = (*it)->getScore();
        }
    }

    cout<<"Winner(s): "<<endl;
    auto winner_it = winners.begin();
    auto winner_end = winners.end();
    for(; winner_it!=winner_end; advance(winner_it, 1))
    {
        cout<<(*winner_it);
    }
    
}

void GameController::start(){
    while(this->playersRemaining>0){
        nextRound();
    }
    displayWinner();
}