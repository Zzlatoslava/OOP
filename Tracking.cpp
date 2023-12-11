#include "Tracking.h"


Tracking::Tracking(Player* player, GameField* nMap, PlayerMovement* nNav, InputReader* read, int mLevel)
{
    if (player == nullptr || nMap == nullptr || nNav == nullptr || read == nullptr) {
        throw "Error in creating a Tracking class object\n";
    }
    this->p = player;
    this->map = nMap;
    this->nav = nNav;
    this->level = mLevel;
    this->reader = read;
    
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

std::string  Tracking::printIndicators()
{

    return "\n\tScore: " + std::to_string(p->getScore()) + "\n"+ "\tHealth: " + std::to_string(p->getHealth()) + "\n";
   // std::cout << "X: " << nav->getXCoordinate() << "\n";
    //std::cout << "Y: " << nav->getYCoordinate() << "\n";
}

std::string Tracking::printCoords()
{
    return "\n\tX: " + std::to_string(nav->getXCoordinate()) + "\n"+ "\tY: " + std::to_string(nav->getYCoordinate()) + "\n";
}

std::string Tracking::printForNewGame()
{
    return "\n\tSize field: " + std::to_string(map->getWidth())+ "*" + std::to_string(map->getHeight()) + "\n\tx:" + std::to_string(map->getStartX()) + " y:" + std::to_string(map->getStartY());
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

int Tracking::getDoubleScore()
{
    return p->getDoubleScore();
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
        case 5:
            return Double;
        }
    }
    return None;
}

void Tracking::update()
{
    p->setHealth(HEALTH);
    nav->setCoordinates(map->getStartX(), map->getStartY());
    totalScore = totalScore + p->getScore() + p->getDoubleScore();
    p->setScore(0);
    p->setDoubleScore(0);
    map->updateMap();
}

int Tracking::getKeyRead()
{
    return reader->getKey();
}

std::string Tracking::moveToString(Move command)
{
    switch (command) {
    case move_up:
        return "move_up";
    case move_down:
        return "move_down";
    case move_right:
        return "move_right";
    case move_left:
        return "move_left";
    }
}

