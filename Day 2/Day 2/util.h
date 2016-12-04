#pragma once
#include <string>
#include <fstream>
#include<sstream>



int static aval = 0;

typedef std::string String;
typedef std::ifstream ifstream;

class Util
{
	public:
		
	static void readInput(String file, String &input, int &linesCount = aval)
	{
		ifstream inputFile(file);
		if (inputFile.is_open())
		{
			String line;
			while (getline(inputFile, line))
			{
				input.append(line + '\n');
				linesCount++;
			}
			inputFile.close();
		}
	}

	static void splitToCharArray(char *keyboard, char demiliter, std::string inputLine)
	{
		int j = 0;
		std::string currentCharacter;
		std::stringstream currentLine;
		currentLine.str(inputLine);

		while (std::getline(currentLine, currentCharacter, ' '))
		{
			keyboard[j] = currentCharacter[0];
			j++;
		}
	}



};
