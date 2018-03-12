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
	if (root != NULL)
		insert(val, root);
	else
	{
		root = new node;
		root->key = val;
		root->Left = NULL;
		root->Right = NULL;
	}
}


void bTree::destroy()
{
	destroy(root);
}

node * bTree::search(int val)
{
	return search(val, root);
}



void bTree::insert(int val, node * leaf)
{
	if (val < leaf->key)
	{
		if (leaf->Left!= NULL)
			insert(val, leaf->Left);
		else
		{
			leaf->Left = new node;
			leaf->Left->key = val;
			leaf->Left->Left = NULL;    //Sets the left child of the child node to null
			leaf->Left->Right = NULL;   //Sets the right child of the child node to null
		}
	}
	else if (val >= leaf->key)
	{
		if (leaf->Right != NULL)
			insert(val, leaf->Right);
		else
		{
			leaf->Right = new node;
			leaf->Right->key = val;
			leaf->Right->Left = NULL;  //Sets the left child of the child node to null
			leaf->Right->Right = NULL; //Sets the right child of the child node to null
		}
	}
}

void bTree::destroy(node *leaf)
{
	if (leaf != NULL)
	{
		destroy(leaf->Left);
		destroy(leaf->Right);
		delete leaf;
	}
}

node * bTree::search(int val, node *leaf)
{
	if (leaf != NULL)
	{
		if (val == leaf->key)
			return leaf;
		if (val<leaf->key)
			return search(val, leaf->Left);
		else
			return search(val, leaf->Right);
	}
	else return NULL;
}



