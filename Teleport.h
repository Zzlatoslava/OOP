
#pragma once
#include "EventInterface.h"

class Teleport: public EventInterface {
private:
	PlayerMovement* movement;
public:
	explicit Teleport(PlayerMovement* pmovement);
	void someEvent()override;

};