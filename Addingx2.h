#pragma once
#include "EventInterface.h"
#include "PlayerMovement.h"


class Addingx2 :public EventInterface
{
private:
	PlayerMovement* movement;
	int id = 5;
	
public:
	explicit Addingx2(PlayerMovement* pmovement);
	void someEvent()override;
	int getID() override;
	
};

