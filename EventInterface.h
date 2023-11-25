#pragma once
#include <ctime>
#include <random>

class EventInterface { 

public:
	virtual void someEvent() = 0;
	virtual int getID() = 0;
};

