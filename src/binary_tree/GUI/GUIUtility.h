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

 /** \defgroup gui GUI
 *  Tutaj znajdują się wszystkie funkcje czy klasy odnośnie GUI 
 * @{
 */
namespace GUI
{
	/**
	 * \brief Typ wyliczeniowy pod zmiane koloru konsoli (Typy wiadomości)
	 */
	 enum MessageType
	{
		T_ERROR,
		T_INFO,
		T_NORMAL
	};
	/**
	 * /brief Statyczny kod błędu
	 **/
	static const int ERROR_CODE = -1;
	/**
	 * \brief Funkcja ładująca zasoby biblioteki Allegro
	 * \return void
	 **/
	int LoadAllegro();
	/**
	 * \brief Funkcja zmieniająca kolor wysyłanej wiadomości na konsoli
	 * \param t MessageType - typ wiadomości
	 * \return void
	 **/
	void setConsoleColor(MessageType t);


	/*
	 *
	 *	DISPLAY
	 */
	/**
	 * \brief Klasa główna wyświetlającego okna Allegro
	 **/
	class GUIDisplay
	{
	private:
		/**
		 * /brief Wskaźnik na okno Allegro
		 **/
		ALLEGRO_DISPLAY * display;
		/**
		 * \brief Wskaźnik na czcionke do okna
		 **/
		ALLEGRO_FONT *GUIFont;
		/**
		 * \brief Wskaźnik na plik dźwiękowy
		 **/
		ALLEGRO_SAMPLE *sample;
		/**
		 * \brief Domyślna ścieżka do czcionki (Tryb Debug)
		 **/
		const std::string defaultFontPath = "../../res/fonts/SourceSansPro-Bold.ttf";
		/**
		 * /brief Domyślna ścieżka do czcionki(Tryb Release)
		 **/
		const std::string defaultRelaseFontPath = "SourceSansPro-Bold.ttf";
		/**
		 * /brief Rozmiar czcionki
		 **/
		int fontSize = 16; //będzie zmieniana wartość
		/**
		 * \brief Opóźnienie wyświetlania kolejnych elementów
		 **/
		const float delay = 0.0f;
		/**
		 * \brief Promień koła otaczającego węzeł
		 **/
		float circle_r = 20.0f;
		/**
		 *\brief Domyślna ścieżka do dźwięku (Tryb Debug)
		 **/
		const std::string defaultSongPath = "../../res/music/Default.wav";
		/**
		 * \brief Domyślna ścieżka do dźwięku (Tryb Release)
		 **/
		const std::string defaultRelaseSongPath = "Default.wav";
		/**
		 * \brief Funkcja ładująca domyślną czcionke
		 * \return void
		 **/
		void loadDefaultFont();

	public:
		/**
		 * \brief Wskaźnik na kolejke eventów allegro
		 */
		ALLEGRO_EVENT_QUEUE * event_queue = NULL;
		/**
		 * \brief Domyślny konstruktor klasy GUIDisplay
		 */
		GUIDisplay();
		/**
		 * \brief Kontruktor klasy GUIDisplay przyjmujący rozmiar
		 * \param width int - szerokość okna
		 * \param height int - wysokość okna
		 */
		GUIDisplay(int width, int height);
		/**
		 * \brief Destruktor klasy GUIDisplay
		 */
		~GUIDisplay();
		/**
		 * \brief Funkcja tworząca okno i ustawiająca odpowiednie flagi dla wygładzenia obrazu
		 * \return void
		 */
		void CreateDisplay(int width, int height);
		/**
		 * \brief Funkcja usuwająca okno
		 * \return void
		 */
		void removeDisplay();
		/**
		 * \brief Funkcja ustawiająca tytuł okna
		 * \return void
		 */
		void setTitle(std::string title);
		/**
		 * \brief Funkcja wyświetlająca tekst na oknie w podanej pozycji
		 * \param text String - tekst do wyświetlenia
		 * \param x float - współrzędna x położenia tekstu
		 * \param y float - współrzędna y położenia tekstu
		 * \return void
		 */
		void printText(std::string text, float x, float y);
		/**
		* \brief Funkcja wyświetlająca wektor na oknie w podanej pozycji
		* \param x1 float - współrzędna x położenia początku wektora
		* \param y1 float - współrzędna y położenia początku wektora
		* \param x2 float - współrzędna x położenia końca wektora
		* \param y2 float - współrzędna y położenia końca wektora
		* \return void
		*/
		void printVector(float x1,float y1, float x2, float y2);
		/**
		 * \brief Funkcja czyszcząca obraz na oknie
		 * \return void
		 */
		void clear();
		/**
		 * \brief Funkcja odtwarzająca muzyke w pętli
		 * \return void
		 */
		void playSong();
		/**
		* \brief Funkcja wyświetlająca okrąg na oknie w podanej pozycji
		* \param x float - współrzędna x położenia środka okręgu
		* \param y float - współrzędna y położenia środka okręgu
		* \return void
		*/
		void printCircle(float x, float y);
		/**
		 * \brief Funkcja zwracająca wielkość czcionki
		 * \return void
		 */
		int getFontSize();
		/**
		 * \brief Funkcja zwracająca promień okręgu ustalonego w klasie
		 * \return float
		 */
		float getR();

		
		
		
	};

	/**
	 *@}
	 */



	/*
	 *
	 *
	 *
	 */
}
