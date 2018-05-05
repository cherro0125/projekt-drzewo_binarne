#pragma once
#include <iostream>
#include "GUI/GUIUtility.h"
class node {
public:
	int key;
	node *Left;
	node *Right;
	node *Parent;
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
	node *searchNode(int val);
	void inorder();
	void remove(int val);


private:
	node * root;
	GUI::GUIDisplay * display;
	int dis = 50;
	void insert(int val, node *leaf);
	void destroy(node *leaf);
	bool search(int val, node *leaf);
	node * searchNode(int val, node *leaf);
	void inorder(node *root);
	int minKey(node * root);
	int maxKey(node * root);
	node * minNode(node * root);
	node * maxNode(node * root);
	node * prevNode(node * x);
	node * nextNode(node * x);
	node * remove(node **root, node * x);

};

