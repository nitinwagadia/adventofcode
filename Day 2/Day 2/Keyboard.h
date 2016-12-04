#pragma once
#include "Position.h"
#include"util.h"

class KeyBoard
{
public:
	KeyBoard(std::string input);
	bool find(char n);
	void findCode(String &instructions, String &code);

private:
	char **keypad;
	Position *p;
	int row;

};