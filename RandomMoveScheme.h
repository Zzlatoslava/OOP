#pragma once
#include <random>
#include "Enemy.h"

template <class T1, class T2>
class Enemy;

class RandomMoveScheme
{
public:
	template<typename T>
	static void Move(T& enemy);
	
};




template<typename T>
static void RandomMoveScheme::Move(T& enemy)
{
    srand(time(0));
    int newX = enemy.getCoordX();
    int newY = enemy.getCoordY();
    bool flag = true;
    int tmp;
    while (flag) {
        int randChoice = rand() % 4 + 1;
        switch (randChoice) {
        case 1:
            tmp = newY - 1;
            if (enemy.getField().getPassability(newX, tmp) && enemy.getField().outOfField(newX, tmp)) {
                flag = false;
                newY--;
            }
            break;

        case 2:
            tmp = newY + 1;
            if (enemy.getField().getPassability(newX, tmp) && enemy.getField().outOfField(newX, tmp)) {
                flag = false;
                newY++;
            }
            break;
        case 3:
            tmp = newX + 1;
            if (enemy.getField().getPassability(tmp, newY) && enemy.getField().outOfField(tmp, newY)) {
                flag = false;
                newX++;
            }
            break;
        case 4:
            tmp = newX - 1;
            if (enemy.getField().getPassability(tmp, newY) && enemy.getField().outOfField(tmp, newY)) {
                flag = false;
                newX--;
            }
            break;
        }

    }
    enemy.setCoord(newX, newY);

}
