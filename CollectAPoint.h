#pragma once
#include "EventInterface.h"
#include "PlayerMovement.h"

class CollectAPoint : public EventInterface {
private:
	PlayerMovement* movement;
	int id = 3;
public:
	explicit CollectAPoint(PlayerMovement* pmovement);
	void someEvent()override;
	int getID() override;
};