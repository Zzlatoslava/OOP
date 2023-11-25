#pragma once

#include "Cell.h"
#define MAX_WIDTH 30
#define MAX_HEIGHT 20

class GameField {
private:
	int width;
	int height;
	Cell** cells;
	int startX,startY;
	int endX, endY;
public:
	GameField(int width = MAX_WIDTH, int height = MAX_HEIGHT, int x1 = 0, int y1 = 0,int x2 = MAX_WIDTH - 1, int y2 = MAX_HEIGHT - 1);
	~GameField();
	GameField(const GameField& remake);
	GameField& operator = (const GameField& remake);
	GameField(GameField&& remake);
	GameField& operator = (GameField&& remake);
	int getWidth();
	int getHeight();
	int getStartX();
	int getStartY();
	int getEndX();
	int getEndY();
	void setStart(int x1, int y1);
	void setEnd(int x2, int y2);
	void setWidth(int newWidth);
	void setHeight(int newHeight);
	const Cell& getCell(int x, int y);
	void setPassability(int x, int y, bool passability = true);
	bool getPassability(int x, int y);
	bool outOfField(int x, int y);
	void setEvent( EventInterface* event, int x, int y);
	EventInterface& getEvent(int x, int y);
	bool isEvent(int x, int y);
	void activeEvent(int x, int y);

};