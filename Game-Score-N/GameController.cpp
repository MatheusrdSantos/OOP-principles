#include "GameController.h"

GameController::GameController(int limitScore){
    this->limitScore = limitScore;
    this->rounds = 0;
    Dice* d1 = new Dice();
    this->dices.push_back(d1);
    Dice* d2 = new Dice();
    this->dices.push_back(d2);
    this->playersRemaining = 0;
}

void GameController::addPlayer(Player* player){
    this->players.push_back(player);
    this->playersRemaining++;
}

int GameController::throwDices(){
    auto it = this->dices.begin();
    auto end = this->dices.end();
    int score = 0;
    for(; it!=end; advance(it, 1))
    {
        int value = (*it)->throwDice();
        score+=value;
    }
    return score;
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
        player->sumScore(throwDices());
        cout<<"Your new score: "<<player->getScore()<<endl;
        if(player->getScore()>this->limitScore){
            cout<<"You lose!"<<endl;
            player->exitGame();
            this->playersRemaining--;
        }else if(player->getScore()==this->limitScore){
            this->playersRemaining=0;
        }
    }
}

void GameController::nextRound(){
    auto it = this->players.begin();
    auto end = this->players.end();
    for(; it!=end; advance(it, 1))
    {
        if((*it)->isInGame() && this->playersRemaining>1){
            cout<<endl;
            cout<<"MAX LIMIT: "<<this->limitScore<<endl;
            playerTurn((*it));
            cout<<"Players reamining: "<<this->playersRemaining<<endl;
        }
        this->rounds++;
    }
}

void GameController::displayWinner(){
    auto it = this->players.begin();
    auto end = this->players.end();

    int winnerScore = 0;
    for(; it!=end; advance(it, 1))
    {
        if((*it)->getScore()>winnerScore  && (*it)->getScore()<=this->limitScore){
            winnerScore = (*it)->getScore();
        }
    }

    it = this->players.begin();
    end = this->players.end();

    // if more than one player has the same score
    list<Player*> winners;
    for(; it!=end; advance(it, 1))
    {
        if((*it)->getScore()==winnerScore){
            winners.push_back(*it);
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

void GameController::displayScores(){
    auto it = this->players.begin();
    auto end = this->players.end();
    cout<<endl<<"Scores: "<<endl;
    for(; it!=end; advance(it, 1))
    {
       cout<<(*it)<<endl;
    }
    
}

void GameController::start(){
    Player p1("José");
    Player p2("Maria");
    Player p3("Ricardo");
    this->addPlayer(&p1);
    this->addPlayer(&p2);
    this->addPlayer(&p3);
    while(this->playersRemaining>1){
        nextRound();
    }
    displayScores();
    displayWinner();
}