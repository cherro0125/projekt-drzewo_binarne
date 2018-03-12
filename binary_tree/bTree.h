#pragma once
#include <iostream>
class node {
public:
	int key;
	node *Left;
	node *Right;
	int get_val();
	
};


class bTree 
{
public:
	bTree();
	~bTree();
	void insert(int val);
	void destroy();
	node *search(int val);
	

private:
	node * root;
	void insert(int val, node *leaf);
	void destroy(node *leaf);
	node *search(int key, node *leaf);

	
};

