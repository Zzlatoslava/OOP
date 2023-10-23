#pragma once
#include "EventInterface.h"

class CollectAPoint : public EventInterface {
private:
	PlayerMovement* movement;

public:
	explicit CollectAPoint(PlayerMovement* pmovement);
	void someEvent()override;

};