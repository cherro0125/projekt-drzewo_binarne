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


	/*
	 *
	 *	DISPLAY
	 */

	class GUIDisplay
	{
	private:
		ALLEGRO_DISPLAY * display;
		ALLEGRO_FONT *GUIFont;
		const std::string defaultFontPath = "../../res/fonts/SourceSansPro-Bold.ttf";
		const int fontSize = 16;
		void loadDefaultFont();

	public:
		GUIDisplay();
		GUIDisplay(int width, int height);
		~GUIDisplay();
		void CreateDisplay(int width, int height);
		void setTitle(std::string title);
		void printText(std::string text, float x, float y);
		void printVector(float x1,float y1, float x2, float y2);
	
		
	};



	/*
	 *
	 *
	 *
	 */
}