#pragma once
#include <random>
class PushInteractionScheme
{
public:
	template<typename T>
	static void Interact(T& enemy);
};

template<typename T>
void PushInteractionScheme::Interact(T& enemy)
{
    int pX = enemy.getMovement().getXCoordinate();
    int pY = enemy.getMovement().getYCoordinate();
    int eX = enemy.getCoordX();
    int eY = enemy.getCoordY();
    if (pX == eX && pY == eY) {
        bool flag = true;
        srand(time(0));
        while (flag) {
            
            int randChoice = rand() % 4 + 1;
            switch (randChoice) {
            case 1:
                pY--;
                if (enemy.getField().getPassability(pX, pY) && enemy.getField().outOfField(pX, pY)) {
                    flag = false;
                }
                break;

            case 2:
                pY++;
                if (enemy.getField().getPassability(pX, pY) && enemy.getField().outOfField(pX, pY)) {
                    flag = false;
                }
                break;
            case 3:
                pX++;
                if (enemy.getField().getPassability(pX, pY) && enemy.getField().outOfField(pX, pY)) {
                    flag = false;
                }
                break;
            case 4:
                pX--;
                if (enemy.getField().getPassability(pX, pY) && enemy.getField().outOfField(pX, pY)) {
                    flag = false;
                }
                break;
            }
        }

        enemy.getMovement().setCoordinates(pX, pY);
        
        
    }



}
