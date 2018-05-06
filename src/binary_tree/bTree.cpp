#include "bTree.h"
#include <string>


bTree::bTree()
{
	root = NULL;
	this->display = new GUI::GUIDisplay(this->width, this->height);
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
		root->Parent = NULL;
	}
}

void bTree::inorder(node *root, float x, float y)
{
	
	if (root != NULL)
	{
		display->printText(std::to_string(root->key), x,y);
		y += 20;
		if(root->Left)
		{
			x -= 25;
			
			display->printText("/", x , y);
		}
			
		if(root->Right)
		{
			x += 50;
			//y += 20;
			display->printText("\\", x, y);
		}
			
		std::cout << root->key << " ";
		inorder(root->Left,x-=60,y+40);
		inorder(root->Right,x+=75,y+40);

		//inorder(root->Left);
		//std::cout << root->key << " ";
		//display->printText(std::to_string(root->key),this->dis+=50,50);
		//inorder(root->Right);
	}
}

int bTree::minKey(node * root)
{
	node * x = root;

	while ((x->Left)) x = x->Left;

	return x->key;
}

int bTree::maxKey(node * root)
{
	node * x = root;

	while ((x->Right)) x = x->Right;

	return x->key;
}

node * bTree::minNode(node * root)
{
	node * x = root;

	while ((x->Left)) x = x->Left;

	return x;
}

node * bTree::maxNode(node * root)
{
	node * x = root;

	while ((x->Right)) x = x->Right;

	return x;
}

node * bTree::prevNode(node * x)
{
	if (x->Left) return maxNode(x->Left);

	node * y;

	do
	{
		y = x;
		x = x->Parent;
	} while (x && (x->Right != y));

	return x;
}

node * bTree::nextNode(node * x)
{
	if (x->Right) return minNode(x->Right);

	node * y;

	do
	{
		y = x;
		x = x->Parent;
	} while (x && (x->Left != y));

	return x;
}

node * bTree::remove(node ** root, node * x)
{
	
	if(x)
	{	
		node * y = x->Parent, *z;
		if ((x->Left) && (x->Right))
		{
			z = (rand() % 2) ? remove(root, prevNode(x)) : remove(root, nextNode(x));
			z->Left = x->Left;   if (z->Left)  z->Left->Parent = z;
			z->Right = x->Right; if (z->Right) z->Right->Parent = z;
		}
		else z = (x->Left) ? x->Left : x->Right;

		if (z) z->Parent = y;

		if (!y) *root = z;
		else if (y->Left == x) y->Left = z; else y->Right = z;
	}

	

	return x;
}


void bTree::destroy()
{
	destroy(root);
}

bool bTree::search(int val)
{
	return search(val, root);
}

node * bTree::searchNode(int val)
{
	return searchNode(val, root);
}

void bTree::inorder()
{
	inorder(root,this->width/2,0);
}

void bTree::remove(int val)
{
	node *s = searchNode(val);
	remove(&root, s);
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
			leaf->Left->Parent = leaf;
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
			leaf->Right->Parent = leaf;
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

node * bTree::searchNode(int val, node * leaf)
{
	if (leaf != NULL)
	{
		if (val == leaf->key)
			return leaf;
		if (val<leaf->key)
			return searchNode(val, leaf->Left);
		else
			return searchNode(val, leaf->Right);
	}
	else return NULL;
}



int node::get_val()
{
	if (this != NULL)
		return this->key;
	std::cout << "Wartosc nie wystepuje w drzewie!\n";
	return -1;
}
