#pragma once

struct node {
	int key;
	node *Left;
	node *Right;
};


class bTree
{
public:
	bTree();
	~bTree();
	void insert(int val);
	void destroy()

private:
	node * root;
	void insert(int val, node *leaf);
	void destroy(node *leaf)
};

