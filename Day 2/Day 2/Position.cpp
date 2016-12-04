#include "Position.h"

Position::Position(int x, int y)
{
	xCordinate = x;
	yCordinate = y;
}

void Position::setPosition(int x, int y)
{
	xCordinate = x;
	yCordinate = y;
}

void Position::setgridSize(int n)
{
	gridSize = n;
}

int* Position::getX() 
{
	return &xCordinate;
}

int* Position::getY() 
{
	return &yCordinate;
}


Position Position::getPosition()
{
	return Position(xCordinate,yCordinate);
}

void Position::moveLeft(char **keypad)
{
	if(checkGridSize() && (yCordinate >=1) && (keypad[xCordinate][yCordinate-1] - '0'))
   setPosition(xCordinate, yCordinate-1);
}

void Position::moveRight(char **keypad)
{    
	if(checkGridSize() && (yCordinate < gridSize - 1) && (keypad[xCordinate][yCordinate + 1] - '0'))
	setPosition(xCordinate , yCordinate + 1);
}

void Position::moveDown(char **keypad)
{
	if (checkGridSize() && (xCordinate < gridSize - 1) && (keypad[xCordinate+1][yCordinate] - '0'))
		setPosition(xCordinate + 1, yCordinate);
}

void Position::moveUp(char **keypad)
{
	if(checkGridSize() && (xCordinate >= 1) && (keypad[xCordinate-1][yCordinate] - '0'))
	setPosition(xCordinate-1 , yCordinate);
}

bool Position::checkGridSize()
{
	if (gridSize <= 0)
	{
		std::cerr << "Grid size cannot be zero\n";
	    abort();
	}
	return true;
}

