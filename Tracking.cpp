#include "Tracking.h"


Tracking::Tracking(Player* player, GameField* nMap, PlayerMovement* nNav, int mLevel )
{
	if (player == nullptr || nMap == nullptr || nNav == nullptr) {
		throw "Error in creating a Tracking class object\n";
	}
	this->p = player;
	this->map = nMap;
	this->nav = nNav;
    this->level = mLevel;
    file.InputSettingsReader("keys.txt");
}

bool Tracking::winGame()
{
	if (nav->getXCoordinate() == map->getEndX() && nav->getYCoordinate() == map->getEndY()) {
		return true;
	}

	return false;
}

bool Tracking::movePlayer(Move * GUImove)
{   
    
    *GUImove = reader.read(file.getKeyList());

    return nav->move(moveSelection(*GUImove));
}

Direction Tracking::moveSelection(Move action)
{
    switch (action) {
    case move_up:
        std::cout << "^\n";
        return UP;

    case move_left:
        std::cout << "<\n";
        return LEFT;

    case move_right:
        std::cout << ">\n";
        return RIGHT;

    case move_down:
        std::cout << "v\n";
        return DOWN;
    default:
        return NONE;
    }
	
}

void Tracking::printIndicators()
{
    std::cout << "Score: " << p->getScore() << "\n";
    std::cout << "Health: " << p->getHealth() << "\n";
}

bool Tracking::dead()
{
    if (p->getHealth() < 1) {
        return true;
    }
    return false;
    
}

int Tracking::getLevel()
{
    return this->level;
}

void Tracking::setLevel(int mLevel)
{
    this->level = mLevel;
}

Event Tracking::getEvent(int x, int y)
{
   
    if (map->isEvent(x, y)) {
        int id = map->getEvent(x, y).getID();
        switch (id) {
        case 1:
            return Reduced;
        case 2:
            return None;
        case 3:
            return None;
        }
    }
    return None;
}


