#pragma once
#include "Player.h"
#include "GameField.h"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

class PlayerMovement  {
private:
    Player* player;
    int x, y;
    GameField* gameField;
    bool isMove = false;

public:
    PlayerMovement(Player* p,  GameField* field, int x = 0 , int y = 0);
    void move(Direction direction);
    void increaseHealth(int addHealth);
    void decreaseHealth(int amount);
    void increaseScore(int amount);
    int getHealth() const;
    void setHealth(int newHealth);
    int getScore() const;
    void setScore(int newScore);
    void setCoordinates(int newX, int newY);
    int getXCoordinate();
    int getYCoordinate();
    void setPassabilityGF(int x, int y);
    bool getIsMove();
    void increaseDoubleScore(int amount);
    int getDoubleScore() const;
    void setDoubleScore(int newScore);
    

    
};