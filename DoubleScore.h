#pragma once
#include "EventInterface.h"
#include "PlayerMovement.h"

class DoubleScore : public EventInterface {

private:
	PlayerMovement* movement;
	int id = 5;
public:
	explicit DoubleScore(PlayerMovement* pmovement);
	void someEvent()override;
	int getID() override;
};
