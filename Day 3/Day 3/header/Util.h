#pragma once
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include <iostream>
typedef std::vector<int> Vector;
typedef std::string String;
typedef std::ifstream ifstream;
class Util
{
public:
	static Vector vector;
	static String trim(String& str)
	{
		size_t first = str.find_first_not_of(' ');
		if (first == String::npos)
			return "";
		size_t last = str.find_last_not_of(' ');
		return str.substr(first, (last - first + 1));
	}


	static void readInput(String &input, int &traingleCount)
	{
		ifstream file(input);
		if (file.is_open())
		{
			String line;
			while (getline(file, line))
			{
				String currentNumber;
				std::stringstream mCurrentLine;
				mCurrentLine.str(Util::trim(line));
				while (std::getline(mCurrentLine, currentNumber, ' '))
				{  
					if(!Util::trim(currentNumber).empty())
					vector.push_back(atoi(currentNumber.c_str()));

					std::cout << "," << currentNumber;
				}
				std::sort(vector.rbegin(), vector.rend());

				Vector::iterator it = vector.begin();
				int largestNum = 0;
				while (it != vector.end())
				{
					if (it == vector.begin())
					{
						largestNum = *it;
						std::cout << "Largest Number " << largestNum;
					}
						
					else
						largestNum -= *it;

					++it;
				}

				if (largestNum < 0)
				{
					++traingleCount;
					std::cout << "difference " << largestNum << "\n";
				}
					
				vector.clear();
				std::cout << "\n";
			}
		}
		else
		{
			std::cout << "File cannot be opened \n";
		}
	
	}


};