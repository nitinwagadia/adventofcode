#include "Keyboard.h"


KeyBoard::KeyBoard(std::string file) : p(NULL)
{
	int index = 0;
	std::stringstream fullInput;
	String currentLine,input;
	Util::readInput(file, input, row);

	keypad = new char*[row];
	
	fullInput.str(input);

	while (std::getline(fullInput, currentLine, '\n'))
	{
		keypad[index] = new char[row];
		Util::splitToCharArray(keypad[index], ' ', currentLine);
		index++;
	}
	/*for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
			std::cout << "--" << keypad[i][j];
		std::cout << "\n";
	}*/

}

/*char KeyBoard::getNumberFromPosition(Position * position)
{
	for (int i = 0; i < *position->getX();++i)
	return 0;
}*/


void KeyBoard::findCode(String &instructions,String &code)
{
	int index = -1;
	while (char c = instructions[++index])
	{
		switch (c)
		{
		case 'R':
		case 'r':
			p->moveRight(keypad);
			break;
		case 'L':
		case 'l':
			p->moveLeft(keypad);
			break;
		case 'D':
		case 'd':
			p->moveDown(keypad);
			break;
		case 'U':
		case 'u':
			p->moveUp(keypad);
			break;

		case '\n':
			std::stringstream ss;
			ss <<keypad[*p->getX()][*p->getY()];
			code.append(ss.str());
			break;
		}
	}
}

bool KeyBoard::find(char n)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < row; ++j)
		{
			if (keypad[i][j] == n)
			{
				p = new Position(i, j);
				p->setgridSize(row);
				return true;
			}

		}
	return false;
}
