// binary_tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "bTree.h"


using namespace std;

int main()
{
	bTree *tree = new bTree;
	tree->insert(2);
	tree->insert(3);
	cout << tree->search(5)->get_val();
    return 0;
}

