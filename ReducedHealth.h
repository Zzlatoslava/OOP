#pragma once
#include "EventInterface.h"

class ReducedHealth : public EventInterface {

private:
	PlayerMovement* movement;
public:
	explicit ReducedHealth(PlayerMovement* pmovement);
	void someEvent()override;

};