#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
/*
 *	ALLEGRO 
 *
 */
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>
/*
 *
 *	
 *
 */


namespace GUI
{
	 enum MessageType
	{
		T_ERROR,
		T_INFO,
		T_NORMAL
	};
	//HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	static const int ERROR_CODE = -1;
	int LoadAllegro();
	void setConsoleColor(MessageType t);
}
