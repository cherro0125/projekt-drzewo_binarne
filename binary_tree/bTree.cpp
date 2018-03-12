#include "stdafx.h"
#include "bTree.h"


bTree::bTree()
{
	root = NULL;
}


bTree::~bTree()
{
}

void bTree::insert(int val)
{
}

void bTree::insert(int val, node * leaf)
{
}

void bTree::destroy()
{
	destroy(root);
}

void bTree::destroy(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->Left);
		destroy_tree(leaf->Right);
		delete leaf;
	}
}



