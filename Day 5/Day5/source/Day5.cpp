// Day5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include<sstream>
#include<map>
#include "MD5.h"
#include "Day5.h"

typedef std::string String;
typedef std::map<int,char> Map;

struct KeyCode
{
	bool visited;
	char code;
};

String findCodePart1(String &base)
{
	bool flag = true;
	String key="";
	int counter = 0;
	while (key.length() != 8)
	{

		String hash = md5(base + std::to_string(counter));
		//std::cout << "HASH OF " << base << std::to_string(counter) << " is " << hash << std::endl;
		if (strncmp(hash.c_str(), "00000", 5) == 0)
		{
			std::cout << "Hash is  : " << hash <<" and inserting "<<hash[5]<<std::endl;
			key += hash[5];
			//key.append(h1ash[5]);
			std::cout << "Key is : " << key << std::endl;
		}

		++counter;
	}

	return key;
}

String findCodePart2(String &base)
{
	Map codes;
	String key;
	int counter = 0, keysFound = 0;
	while (keysFound!=8)
	{
		String hash = md5(base + std::to_string(counter));
	
		if (strncmp(hash.c_str(), "00000", 5) == 0)
		{
			int position = hash[5] - '0';
			if (position < 8)
			{
				if (codes.find(position) == codes.end())
				{
					codes[position] = hash[6];
					++keysFound;
					std::cout << "Pass Code : ";
					for (int i = 0; i <8; ++i)
					{
						if (codes.find(i) == codes.end())
						{
							std::cout << "_";
						}
						else
							std::cout << codes[i];
					}
					std::cout << "\n";
				}

			}

		}

		++counter;
	}

	for (int i = 0; i <8; ++i)
	{
		key += codes[i];
	}
	return key;
}

int main(int argc,char** argv)
{
	String baseSeed = argv[1];
	std::cout <<"Code for Door 1 : "<< findCodePart1(baseSeed) <<std::endl;
	std::cout << "Code for Door 2 : " << findCodePart2(baseSeed) << std::endl;

	std::getchar();
    return 0;
}

