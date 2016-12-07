// Day 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<map>
#include<string>
#include<fstream>
#include <iostream>
#include <sstream>
#include "Day 6.h"

typedef std::map<char, int> Map;
typedef std::vector<Map> VectorMap;
typedef std::string String;

String parseInput(const String inputFile,int &maxLength)
{
	String input;
	std::ifstream file(inputFile);
	if (file.is_open())
	{
		String line;
		while (getline(file,line))
		{
			if (line.length() > maxLength)
				maxLength = line.length();
			input.append(line).append("\n");
		}
	}

	return input;
}

void CreateMessageMap(const String input,VectorMap &messageMap)
{
	String currentLine;
	std::stringstream inputstream;
	inputstream.str(input);
	while (getline(inputstream, currentLine, '\n'))
	{
		int index = 0;
		VectorMap::iterator it = messageMap.begin();
		while (index < currentLine.length())
		{
			char currentCharacter = currentLine[index];
			Map *vmap = &messageMap[index];

			Map::iterator map_it = vmap->find(currentCharacter);

			if (map_it != vmap->end())
			{
				map_it->second++;
			}
			else
			{
				vmap->insert(std::pair<char, int>(currentCharacter, 1));
			}
			++index;
		}
	}
}

void MostCommon(VectorMap &messageMap, String &message)
{
	VectorMap::iterator vector_it = messageMap.begin();
	while (vector_it != messageMap.end())
	{
		Map &tmap = *vector_it;
		Map::iterator it = tmap.begin();
		int max = INT_MIN;
		char c;
		while (it != tmap.end())
		{

			if (it->second > max)
			{
				max = it->second;
				c = it->first;
			}
			++it;
		}
		message += c;
		++vector_it;
	}

}

void LeastCommon( VectorMap &messageMap, String &message)
{
	VectorMap::iterator vector_it = messageMap.begin();
	while (vector_it != messageMap.end())
	{
		Map &tmap = *vector_it;
		Map::iterator it = tmap.begin();
		int max = INT_MAX;
		char c;
		while (it != tmap.end())
		{

			if (it->second < max)
			{
				max = it->second;
				c = it->first;
			}
			++it;
		}
		message += c;
		++vector_it;
	}
}

int main(int argc, char** argv)
{
	int maxLength = 0;
	String mostCommon, leastCommon;
	String inputFile = argv[1];
	String input = parseInput(inputFile, maxLength);
	VectorMap *messageMap = new VectorMap(maxLength);
	CreateMessageMap(input,*messageMap);
	MostCommon(*messageMap, mostCommon);
	LeastCommon(*messageMap, leastCommon);
	std::cout << "Most Common Message : " << mostCommon<<std::endl;
	std::cout << "Least Common Message : "<< leastCommon << std::endl;
	
	std::getchar();
	return 0;
}

