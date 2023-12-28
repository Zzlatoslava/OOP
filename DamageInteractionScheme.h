#pragma once

class DamageInteractionScheme
{
public:
	template<typename T>
	static void Interact(T& enemy);
};


template<typename T>
void DamageInteractionScheme::Interact(T& enemy)
{
	int pX = enemy.getMovement().getXCoordinate();
	int pY = enemy.getMovement().getYCoordinate();
	int eX = enemy.getCoordX();
	int eY = enemy.getCoordY();
	if (pX == eX && pY == eY) {
		enemy.getMovement().decreaseHealth(1);
	}

}