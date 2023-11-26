#pragma once
#include "EventInterface.h"
#include <typeinfo>
#include <iostream>

class Cell {
private:
	bool passability; 
	EventInterface* event;
public:
	Cell( bool newPassability = true, EventInterface* newEvent = 0);
	void setPassability(bool passability = true);
	bool isPassability();
	EventInterface& getEvent();
	void setEventCell(EventInterface* newEvent);
	void workingEvent();
	bool isEventCell();
	void clearEvent();
};