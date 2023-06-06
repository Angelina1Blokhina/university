using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef enum { BLACK, RED } nodeColor;

struct Node { // C++

	int key;

	Node* left;

	Node* right;

	Node* parent;

	char color;

};
struct Node* grandparent(struct Node* n)
{
	if ((n != NULL) && (n->parent != NULL))
		return n->parent->parent;
	else
		return NULL;
}

struct Node* uncle(struct Node* n)
{
	struct Node* g = grandparent(n);
	if (g == NULL)
		return NULL; // No grandparent means no uncle
	if (n->parent == g->left)
		return g->right;
	else
		return g->left;
}
void rotate_left(struct Node* n)
{
	struct Node* pivot = n->right;

	pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
	if (n->parent != NULL) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = n;

	n->parent = pivot;
	pivot->left = n;
}

void rotate_right(struct Node * n)
{
	struct Node* pivot = n->left;

	pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
	if (n->parent != NULL) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = n;

	n->parent = pivot;
	pivot->right = n;
}
void insert_case5(struct Node* n)
{
	struct Node* g = grandparent(n);

	n->parent->color = BLACK;
	g->color = RED;
	if ((n == n->parent->left) && (n->parent == g->left)) {
		rotate_right(g);
	}
	else { /* (n == n->parent->right) && (n->parent == g->right) */
		rotate_left(g);
	}
}

void insert_case4(struct Node* n)
{
	struct Node* g = grandparent(n);

	if ((n == n->parent->right) && (n->parent == g->left)) {
		rotate_left(n->parent);

		/*
		 * rotate_left может быть выполнен следующим образом, учитывая что уже есть *g =  grandparent(n)
		 *
		 * struct node *saved_p=g->left, *saved_left_n=n->left;
		 * g->left=n;
		 * n->left=saved_p;
		 * saved_p->right=saved_left_n;
		 *
		 */

		n = n->left;
	}
	else if ((n == n->parent->left) && (n->parent == g->right)) {
		rotate_right(n->parent);

		/*
		 * rotate_right может быть выполнен следующим образом, учитывая что уже есть *g =  grandparent(n)
		 *
		 * struct node *saved_p=g->right, *saved_right_n=n->right;
		 * g->right=n;
		 * n->right=saved_p;
		 * saved_p->left=saved_right_n;
		 *
		 */

		n = n->right;
	}
	insert_case5(n);
}
void insert_case1(struct Node* n);
void insert_case3(struct Node* n)
{
	struct Node* u = uncle(n), * g;

	if ((u != NULL) && (u->color == RED)) {
		// && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
		n->parent->color = BLACK;
		u->color = BLACK;
		g = grandparent(n);
		g->color = RED;
		//insert_case1(g, parent, left, right);
	}
	else {
		insert_case4(n);
	}
}

void insert_case2(struct Node* n)
{
	if (n->parent->color == BLACK)
		return; 
	else
		insert_case3(n);
}
void insert_case1(struct Node* n)
{
	if (n->parent == NULL)
		n->color = BLACK;
		
	else
		insert_case2(n);
}

void Insert_Fixup(Node** n, Node* New_Node)
{
	Node* Current = New_Node;
	// Проверка свойств дерева
	while (Current != *(n) && Current->parent->color == RED) {
		// если есть нарушение
		if (Current->parent == Current->parent->parent->left)
		{
			Node* ptr = Current->parent->parent->right;
			if (ptr != NULL)
			{

				if (ptr->color == RED) {
					Current->parent->color = BLACK;
					ptr->color = BLACK;
					Current->parent->parent->color = RED;
					Current = Current->parent->parent;
				}

			}
			else
			{
				if (Current == Current->parent->right) {
					// сделать Current левым потомком
					Current = Current->parent;
					rotate_left(Current);
				}
				// перекрасить и повернуть
				Current->parent->color = BLACK;
				Current->parent->parent->color = RED;
				rotate_right(Current->parent->parent);
			}
			
		}
		else 
		{
			Node* ptr = Current->parent->parent->left;
			if (ptr != NULL)
			{

				if (ptr->color == RED) {
					Current->parent->color = BLACK;
					ptr->color = BLACK;
					Current->parent->parent->color = RED;
					Current = Current->parent->parent;
				}
				
			}
			else
			{
				if (Current == Current->parent->left) {
					Current = Current->parent;
					rotate_right(Current);
				}
				Current->parent->color = BLACK;
				Current->parent->parent->color = RED;
				rotate_left(Current->parent->parent);
			}
		}
	}
	(*n)->color = BLACK;
}

