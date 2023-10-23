#pragma once
#include "Player.h"
#include "GameField.h"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class PlayerMovement  {
private:
    Player* player;
    int x, y;
    GameField* gameField;

public:
    PlayerMovement(Player* p, int x, int y, GameField* field);
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
    

    
};