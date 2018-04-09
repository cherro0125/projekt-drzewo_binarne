#include "bTree.h"
#include <string>


bTree::bTree()
{
	root = NULL;
	this->display = new GUI::GUIDisplay(640, 480);
}


bTree::~bTree()
{
	destroy(root);
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

void bTree::inorder(node *root)
{
	
	if (root != NULL)
	{
		inorder(root->Left);
		std::cout << root->key << " ";
		

		
		display->printText(std::to_string(root->key),this->dis+=50,50);
		inorder(root->Right);
	}
}


void bTree::destroy()
{
	destroy(root);
}

bool bTree::search(int val)
{
	return search(val, root);
}

void bTree::inorder()
{
	inorder(root);
}



void bTree::insert(int val, node * leaf)
{
	if (val < leaf->key)
	{
		if (leaf->Left != NULL)
			insert(val, leaf->Left);
		else
		{
			leaf->Left = new node;
			leaf->Left->key = val;
			leaf->Left->Left = NULL;
			leaf->Left->Right = NULL;
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
			leaf->Right->Left = NULL;
			leaf->Right->Right = NULL;
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

bool bTree::search(int val, node *leaf)
{
	if (leaf != NULL)
	{
		if (val == leaf->key)
			return true;
		if (val<leaf->key)
			return search(val, leaf->Left);
		else
			return search(val, leaf->Right);
	}
	else return false;
}

int node::get_val()
{
	if (this != NULL)
		return this->key;
	std::cout << "Wartosc nie wystepuje w drzewie!\n";
	return -1;
}
