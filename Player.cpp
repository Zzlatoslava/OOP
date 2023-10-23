#include "Player.h"
#include <iostream>


Player::Player(int initialHealth, int initialScore) { //constructor
    if (HEALTH < initialHealth < 0 || SCORE < initialScore < 0) {
        throw "Error in creating a Player class object \n";
    }
    this->health = initialHealth;
    this->score = initialScore;
}

int Player::getHealth() const {
    return health;
}

void Player::setHealth(int newHealth) {
    if (HEALTH < newHealth < 0) {
        throw "Invalid value score in setHealth()\n";
        
    }
    health = newHealth;
}
int Player::getScore() const{
    return score;
}

void Player::setScore(int newScore) {
    if (SCORE < newScore < 0) {
        throw "Invalid value score in setScore()\n";
        
    }
    score = newScore;
}

