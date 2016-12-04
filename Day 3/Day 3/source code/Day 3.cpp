// Day 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include <iostream>
typedef std::vector<int> Vector;
typedef std::string String;
typedef std::ifstream ifstream;


String trim(String& str)
{
	size_t first = str.find_first_not_of(' ');
	if (first == String::npos)
		return "";
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

void getNumberOfTraingles(String input, int &traingleCount, int line_reads)
{
	int total_reads=0;
	ifstream file(input);
	Vector vector;
	Vector *vectorArray = new Vector[line_reads];
	
	if (file.is_open())
	{
		String line;
		while (getline(file, line))
		{
			String currentNumber;
			std::stringstream mCurrentLine;
			mCurrentLine.str(trim(line));
			int vectorIndex = 0;
			while (std::getline(mCurrentLine, currentNumber, ' '))
			{
				if (!trim(currentNumber).empty())
				{
					if(line_reads > 1)
					{
						vectorArray[vectorIndex++].push_back(atoi(currentNumber.c_str()));
					}
					else
					{
						vectorArray[total_reads].push_back(atoi(currentNumber.c_str()));
					}
				}		
			}
			
			++total_reads;
			if (total_reads == line_reads)
			{
				for (int i = 0; i < line_reads; i++)
				{
					std::sort(vectorArray[i].rbegin(), vectorArray[i].rend());

					Vector::iterator it = vectorArray[i].begin();
					int largestNum = 0;
					while (it != vectorArray[i].end())
					{
						if (it == vectorArray[i].begin())
							largestNum = *it;
						else
							largestNum -= *it;

						++it;
					}
					if (largestNum < 0)
					{
						++traingleCount;
					}

					vectorArray[i].clear();
				}

				total_reads = 0;
			}
		}
	}
	else
	{
		std::cout << "File cannot be opened \n";
	}

}

int main(int argc,char** argv)
{
	int mCount=0;
	getNumberOfTraingles(argv[1], mCount,std::atoi(argv[2]));
	std::cout << "Number of Trianngle : " << mCount;
	std::getchar();
    return 0;
}

