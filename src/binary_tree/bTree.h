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
	bTree(bool newDisplay = true);
	~bTree();
	void insert(int val);
	void destroy();
	bool search(int val);
	node *searchNode(int val);
	void inorder();
	void remove(int val);
	void clearDisplay();
	void removeDisplay();
	void add_multiply_num();
	void add_single_num();
	bool empty();
	bool searchShow(int val);
	void searchNum();
	void removeShow();
	void delete_node(int val);


private:
	node * root;
	GUI::GUIDisplay * display;
	int width = 1024;
	int height = 768;
	int dis = 40;
	void insert(int val, node *leaf);
	void destroy(node *leaf);
	bool search(int val, node *leaf);
	node * searchNode(int val, node *leaf);
	void inorder(node *root, float x, float y);
	int minKey(node * root);
	int maxKey(node * root);
	node * minNode(node * root);
	node * maxNode(node * root);
	node * prevNode(node * x);
	node * nextNode(node * x);
	node * remove(node **root, node * x);
	bool searchShow(int val, node *leaf, float x, float y);
	node *isolate_predecessor(node **root);
	void delete_node(node **root, int val);


	
	

};

