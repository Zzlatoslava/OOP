#include "Player.h"
#include <iostream>


Player::Player(int initialHealth, int initialScore, int newDoubleScore) { //constructor
    if (HEALTH < initialHealth < 0 || SCORE < initialScore < 0) {
        throw "Error in creating a Player class object \n";
    }
    this->health = initialHealth;
    this->score = initialScore;
    this->doubleScore = newDoubleScore;
}

int Player::getHealth() const {
    return health;
}

void Player::setHealth(int newHealth) {
    if (HEALTH < newHealth || newHealth < 0) {
        throw "Invalid value score in setHealth()\n";
        
    }
    health = newHealth;
}
int Player::getScore() const{
    return score;
}

void Player::setScore(int newScore) {
    if (MAX_SCORE < newScore || newScore < 0) {
        throw "Invalid value score in setScore()\n";
        
    }
    score = newScore;
}

int Player::getDoubleScore() const
{
    return doubleScore;
}

void Player::setDoubleScore(int newScore)
{
    doubleScore = newScore;
}

