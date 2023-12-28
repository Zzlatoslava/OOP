#pragma once
#include <cmath>

class SeekAndMoveScheme
{
public:
	template<typename T>
	static void Move(T& enemy);

};


template<typename T>
static void SeekAndMoveScheme::Move(T& enemy)
{
	int pX = enemy.getMovement().getXCoordinate();
	int pY = enemy.getMovement().getYCoordinate();
	int eX = enemy.getCoordX();
	int eY = enemy.getCoordY();
	if (abs(eX - pX) <= 4 || abs(eY - pY) <= 4) {

		if (eX - pX > 0 && enemy.getField().getPassability(eX - 1, eY)) {
			enemy.setCoord(eX - 1, eY);
			
		}
		else if (eX - pX < 0 && enemy.getField().getPassability(eX + 1, eY)) {
			enemy.setCoord(eX + 1, eY);
			
		}
		else if (eY - pY > 0 && enemy.getField().getPassability(eX, eY - 1)) {
			enemy.setCoord(eX, eY - 1);
			
		}
		else if (eY - pY < 0 && enemy.getField().getPassability(eX, eY + 1)) {
			enemy.setCoord(eX, eY + 1);
			
		}

	}

}