#include <iostream>
#include "PlayerMovement.h"

PlayerMovement::PlayerMovement(Player* p, GameField* field ,int start_x, int start_y) {
    if (p == nullptr || MAX_WIDTH < start_x || start_x < 0 || MAX_HEIGHT < start_y || start_y < 0 || field == nullptr) {
        throw "Error in creating a PlayerMovement class object\n";
    }
    player = p;
    x = start_x;
    y = start_y;
    gameField = field;
    isMove = false;

}
void PlayerMovement::move(Direction direction) {
    isMove = false;
    int newX = x;
    int newY = y;
    switch (direction) {
        case UP:
            newY--;
            if (gameField->getPassability(newX, newY) && gameField->outOfField(newX, newY)) {
                isMove =  true;
            }
            break;
        case DOWN:
            newY++;
            if (gameField->getPassability(newX, newY) && gameField->outOfField(newX, newY)) {
                isMove = true;
            }
            break;
        case LEFT:
            newX--;
            if (gameField->getPassability(newX, newY) && gameField->outOfField(newX, newY)) {
                isMove = true;
            }
            break;
        case RIGHT:
            newX++;
            if (gameField->getPassability(newX, newY) && gameField->outOfField(newX, newY)) {
                isMove = true;
            }
            break;
        default:
            break;

    }
    if (isMove) {
        this->setCoordinates(newX, newY);
        gameField->activeEvent(x, y);
    }
  
}
void PlayerMovement::increaseHealth(int addHealth) {
    
    int currentHealth = player->getHealth();
    if (currentHealth + addHealth > HEALTH) {
        player->setHealth(HEALTH);
    }
    else {
        player->setHealth(currentHealth + addHealth);
    }
    
}
void PlayerMovement::decreaseHealth(int decreaseHealth) {
    int currentHealth = player->getHealth();
    player->setHealth(currentHealth - decreaseHealth);
}

void PlayerMovement::increaseScore(int addScore) {
    
    int currentScore = player->getScore();
    if (currentScore + addScore > MAX_SCORE) {
        player->setScore(MAX_SCORE);
    }
    else {
        player->setScore(currentScore + addScore);
    }
    
}
int PlayerMovement::getHealth() const {
    return this->player->getHealth();
}
void PlayerMovement::setHealth(int newHealth) {
    this->player->setHealth(newHealth);
}
int PlayerMovement::getScore() const {
    return this->player->getScore(); 
}
void PlayerMovement::setScore(int newScore) {
        this->player->setScore(newScore);
        
}
void PlayerMovement::setCoordinates(int newX, int newY) {
    if (gameField->outOfField(newX, newY) ){
        this->x = newX;
        this->y = newY;
    }
}
int PlayerMovement::getXCoordinate() { return this->x; }
int PlayerMovement::getYCoordinate() { return this->y; }

void PlayerMovement::setPassabilityGF(int x, int y){
    gameField->setPassability(x, y);
}

bool PlayerMovement::getIsMove()
{
    return isMove;
}

void PlayerMovement::increaseDoubleScore(int addScore)
{
    int currentScore = player->getDoubleScore();
    if (currentScore + addScore > MAX_SCORE) {
        player->setDoubleScore(MAX_SCORE);
    }
    else {
        player->setDoubleScore(currentScore + addScore);
    }
}

int PlayerMovement::getDoubleScore() const
{
    return player->getDoubleScore();
}

void PlayerMovement::setDoubleScore(int newScore)
{
    this->player->setDoubleScore(newScore);
}



