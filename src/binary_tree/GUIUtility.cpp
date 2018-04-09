#include "GUIUtility.h"

int GUI::LoadAllegro()
{
	
	if(!al_init())
	{
	
		
		setConsoleColor(MessageType::T_ERROR);
		std::cout << "[Error]Initialization Allegro Liblary Faild!" << std::endl;
		return -1;
	}
	else
	{
		setConsoleColor(MessageType::T_INFO);
		std::cout << "[INFO]Initialization Allegro Liblary Sucessfull" << std::endl;
	}






	
	setConsoleColor(MessageType::T_NORMAL);
	return 1;
}

void GUI::setConsoleColor(MessageType t)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	switch(t)
	{
	case MessageType::T_ERROR:
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | 0);
		break;
	case MessageType::T_INFO:
		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | 0);
		break;
	case MessageType::T_NORMAL:
		SetConsoleTextAttribute(hStdOut, (1 | 2 | 4) | 0);
		break;
	default:
		SetConsoleTextAttribute(hStdOut, (1 | 2 | 4) | 0);

	}
}
