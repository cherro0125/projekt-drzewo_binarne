// binary_tree.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include "bTree.h"
#include <locale>
#include <string>
#include <locale.h>
#include "GUI/GUIUtility.h"



using namespace std;

void print_main_menu_txt()
{
	cout << "MENU\n";
	cout << "1. MULTIPLY ADD NUMBERS\n";
	cout << "2. ADD NUMBER\n";
	cout << "3. DESTROY TREE\n";
	cout << "0. EXIT\n";
}

void print_menu()
{
	bTree *tree = new bTree;
	int input;
	do
	{
		print_main_menu_txt();
		cin >> input;
		switch (input)
		{
		case 1:
			tree->add_multiply_num();
			break;
		case 3:
			tree->destroy();
			tree->clearDisplay();
			tree->removeDisplay();
			tree = new bTree;
			break;
		case 0:

			break;

		}
		system("cls");
	} while (input != 0);
}

int main()
{
	
	if (GUI::LoadAllegro() == GUI::ERROR_CODE)
		return GUI::ERROR_CODE;
	print_menu();

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

