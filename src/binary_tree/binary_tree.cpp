// binary_tree.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include "bTree.h"
#include <locale>
#include <string>
#include <locale.h>
#include "GUI/GUIUtility.h"



using namespace std;

int main()
{
	
	if (GUI::LoadAllegro() == GUI::ERROR_CODE)
		return GUI::ERROR_CODE;

	
	bTree *tree = new bTree;
	tree->insert(2);
	tree->insert(3);
	tree->insert(1);
	tree->insert(7);
	tree->insert(92);
	tree->insert(18);
	tree->inorder();
	const int searchVal = 3;
	cout << endl;
	if (tree->search(searchVal))
		cout << "Znaleziono wartosc " << searchVal << " w drzewie" << endl;
	else
		cout << "Nie znaleziono wartosci " << searchVal << " w drzewie" << endl;

	getchar();
	return 0;
}

