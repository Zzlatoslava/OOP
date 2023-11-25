#pragma once
#include "EventInterface.h"
#include "PlayerMovement.h"

class AddingHealth : public EventInterface {

private:
	PlayerMovement* movement;
	int id = 2;
public:
	explicit AddingHealth(PlayerMovement* pmovement);
	void someEvent()override;
	int getID() override;
};