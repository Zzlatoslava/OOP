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

}
void PlayerMovement::move(Direction direction) {
    switch (direction) {
        case UP:
            if (gameField->getPassability(x, y++)) {
                this->setCoordinates(x, y++);
            }
            
            break;
        case DOWN:
            if (gameField->getPassability(x, y--)) {
                this->setCoordinates(x, y--);
            }
            break;
        case LEFT:
            if (gameField->getPassability(x--, y)) {
                this->setCoordinates(x--, y);
            }
            break;
        case RIGHT:
            if (gameField->getPassability(x++, y)) {
                this->setCoordinates(x++, y);
            }
            break;
        default:
            std::cout << "Error!\n";

    }
    gameField->activeEvent(this->x, this->y);

}
void PlayerMovement::increaseHealth(int addHealth) {
    
    int currentHealth = player->getHealth();
    player->setHealth(currentHealth + addHealth);
    
}
void PlayerMovement::decreaseHealth(int decreaseHealth) {
    int currentHealth = player->getHealth();
    player->setHealth(currentHealth - decreaseHealth);

    if (player->getHealth() < 1) {
        std::cout << "Game Over!";
        exit(1);
    }
}

void PlayerMovement::increaseScore(int addScore) {
    
    int currentScore = player->getScore();
    player->setScore(currentScore + addScore);
    
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



