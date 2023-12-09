#pragma once
#include <string>

class RenderingInterface {

public:
	virtual void setBackground(std::string) = 0;
	virtual void level() = 0;
	virtual void cat_Before() = 0;
	virtual void cat_Back() = 0;
	virtual void cat_Left() = 0;
	virtual void cat_Right() = 0;
	virtual void water() = 0;
	virtual void heart() = 0;
	virtual void fish() = 0;
	virtual void teleport() = 0;
};