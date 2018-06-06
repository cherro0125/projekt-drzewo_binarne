#pragma once
#include <iostream>
#include "GUI/GUIUtility.h"
/** \defgroup typybazowe Typy bazowe drzewa
*  Tutaj znajdują się wszystkie typy bazowe dla drzewa binarnego
* @{
*/

/**
 * \brief Klasa bazowa węzła w drzewie
 **/
class node {
public:
	/**
	 * \brief Wartość(klucz) węzła 
	 **/
	int key;
	/**
	 * \brief Wskaźnik na lewego potomka
	 **/
	node *Left;
	/**
	 * \brief Wskaźnik na prawego potomka
	 **/
	node *Right;
	/**
	 * \brief Wskaźnik na rodzica
	 **/
	node *Parent;


};

/**
 * @}
 **/

 /** \defgroup klasadrzewo Klasa drzewa
 *  Tutaj znajduje się wszystko związane z klasą drzewa
 * @{
 */

class bTree
{
public:
	/**
	 * \brief Konstruktor drzewa binarnego
	 **/
	bTree(bool newDisplay = true);
	/**
	 * \brief Destruktor drzewa binarnego
	 **/
	~bTree();
	/**
	 * \brief Metoda dodająca element o podanej wartości do drzewa (Interfejs publiczny)
	 * \param val int - wartość nowego węzła
	 * \return void
	 **/
	void insert(int val);
	/**
	 * \brief Metoda usuwająca wszystkie węzły z drzewa binarnego (pozostawia NULL na korzeniu) (Interfejs)
	 * \return void
	 **/
	void destroy();
	/**
	 * \brief Metoda szukająca węzła o danej wartości w drzewie (Interfejs publiczny)
	 * \param val int - wartość szukanego węzła
	 * \return bool
	 **/
	bool search(int val);
	/**
	* \brief Metoda szukająca węzła o danej wartości w drzewie (Interfejs publiczny)
	* \param val int - wartość szukanego węzła
	* \return node *
	**/
	node *searchNode(int val);
	/**
	 * \brief Metoda drukująca reprezentacje graficzną drzewa binarnego (Interfejs publiczny)
	 * \return void
	 **/
	void print_Tree();
	/** 
	* \brief Metoda czyszcząca obraz na oknie (Łącznik z faktyczną metodą okna) (Interfejs publiczny)
	* \return void
	**/
	void clearDisplay();
	/**
	* \brief Metoda usuwająca okno (Łącznik z faktyczną metodą okna) (Interfejs publiczny)
	* \return void
	**/
	void removeDisplay();
	/**
	 * \brief Metoda pomocnicza pozwalająca użytkownikowi wprowadzić wiele węzłów o określonych wartościach do drzewa
	 * \return void
	 **/
	void add_multiply_num();
	/**
	* \brief Metoda pomocnicza pozwalająca użytkownikowi wprowadzić jeden węzeł o określonej wartości do drzewa
	* \return void
	**/
	void add_single_num();
	/**
	 * \brief Metoda sprawdzająca czy drzewo jest puste
	 * \return bool
	 **/
	bool empty();
	/**
	 * \brief Metoda wyświetlająca graficznie reprezentacje poszukiwań węzła o podanej wartości w drzewie (Interfejs publiczny)
	 * \param val int - wartość poszukiwanego węzła
	 **/
	bool searchShow(int val);
	/**
	* \brief Metoda pomocznicza pozwalająca wprowadzić użytkownikowi wartość szukanego węzła i wyświetlić graficznie reprezentacje poszukiwań (ścieżke przez inne węzły)
	* 
	* \return bool
	**/
	void searchNum();
	/**
	 * \brief Metoda pomocnicza pozwalająca wprowadzić użytkownikowi wartość węzła do usunięcia i wyświetlić drzewo po usunięciu owego węzła
	 * \return void
	 **/
	void removeShow();
	/**
	 * \brief Metoda usuwająca węzeł o podanej wartości z drzewa (Interfejs publiczny)
	 * \return void
	 **/
	void delete_node(int val);
	/**
	 * \brief Metoda pomocznicza ładująca węzły o przykładowych wartościach do drzewa
	 * \return void
	 **/
	void load_test_data();
	/**
	 * \brief Metoda zwracająca wskaźnik na obiekt okna (NIE OKNA Z ALLEGRO!)
	 * \return GUI::GUIDisplay * 
	 **/
	GUI::GUIDisplay * get_display();
	


private:
	/**
	 * \brief Wskaźnik na korzeń drzewa
	 **/
	node * root;
	/**
	 * \brief Wskaźnik na obiekt okna
	 **/
	GUI::GUIDisplay * display;
	/**
	 * \brief Szerokośc okna
	 **/
	int width = 1024;
	/**
	 * \brief Wysokość okna
	 **/
	int height = 768;
	/**
	 * \brief Składowa odległości między węzłami w reprezentacji graficznej
	 **/
	int dis = 40;
	/**
	* \brief Metoda rekurencyjna dodająca element o podanej wartości do drzewa (Metoda prywatna)
	* \param val int - wartość nowego węzła
	* \param leaf node* - wskaźnik na węzeł (wyjściowo wskaźnik na korzeń)
	* \return void
	**/
	void insert(int val, node *leaf);
	/**
	* \brief Metoda rekurencyjna usuwająca wszystkie węzły z drzewa binarnego (pozostawia NULL na korzeniu)  (Metoda prywatna)
	* \param leaf node* - wskaźnik na węzeł (wyjściowo wskaźnik na korzeń)
	* \return void
	**/
	void destroy(node *leaf);
	/**
	* \brief Metoda rekurencyjna szukająca węzła o danej wartości w drzewie (Metoda prywatna)
	* \param val int - wartość szukanego węzła
	* \param leaf node* - wskaźnik na węzeł (wyjściowo wskaźnik na korzeń)
	* \return bool
	**/
	bool search(int val, node *leaf);
	/**
	* \brief Metoda rekurencyjna szukająca węzła o danej wartości w drzewie (Metoda prywatna)
	* \param val int - wartość szukanego węzła
	* \param leaf node* - wskaźnik na węzeł (wyjściowo wskaźnik na korzeń)
	* \return node *
	**/
	node * searchNode(int val, node *leaf);
	/**
	* \brief Metoda drukująca reprezentacje graficzną drzewa binarnego (Metoda prywatna)
	* \param root node * - wskaźnik na korzeń drzewa
	* \param x float - współrzędna x wyświetlania
	* \param y float - współrzędna y wyświetlania
	* \return void
	**/
	void print_Tree(node *root, float x, float y);
	/**
	* \brief Metoda rekurencyjna wyświetlająca graficznie reprezentacje poszukiwań węzła o podanej wartości w drzewie (Metoda prywatna)
	* \param val int - wartość poszukiwanego węzła
	* \param x float - współrzędna x wyświetlania
	* \param y float - współrzędna y wyświetlania
	**/
	bool searchShow(int val, node *leaf, float x, float y);
	/**
	* \brief Metoda izolująca poprzednika w drzewie w celu późniejszego usunięcia 
	* \param root node ** - wskaźnik na wskaźnik korzeia drzewa
	* \return node *
	*/
	node *isolate_predecessor(node **root);
	/**
	* \brief Metoda iteracyjna usuwająca węzeł o podanej wartości z drzewa (Metoda prywatna)
	* \param root node** - podwójny wskaźnik na korzeń
	* \param val int - wartość węzła do usunięcia z drzewa
	* \return void
	**/
	void delete_node(node **root, int val);
	


	
	

};


/**
* @}
**/

