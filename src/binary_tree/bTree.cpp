#include "bTree.h"
#include <string>



bTree::bTree(bool newDisplay)
{
	root = NULL;
	if (newDisplay)
		this->display = new GUI::GUIDisplay(this->width, this->height);
		

}


bTree::~bTree()
{
	destroy(root);
	delete(root);
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

void bTree::print_Tree(node *root, float x, float y)
{
	
	if (root != NULL)
	{
		display->printCircle(x, y);
		display->printText(std::to_string(root->key), x,y-(display->getFontSize()/2));
		
		
		y += 20;
		//TODO naprawić zlewanie sie momentami elementow prawych i lewych
		if(root->Left)
		{
			//x -= 25;
			
			//display->printText("/", x , y);
			//display->printVector(x  + (display->getFontSize() / 2), y, x, y+20 );
			//display->printVector(x +40 - display->getR()*2 , y-40 + display->getR()*2, x-40, y+40-display->getR());
			display->printVector(x + this->dis - display->getR()*3 , y - this->dis + display->getR() , x - this->dis, y + this->dis - display->getR());
		}
			
		if(root->Right)
		{
			//x += 50;
			//y += 20;
			//display->printText("\\", x, y);
			//display->printVector(x  - (display->getFontSize() / 2), y, x, y+20);
			display->printVector(x +this->dis - display->getR(), y- this->dis +display->getR(), x+ this->dis, y+ this->dis -display->getR());
		}
			
		//std::cout << root->key << " ";
		print_Tree(root->Left,x- this->dis,y+ this->dis);
		print_Tree(root->Right,x+ this->dis,y+ this->dis);

		//print_Tree(root->Left);
		//std::cout << root->key << " ";
		//display->printText(std::to_string(root->key),this->dis+=50,50);
		//print_Tree(root->Right);
	}
}











//TODO Wektory do poprawki 
bool bTree::searchShow(int val, node * leaf,float x,float y) 
{

	//if (root != NULL)
	//{
	//	display->printCircle(x, y);
	//	display->printText(std::to_string(root->key), x, y - (display->getFontSize() / 2));


	//	y += 20;

	//	if (root->Left)
	//	{
	//		//x -= 25;

	//		//display->printText("/", x , y);
	//		//display->printVector(x  + (display->getFontSize() / 2), y, x, y+20 );
	//		//display->printVector(x +40 - display->getR()*2 , y-40 + display->getR()*2, x-40, y+40-display->getR());
	//		display->printVector(x + this->dis - display->getR() * 3, y - this->dis + display->getR(), x - this->dis, y + this->dis - display->getR());
	//	}

	//	if (root->Right)
	//	{
	//		//x += 50;
	//		//y += 20;
	//		//display->printText("\\", x, y);
	//		//display->printVector(x  - (display->getFontSize() / 2), y, x, y+20);
	//		display->printVector(x + this->dis - display->getR(), y - this->dis + display->getR(), x + this->dis, y + this->dis - display->getR());
	//	}

	//	//std::cout << root->key << " ";
	//	print_Tree(root->Left, x - this->dis, y + this->dis);
	//	print_Tree(root->Right, x + this->dis, y + this->dis);

	//	//print_Tree(root->Left);
	//	//std::cout << root->key << " ";
	//	//display->printText(std::to_string(root->key),this->dis+=50,50);
	//	//print_Tree(root->Right);
	//}
	if (leaf != NULL)
	{
		if (val == leaf->key)
		{
			display->printCircle(x, y);
			display->printText(std::to_string(leaf->key), x, y - (display->getFontSize() / 2));
			//y += 20;
			return true;
		}
		display->printCircle(x, y);
		
		display->printText(std::to_string(leaf->key), x, y - (display->getFontSize() / 2));
		y += 20;
			
		if (val<leaf->key)
		{
			//x -= 25;

			//display->printText("/", x , y);
			//display->printVector(x + 25, y, x, y + 20);
			display->printVector(x + this->dis - display->getR() * 2.95, y - this->dis + display->getR(), x - this->dis, y + this->dis - display->getR());
			//display->printText(std::to_string(leaf->Left->key), x, y);
			return searchShow(val, leaf->Left,x - this->dis, y + this->dis);
		}
		else
		{
			//x += 50;
			//y += 20;
			//display->printText("\\", x, y);
			//display->printVector(x - 25, y, x, y + 20);
			//display->printText(std::to_string(leaf->Right->key), x, y);
			display->printVector(x + this->dis - display->getR()*1.07, y - this->dis + display->getR(), x + this->dis, y + this->dis - display->getR());
			return searchShow(val, leaf->Right, x + this->dis, y + this->dis);
		}
	
	}
	else return false;
}

node * bTree::isolate_predecessor(node ** root)
{
	while (*root && (*root)->Right)
		root = &(*root)->Right;
	node *predecessor = *root;
	if (*root)
		*root = (*root)->Left;
	return predecessor;
}

void bTree::delete_node(node ** root, int val)
{
	while (*root && (*root)->key != val) {
		if ((*root)->key>val)
			root = &(*root)->Left;
		if ((*root)->key<val)
			root = &(*root)->Right;
	}
	if (*root) {
		node *node = *root;
		if (!node->Left)
			*root = (*root)->Right;
		else if (!node->Right)
			*root = (*root)->Left;
		else {
			node = isolate_predecessor(&(*root)->Left);
			(*root)->key = node->key;
			
		}
		delete(node);
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

node * bTree::searchNode(int val)
{
	return searchNode(val, root);
}

void bTree::print_Tree()
{
	print_Tree(root,this->width/2,30);
}



void bTree::clearDisplay()
{
	this->display->clear();
}

void bTree::removeDisplay()
{
	this->display->removeDisplay();
}

void bTree::add_multiply_num()
{
	system("cls");
	int c, num;
	std::cout << "TYPE HOW MANY NUMBERS:" << std::endl;
	std::cin >> c;
	while (std::cin.fail())
	{
		system("cls");
		setConsoleColor(GUI::MessageType::T_ERROR);
		std::cout << "[ERROR] TYPE INTEGER NUMBER!\n";
		setConsoleColor(GUI::MessageType::T_NORMAL);
		std::cout << "TYPE HOW MANY NUMBERS:" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> c;
	}
	for (int i = 1; i <= c; i++)
	{
		std::cout << "NUM" << "[" << i << "]:";
		std::cin >> num;
		while (std::cin.fail())
		{
			system("cls");
			setConsoleColor(GUI::MessageType::T_ERROR);
			std::cout << "[ERROR] TYPE INTEGER NUMBER!\n";
			setConsoleColor(GUI::MessageType::T_NORMAL);
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "NUM" << "[" << i << "]:";
			std::cin >> num;
		}
		std::cout << std::endl;
		system("cls");
		this->clearDisplay();
		this->insert(num);
		this->print_Tree();

	}
}

void bTree::add_single_num()
{
	system("cls");
	int  num;
	std::cout << "NUM:" << std::endl;
	std::cin >> num;
	while (std::cin.fail())
	{
		system("cls");
		setConsoleColor(GUI::MessageType::T_ERROR);
		std::cout << "[ERROR] TYPE INTEGER NUMBER!\n";
		setConsoleColor(GUI::MessageType::T_NORMAL);
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "NUM:";
		std::cin >> num;
	}
	std::cout << std::endl;
	system("cls");
	this->clearDisplay();
	this->insert(num);
	this->print_Tree();
}


bool bTree::empty()
{
	if (root)
		return false;
	return true;
}



bool bTree::searchShow(int val)
{
	return searchShow(val, root,this->width/2,this->height/2);
}

void bTree::searchNum()
{
	system("cls");
	int  num;
	std::cout << "SEARCH NUM:";
	std::cin >> num;
	while (std::cin.fail())
	{
		system("cls");
		setConsoleColor(GUI::MessageType::T_ERROR);
		std::cout << "[ERROR] TYPE INTEGER NUMBER!\n";
		setConsoleColor(GUI::MessageType::T_NORMAL);
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "NUM:";
		std::cin >> num;
	}
	std::cout << std::endl;
	system("cls");
	this->clearDisplay();
	this->print_Tree();
	//this->insert(num);
	this->searchShow(num);
}

void bTree::removeShow()
{
	system("cls");
	int  num;
	std::cout << "NUM TO DELETE:";
	std::cin >> num;
	while (std::cin.fail())
	{
		system("cls");
		setConsoleColor(GUI::MessageType::T_ERROR);
		std::cout << "[ERROR] TYPE INTEGER NUMBER!\n";
		setConsoleColor(GUI::MessageType::T_NORMAL);
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "NUM TO DELETE:";
		std::cin >> num;
	}
	std::cout << std::endl;
	system("cls");
	//this->remove(num);
	this->delete_node(num);
	this->clearDisplay();
	this->print_Tree();
}

void bTree::delete_node(int val)
{
	if(searchNode(val)!=NULL)
		delete_node(&root, val);
	else
	{
		system("cls");
		setConsoleColor(GUI::MessageType::T_ERROR);
		std::cout << "[ERROR] Node with this value not found!\n";
		setConsoleColor(GUI::MessageType::T_NORMAL);
		Sleep(1000);
	}

}


void bTree::load_test_data()
{
	this->destroy();
	this->clearDisplay();
	this->insert(3);
	this->insert(2);
	this->insert(55);
	this->insert(-5);
	this->insert(999);
	this->insert(66);
	this->insert(-17);
	this->insert(-4);
	this->insert(99);
	this->insert(-20);
	this->insert(-6);
	this->insert(88);
	this->insert(112);
	this->insert(-18);


	this->print_Tree();

}

GUI::GUIDisplay * bTree::get_display()
{
	return this->display;
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
		if (leaf != root)
			delete leaf;
		else
			root = NULL;
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




