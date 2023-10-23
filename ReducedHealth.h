#pragma once
#include "EventInterface.h"
#include "PlayerMovement.h"

class ReducedHealth : public EventInterface {

private:
	PlayerMovement* movement;
public:
	explicit ReducedHealth(PlayerMovement* pmovement);
	void someEvent()override;

};