// Week1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

typedef std::vector<std::string> vector;
enum Orientation { North, South, East, West };

void getParsedInput(const std::string &input, vector &moves, const char &demiliter)
{
	std::stringstream temp;
	temp.str(input);
	std::string item;
	while (std::getline(temp, item, demiliter))
	{
		item.erase(0, item.find_first_not_of(' '));
		moves.push_back(item);
	}
}


int getShortestPath(vector &moves)
{
	Orientation currentOrientation = Orientation::North;
	int xDistance = 0, yDistance = 0;
	vector::iterator it = moves.begin();
	while (it != moves.end())
	{
		std::string currentMove = *it;
		switch (currentOrientation)
		{
		case Orientation::North:
			if (currentMove[0] == 'L')
			{
				currentOrientation = Orientation::West;
				xDistance -= std::atoi(currentMove.substr(1).c_str());
			}
			else
			{
				currentOrientation = Orientation::East;
				xDistance += std::atoi(currentMove.substr(1).c_str());
			}
			break;
		case Orientation::South:
			if (currentMove[0] == 'L')
			{
				currentOrientation = Orientation::East;
				xDistance += std::atoi(currentMove.substr(1).c_str());
			}
			else
			{
				currentOrientation = Orientation::West;
				xDistance -= std::atoi(currentMove.substr(1).c_str());
			}
			break;
		case Orientation::East:
			if (currentMove[0] == 'L')
			{
				currentOrientation = Orientation::North;
				yDistance += std::atoi(currentMove.substr(1).c_str());
			}
			else
			{
				currentOrientation = Orientation::South;
				yDistance -= std::atoi(currentMove.substr(1).c_str());
			}

			break;
		case Orientation::West:
			if (currentMove[0] == 'L')
			{
				currentOrientation = Orientation::South;
				yDistance -= std::atoi(currentMove.substr(1).c_str());
			}
			else
			{
				currentOrientation = Orientation::North;
				yDistance += std::atoi(currentMove.substr(1).c_str());
			}
			break;
		}
		++it;
	}
	return abs(xDistance) + abs(yDistance);
}

int main()
{
	vector moves;
	std::string input = "R3, R1, R4, L4, R3, R1, R1, L3, L5, L5, L3, R1, R4, L2, L1, R3, L3, R2, R1, R1, L5, L2, L1, R2, L4, R1, L2, L4, R2, R2, L2, L4, L3, R1, R4, R3, L1, R1, L5, R4, L2, R185, L2, R4, R49, L3, L4, R5, R1, R1, L1, L1, R2, L1, L4, R4, R5, R4, L3, L5, R1, R71, L1, R1, R186, L5, L2, R5, R4, R1, L5, L2, R3, R2, R5, R5, R4, R1, R4, R2, L1, R4, L1, L4, L5, L4, R4, R5, R1, L2, L4, L1, L5, L3, L5, R2, L5, R4, L4, R3, R3, R1, R4, L1, L2, R2, L1, R4, R2, R2, R5, R2, R5, L1, R1, L4, R5, R4, R2, R4, L5, R3, R2, R5, R3, L3, L5, L4, L3, L2, L2, R3, R2, L1, L1, L5, R1, L3, R3, R4, R5, L3, L5, R1, L3, L5, L5, L2, R1, L3, L1, L3, R4, L1, R3, L2, L2, R3, R3, R4, R4, R1, L4, R1, L5";
	getParsedInput(input, moves, ',');
	std::cout << "Shortest distance  : " << getShortestPath(moves);
	std::getchar();
	return 0;
}