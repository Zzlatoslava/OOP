#pragma once

#define HEALTH 9
#define SCORE 10
#define MAX_SCORE 50


class Player {
private:
    int health;
    int score;
    int doubleScore;

public:
    Player(int initialHealth = HEALTH, int initialScore = 0, int  newDoubleScore = 0);

    int getHealth() const;
    void setHealth(int newHealth);
    int getScore() const ;
    void setScore(int newScore);
    int getDoubleScore() const;
    void setDoubleScore(int newScore);
};
