#pragma once
#include "EventInterface.h"

class AddingHealth : public EventInterface {

private:
	PlayerMovement* movement;
public:
	explicit AddingHealth(PlayerMovement* pmovement);
	void someEvent()override;

};