#include "Cell.h"


Cell::Cell( bool newPassability, EventInterface* newEvent){
	this->passability = newPassability;
	this->event = newEvent;
}
void Cell::setPassability(bool passability ) {
	this->passability = passability;
};

bool Cell::isPassability() {
	return this->passability;
};



EventInterface& Cell::getEvent() {
	return *event;
}

void Cell::setEventCell(EventInterface* newEvent) {
	this->event = newEvent;
}

void Cell::workingEvent() {
	
		this->event->someEvent();
		
		
		if (event->getID() != 1) {
			this->event = nullptr;
		}
	

}

bool Cell::isEventCell() {
	if (this->event != nullptr) { return true; }
	return false;
}

void Cell::clearEvent()
{
	event = nullptr;
}
