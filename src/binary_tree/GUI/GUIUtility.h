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
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
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
		ALLEGRO_SAMPLE *sample;
		const std::string defaultFontPath = "../../res/fonts/SourceSansPro-Bold.ttf";
		const std::string defaultRelaseFontPath = "SourceSansPro-Bold.ttf";
		int fontSize = 16; //będzie zmieniana wartość
		const float delay = 0.0f;
		float circle_r = 20.0f;
		const std::string defaultSongPath = "../../res/music/Default.wav";
		const std::string defaultRelaseSongPath = "Default.wav";

		void loadDefaultFont();

	public:
		GUIDisplay();
		GUIDisplay(int width, int height);
		~GUIDisplay();
		void CreateDisplay(int width, int height);
		void removeDisplay();
		void setTitle(std::string title);
		void printText(std::string text, float x, float y);
		void printVector(float x1,float y1, float x2, float y2);
		void clear();
		void playSong();
		void printCircle(float x, float y);
		int getFontSize();
		float getR();
		int wait_for_close();
		
	};



	/*
	 *
	 *
	 *
	 */
}
