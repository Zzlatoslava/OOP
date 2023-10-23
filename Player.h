#pragma once

#define HEALTH 9
#define SCORE 10


class Player {
private:
    int health;
    int score;

public:
    Player(int initialHealth = HEALTH, int initialScore = SCORE);

    int getHealth() const;
    void setHealth(int newHealth);
    int getScore() const ;
    void setScore(int newScore);
};
