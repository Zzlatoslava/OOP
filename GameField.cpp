#include "GameField.h"


GameField::GameField(int width , int height, int x1 , int y1 , int x2 , int y2 ) {
    if (MAX_WIDTH < width || width <= 0 || MAX_HEIGHT < height || height <= 0) {
        throw "Error in creating a GameField class object\n";
    }

    this->width = width;
    this->height = height;
        cells = new Cell * [height];
        for (int i = 0; i < height; i++) {
            cells[i] = new Cell[width];
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                this->cells[i][j].setPassability();
            }
            
        }
        this->startX = x1;
        this->startY = y1;
        this->endX = x2;
        this->endY = y2;
}

GameField::~GameField() {
    for (int i = 0; i < height; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}


GameField::GameField(const GameField& remake)
{
    this->height = remake.height;
    this->width = remake.width;
    this->startX = remake.startX;
    this->startY = remake.startY;
    this->endX = remake.endX;
    this->endX = remake.endX;
    this->cells = new Cell * [this->height];

    for (int i = 0; i < this->height; i++) {
        cells[i] = new Cell[this->width];
        for (int j = 0; j < this->width; j++) {
            this->cells[i][j] = remake.cells[i][j];
        }
    }
}

GameField& GameField::operator = (const GameField& remake)
{
    GameField temp(remake);
    this->height = temp.height;
    this->width =  temp.width;
    this->startX = temp.startX;
    this->startY = temp.startY;
    this->endX = temp.endX;
    this->endX = temp.endX;
    this->cells = temp.cells;
    return *this;
}

GameField::GameField(GameField&& remake)
{
    this->height = remake.height;
    this->width = remake.width;
    this->startX = remake.startX;
    this->startY = remake.startY;
    this->endX = remake.endX;
    this->endX = remake.endX;
    this->cells = new Cell * [this->height];

    for (int i = 0; i < this->height; i++) {
        cells[i] = new Cell[this->width];
        for (int j = 0; j < this->width; j++) {
            this->cells[i][j] = remake.cells[i][j];
        }
    }
    remake.cells = nullptr;
    remake.height = 0;
    remake.width = 0;
    remake.startX = 0;
    remake.startY = 0;
    remake.endX = 0;
    remake.endY = 0;
}

GameField& GameField::operator = (GameField&& remake)
{
    if (this != &remake)
    {
        for (int i = 0; i < this->height; i++)
        {
            delete[] cells[i];
        }
        delete[] cells;
        this->height = remake.height;
        this->width = remake.width;
        this->startX = remake.startX;
        this->startY = remake.startY;
        this->endX = remake.endX;
        this->endX = remake.endX;
        this->cells, remake.cells;
        remake.cells = nullptr;
        remake.height = 0;
        remake.width = 0;
        remake.startX = 0;
        remake.startY = 0;
        remake.endX = 0;
        remake.endY = 0;
    }
    return *this;
}

int GameField::getWidth(){
    return width;
}
int GameField::getHeight() {
    return height;
}
void GameField::setWidth(int newWidth) {
    if (width < newWidth || newWidth <= 0) {
        throw "Invalid value width in setWidth()\n";
        
    }
    this->width = newWidth;
}
void GameField::setHeight(int newHeight) {
    if (height < newHeight || newHeight <= 0) {
        throw "Invalid value height in setHeight()\n";
       
    }
    this->height = newHeight;
    
}
int GameField::getStartX() {
    return startX;
}
int GameField::getStartY() {
    return startY;
}
int GameField::getEndX() {
    return endX;
}
int GameField::getEndY() {
    return endY;
}
void GameField::setStart(int x1, int y1) {
    if (height < y1 || y1 < 0 || width < x1 || x1 < 0) {
        throw "Invalid value in setStart()\n";
    }
    this->startX = x1;
    this->startY = y1;
}
void GameField::setEnd(int x2, int y2) {
    if (height < y2 || y2 < 0 || width < x2 || x2 < 0) {
        throw "Invalid value in setEnd()\n";
    }
    this->startX = x2;
    this->startY = y2;
}
const Cell& GameField::getCell(int x, int y) {
    if (height < y || y < 0 || width < x || x < 0) {
        throw "Invalid value in getCell()\n";
    }
    return cells[y][x];
}
void GameField::setPassability(int x, int y, bool passability ) {
    this->cells[y][x].setPassability(passability);
}
bool GameField::getPassability(int x, int y) {
    return this->cells[y][x].isPassability();
    
}
bool GameField::outOfField(int x, int y) {
    if (x > width || x < 0 || y > width || y < 0) {
        throw "Going beyond the game field\n";
    }
    return true;
}

void GameField::setEvent(EventInterface* event, int x, int y)
{
    if (not (getPassability(x, y)) || isEvent(x, y)) {
        throw "The event cannot be set\n";
    }
    this->cells[y][x].setEventCell(event);
}


EventInterface& GameField::getEvent(int x, int y) {
    return this->cells[y][x].getEvent();
}

bool GameField::isEvent(int x, int y) {
    if (cells[y][x].isEventCell()) { return true; }
    return false;
}

void GameField::activeEvent(int x, int y) {
    cells[x][y].workingEvent();
}


