#pragma once
#include "EventInterface.h"

class Cell {
private:
	bool passability; 
	EventInterface* event;
public:
	Cell( bool newPassability = true, EventInterface* newEvent = nullptr);
	void setPassability(bool passability = true);
	bool isPassability();
	EventInterface& getEvent();
	void setEventCell(EventInterface* newEvent);
	void workingEvent();
	bool isEventCell();
};