void insert(Node** n, int Data) 
{
	Node** Current, * Parent, * New_Node;
	Current = n;
	Parent = NULL;
	if (Current == NULL)
	{	
		(*Current)->key = Data;
	}
	else
	{
		// Поиск местоположения
		while (Current != NULL) {
			Parent = (*Current);
			Current = Data < (*Current)->key ? &((*Current)->left) : &((*Current)->right);
		}
		(*Current)->parent = Parent;
		// Создание нового узла
		New_Node = new Node();
		New_Node->key = Data;
		New_Node->parent = Parent;
		New_Node->left = NULL;
		New_Node->right = NULL;
		New_Node->color = RED;
		// Вставка элемента в дерево
		if (Parent != NULL) {
			if (Data < Parent->key) Parent->left = New_Node;
			else Parent->right = New_Node;
		}
		else (*Current) = New_Node;
		Insert_Fixup(n, New_Node);

	}
	
	
	
}
void replace_node(Node* n, Node* child) {
	child->parent = n->parent;
	if (n == n->parent->left) {
		n->parent->left = child;
	}
	else {
		n->parent->right = child;
	}
}

void delete_one_child(Node** T, Node* n)
{
	/*
	 * Условие: n имеет не более одного ненулевого потомка.
	 */
	Node* child = NULL;
	if (n->right != NULL & n->left == NULL)
		child = n->right;
	else
	{
		if (n->right == NULL & n->left != NULL)
			child = n->left;
	}

	replace_node(n, child);
	if (n->color == BLACK) {
		if (child->color == RED)
			child->color = BLACK;
		else
			delete_case1(T, child);
	}
	delete(n);
}
void delete_case6(Node** T, Node* n)
{
	Node* s = sibling(n);

	s->color = n->parent->color;
	n->parent->color = BLACK;

	if (n == n->parent->left) {
		s->right->color = BLACK;
		TREE_ROTATE_L(&T, n->parent);
	}
	else {
		s->left->color = BLACK;
		TREE_ROTATE_R(&T, n->parent);
	}
}
void delete_case5(Node** T, Node* n)
{
	Node* s = sibling(n);

	if (s->color == BLACK) {
		if ((n == n->parent->left) &&
			(s->right->color == BLACK) &&
			(s->left->color == RED)) { /* this last test is trivial too due to cases 2-4. */
			s->color = RED;
			s->left->color = BLACK;
			TREE_ROTATE_R(&T, s);
		}
		else if ((n == n->parent->right) && (s->left->color == BLACK) && (s->right->color == RED))
		{
			s->color = RED;
			s->right->color = BLACK;
			TREE_ROTATE_L(&T, s);
		}
	}
	delete_case6(T, n);
}

void delete_case4(Node** T, Node* n)
{
	Node* s = sibling(n);

	if ((n->parent->color == RED) &&
		(s->color == BLACK) &&
		(s->left->color == BLACK) &&
		(s->right->color == BLACK)) {
		s->color = RED;
		n->parent->color = BLACK;
	}
	else
		delete_case5(T, n);
}
void delete_case3(Node** T, Node* n)
{
	Node* s = sibling(n);

	if ((n->parent->color == BLACK) &&
		(s->color == BLACK) &&
		(s->left->color == BLACK) &&
		(s->right->color == BLACK)) {
		s->color = RED;
		delete_case1(T, n->parent);
	}
	else
		delete_case4(T, n);
}
void delete_case2(Node** T, Node* n)
{
	Node* s = sibling(n);

	if (s->color == RED) {
		n->parent->color = RED;
		s->color = BLACK;
		if (n == n->parent->left)
			TREE_ROTATE_L(&T, n->parent);
		else
			TREE_ROTATE_R(&T, n->parent);
	}
	delete_case3(T, n);
}
void delete_case1(Node** T, Node* n)
{
	if (n->parent != NULL)
		delete_case2(T, n);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int n, num;
	int ky;
	cout << "Введите количечество элементов" << endl;
	cin >> n;
	ky = n;
	Node* root = 0;
	while (n != 0)
	{
		cin >> num;
		
			
		
		insert(&root, num);
		n--;
	}
	while (root->parent != NULL)
				root = root->parent;
	/*if (parent == NULL)
		root(parent);*/
  
}

