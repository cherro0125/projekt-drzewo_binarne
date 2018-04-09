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
	bool search(int val);
	void inorder();
	

private:
	node * root;
	void insert(int val, node *leaf);
	void destroy(node *leaf);
	bool search(int key, node *leaf);
	void inorder(node *root);
	
};

