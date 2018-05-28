﻿// binary_tree.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <windows.h>
#include "bTree.h"
#include <locale>
#include <string>
#include <locale.h>
#include "GUI/GUIUtility.h"
#include <set>


using namespace std;
/**
 * \brief Funkcja wyświetla tekst głównego menu
 * \return void
 */
void print_main_menu_txt()
{
	cout << "-----------------------------------------------------------\n";
	cout << "                     Binary Search Tree \n";
	cout << "                           Authors:\n";
	cout << "                     Dominik Kaliszewski\n";
	cout << "                             and\n";
	cout << "                     Karol Kolodziejczyk\n";
	cout << "                          Beta Tester:\n";
	cout << "                            Anna Huk\n";
	cout << "-----------------------------------------------------------\n";
	cout << "-                           MENU                          -\n";
	cout << "-----------------------------------------------------------\n";
	cout << "                 1. MULTIPLY ADD NUMBERS\n";
	cout << "                 2. ADD NUMBER\n";
	cout << "                 3. DELETE NUMBER\n";
	cout << "                 4. DESTROY TREE\n";
	cout << "                 5. SHOW TREE\n";
	cout << "                 6. TREE EMPTY CHECK\n";
	cout << "                 7. SEARCH NUMBER IN TREE\n";
	cout << "                 8. LOAD TEST DATA\n";
	cout << "                 0. EXIT\n";
	cout << "-----------------------------------------------------------\n";


		
}


/**
 * \brief Funkcja wyświetla główne menu z jego obsługą
 * \return void
 */
int print_menu()
{
	
	bTree *tree = new bTree;
	//tree->wait_for_close_event();
	int input;

	do
	{
		//ALLEGRO_EVENT ev;
		//ALLEGRO_TIMEOUT timeout;
		//al_init_timeout(&timeout, 0.06);

		//bool get_event = al_wait_for_event_until(tree->get_display()->event_queue, &ev, &timeout);

		//if (get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		//	break;
		//}
		
		print_main_menu_txt();
		cout << "CHOICE:";
		cin >> input;
		switch (input)
		{
		case 1:
			tree->add_multiply_num();
			break;
		case 2:
			tree->add_single_num();
			break;
		case 3:
			//if (!tree->empty())
			//{
			//	cout << "What number do you want to delete??\n";
			//	cin >> value;
			//	tree->remove(value);
			//	tree->clearDisplay();
			//	tree->print_Tree();
			//}
			//else
			//{
			//	setConsoleColor(GUI::MessageType::T_ERROR);
			//	cout << "TREE IS EMPTY!\n";
			//	setConsoleColor(GUI::MessageType::T_NORMAL);
			//	Sleep(1200);
			//}
			if(!tree->empty())
				tree->removeShow();
			else
			{
				setConsoleColor(GUI::MessageType::T_ERROR);
				cout << "TREE IS EMPTY! ADD SOME NUMBERS!";
				setConsoleColor(GUI::MessageType::T_NORMAL);
				Sleep(1200);
			}
			break;
		case 4:
			tree->destroy();
			tree->clearDisplay();
			//tree->removeDisplay();
			//tree = new bTree;
			break;
		case 5:
			if (tree->empty())
			{
				setConsoleColor(GUI::MessageType::T_ERROR);
				cout << "TREE IS EMPTY! ADD SOME NUMBERS!";
				setConsoleColor(GUI::MessageType::T_NORMAL);
				Sleep(1200);
			}
			else
			{
				tree->clearDisplay();
				tree->print_Tree();
			}
			break;
		case 6:
			if (tree->empty())
			{
				setConsoleColor(GUI::MessageType::T_ERROR);
				cout << "TREE IS EMPTY!\n";
				setConsoleColor(GUI::MessageType::T_NORMAL);
			}
				
			else
			{
				setConsoleColor(GUI::MessageType::T_INFO);
				cout << "TREE IS NOT EMPTY!\n";
				setConsoleColor(GUI::MessageType::T_NORMAL);
			}
			Sleep(1200);
			break;
		case 7:
			if(!tree->empty())
				tree->searchNum();
			else
			{
				setConsoleColor(GUI::MessageType::T_ERROR);
				cout << "TREE IS EMPTY! ADD SOME NUMBERS!";
				setConsoleColor(GUI::MessageType::T_NORMAL);
				Sleep(1200);
			}
			break;
		case 8:
			tree->load_test_data();
			break;
		case 0:

			break;

		}
		system("cls");
	} while (input != 0);


	return 1;
}

int main()
{
	
	if (GUI::LoadAllegro() == GUI::ERROR_CODE)
		return GUI::ERROR_CODE;
	print_menu();
		
	
	
	//
	//
	//const int searchVal = 3;
	//cout << endl;
	//if (tree->search(searchVal))
	//	cout << "Znaleziono wartosc " << searchVal << " w drzewie" << endl;
	//else
	//	cout << "Nie znaleziono wartosci " << searchVal << " w drzewie" << endl;

	getchar();
	return 0;
}

