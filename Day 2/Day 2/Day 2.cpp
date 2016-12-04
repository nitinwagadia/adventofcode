// Day 2.cpp : Defines the entry point for the console application.
//

#include"Keyboard.h"
#include "Day 2.h"

int main(int argc, char** argv)
{
	int rows = 0, columns = 0;
	String instructions,keyboardLayout,code;
	Util::readInput(argv[1], instructions);
	KeyBoard keyboard(argv[2]);
	if (keyboard.find(argv[3][0]))
	{
		keyboard.findCode(instructions, code);
	};

	std::cout << "Code is : " << code;
	
	std::getchar();
    return 0;
}

