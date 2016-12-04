#pragma once
#include "stdafx.h"
#include <ostream>
#include <iostream>
 
class Position
{
public: 
	Position(int x, int y);
	void setPosition(int x,int y);
	int* getX();
	int* getY();
	void setgridSize(int n);
	Position getPosition();
	void moveLeft(char **keypad);
	void moveRight(char **keypad);
	void moveDown(char **keypad);
	void moveUp(char **keypad);
	bool checkGridSize();
	friend std::ostream& operator<<(std::ostream & os, Position& pos)
	{
		os << " " << *pos.getX() << "," << *pos.getY()<<"\n";
		return os;

	}

private:
	int xCordinate = 0, yCordinate = 0,gridSize=0;
};