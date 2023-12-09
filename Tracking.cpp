#include "Tracking.h"


Tracking::Tracking(Player* player, GameField* nMap, PlayerMovement* nNav, int mLevel)
{
    if (player == nullptr || nMap == nullptr || nNav == nullptr) {
        throw "Error in creating a Tracking class object\n";
    }
    this->p = player;
    this->map = nMap;
    this->nav = nNav;
    this->level = mLevel;
    
}

bool Tracking::winGame()
{
    if (nav->getXCoordinate() == map->getEndX() && nav->getYCoordinate() == map->getEndY()) {
        return true;
    }

    return false;
}

bool Tracking::movePlayer()
{

    return nav->getIsMove();
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
    std::cout << "X: " << nav->getXCoordinate() << "\n";
    std::cout << "Y: " << nav->getYCoordinate() << "\n";
}

bool Tracking::dead()
{
    if (p->getHealth() < 1) {
        return true;
    }
    return false;

}

int Tracking::getHealth()
{
    return p->getHealth();
}

int Tracking::getScore()
{
    return p->getScore();
}

int Tracking::getTotalScore()
{
    return this->totalScore;
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
            return Adding;
        case 3:
            return Collect;
        case 4:
            return Teleport;
        }
    }
    return None;
}

void Tracking::update()
{
    p->setHealth(HEALTH);
    nav->setCoordinates(map->getStartX(), map->getStartY());
    totalScore += p->getScore();
    p->setScore(0);
    //map->~GameField();
    map->updateMap();
}

