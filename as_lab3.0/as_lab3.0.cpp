using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <math.h>
typedef enum { BLACK, RED } nodeColor;
struct Node
{
	int key;
	Node* left;
	Node* right;
	Node* parent;
	char color;
};
void TREE_ROTATE_R(Node ***T, Node*current)
{
	Node* pivot;
	pivot = current->left;
	//parent->parent = current->parent;
	pivot->parent = current->parent;
	if (current->parent == NULL)
		**T = pivot;
	else
	{
		if (current == current->parent->right)
			current->parent->right = pivot;
		else
			current->parent->left = pivot;
	}

	current->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = current;

	
	/* Соединяем x и y. */
	pivot->right = current;
	current->parent = pivot;


}
void TREE_ROTATE_L(Node*** T, Node* current)
{
	/* На вход подается дерево T и опорный узел x. */
	Node* parent;
	parent = current->right;
	parent->parent = current->parent;
	if (current->parent == NULL)
		**T = parent;
	else
	{
		if (current == current->parent->left)
			current->parent->left = parent;
		else
			current->parent->right = parent;
	}
	current->right = parent->left;
	if (parent->left != NULL)
		parent->left->parent = current;

	
	/* Соединяем x и y. */
	parent->left = current;
	current->parent = parent;


}
void fixup(Node** T, Node* New_Node, Node *parent)
{
	Node* current = New_Node;
	if (current->parent != NULL) {
		while ((current != *T) && current->parent->color == RED)
		{
			if (current->parent == current->parent->parent->left)
			{
				parent = current->parent->parent->right; /* parent – дядя x */
				if (parent != NULL)
				{
					if (parent->color == RED) /* случай 1 */
					{
						current->parent->color = BLACK;
						parent->color = BLACK;
						current->parent->parent->color = RED;
						current = current->parent->parent;/* при следующем заходе в цикл начнем проверку с деда x */
					}

					else
					{
						if (current == current->parent->right)/* случай 3 */
						/* сводим к случаю 2 */
						{
							current = current->parent;
							TREE_ROTATE_L(&T, current);
						}

						current->parent->color = BLACK;/* случай 2 */
						current->parent->parent->color = RED;
						TREE_ROTATE_R(&T, current->parent->parent);
					}
				}
				else
				{
					if (current == current->parent->right)/* случай 3 */
					/* сводим к случаю 2 */
					{
						current = current->parent;
						TREE_ROTATE_L(&T, current);
					}

					current->parent->color = BLACK;/* случай 2 */
					current->parent->parent->color = RED;
					TREE_ROTATE_R(&T, current->parent->parent);
				}
			}
			else
			{
				parent = current->parent->parent->left;
				if (parent != NULL)/* y – дядя x */
				{
					if (parent->color == RED) /* случай 1 */
					{
						current->parent->color = BLACK;
						parent->color = BLACK;
						current->parent->parent->color = RED;
						current = current->parent->parent;


						/* при следующем заходе в цикл начнем проверку с деда x */
					}

					else
					{
						if (current == current->parent->left)/* случай 3 */
						/* сводим к случаю 2 */
						{
							current = current->parent;
							TREE_ROTATE_R(&T, current);
						}

						current->parent->color = BLACK;/* случай 2 */
						current->parent->parent->color = RED;
						TREE_ROTATE_L(&T, current->parent->parent);


					}
				}
				else
				{
					if (current == current->parent->left)/* случай 3 */
					/* сводим к случаю 2 */
					{
						current = current->parent;
						TREE_ROTATE_R(&T, current);
					}

					current->parent->color = BLACK;/* случай 2 */
					current->parent->parent->color = RED;
					TREE_ROTATE_L(&T, current->parent->parent);


				}

			}
		}
	}
	(*T)->color = BLACK;
}

void TREE_SEARCH(Node **T, int k)/* На вход подается дерево T, в котором производится поиск, и k– значение ключа. Возвращается узел дерева, в котором находится искомый ключ, или NULL, если узла с искомым ключом в дереве нет. */

{
	Node* current, *parent, *New_Node;
	current = *T;
	parent = NULL;
	while (current != NULL )//Просматриваем текущий узел, спускаясь по дереву вниз, пока не найдем искомый ключ или не дойдем до пустого поддерева. 
	{
		parent = current;
		if (k < current->key)
			current = current->left; /* присваиваем x его левого сына */
		else
			current = current->right; /* присваиваем x его правого сына */

	}
	if(current!=NULL) parent = current;
		New_Node = new Node();
		New_Node->key = k;
		New_Node->parent = parent;
		New_Node->left = NULL;
	
		New_Node->right = NULL;
		
		New_Node->color = RED;
		if (parent != NULL)
		{
			if (k < parent->key) parent->left = New_Node;
			else parent->right = New_Node;
		}
		else
		{
			current = New_Node;
			*T = New_Node;
		}
		fixup(T, New_Node, parent);
	
}
void RB_DELETE_FIXUP(Node** T, Node* n)
{
	Node* b;
	//На вход подается дерево T и n – сын удаленного узла. 
	while (n != *T & n->color == BLACK)
	{
		if (n == n->parent->left)
		{
			b = n->parent->right; //b – брат n 
			if (b->color == RED) //случай 4 
			{
				b->color = BLACK;
				n->parent->color = RED;
				TREE_ROTATE_L(&T, n->parent);
				b = n->parent->right; //теперь у n черный брат 
			}
			if (b->left->color == BLACK & b->right->color == BLACK)//случай 1 или 5 
			{
				b->color = RED;
				n = n->parent; // при следующем заходе в цикл просмотрим отца n: если он красный, то имел место случай 1 (в цикл не заходим),
							   //а если он черный, то имел место случай 5 (продолжаем цикл) 
			}
			else
			{
				if (b->right->color == BLACK) //случай 3 
				// сводим к случаю 2 
				{
					b->left->color = BLACK;
					b->color = RED;
					TREE_ROTATE_R(&T, b);
					b = n->parent->right;
				}
				b->color = n->parent->color; //случай 2 
				n->parent->color = BLACK;
				b->right->color = BLACK;
				TREE_ROTATE_L(&T, n->parent);
				n = *T; //при попытке зайти в цикл следующий раз процесс прекратится 
			}

		}
		else
		{
			b = n->parent->left; //b – брат n 
			if (b->color == RED) // случай 4 
			{
				b->color = BLACK;
				n->parent->color = RED;
				TREE_ROTATE_R(&T, n->parent);
				b = n->parent->left; //теперь у n черный брат 
			}
			if (b->right->color == BLACK & b->left->color == BLACK)// случай 1 или 5 
			{
				b->color = RED;
				n = n->parent; // при следующем заходе в цикл просмотрим отца n: если он красный, то имел место случай 1 (в цикл не заходим),
							   //а если он черный, то имел место случай 5 (продолжаем цикл) 
			}
			else
			{
				if (b->left->color == BLACK) // случай 3 
				// сводим к случаю 2 
				{
					b->right->color = BLACK;
					b->color = RED;
					TREE_ROTATE_L(&T, b);
					b = n->parent->left;
				}
				b->color = n->parent->color; //случай 2 
				n->parent->color = BLACK;
				b->right->color = BLACK;
				TREE_ROTATE_R(&T, n->parent);
				n = *T; // при попытке зайти в цикл следующий раз процесс прекратится 
			}

		}
		
	}
	n->color = BLACK;
}
struct Node* TREE_MINIMUM(Node *x)
{	
	while (x->left != NULL)/* ищем самый левый узел в дереве */
		x = x->left;
	return x;
}
struct Node* TREE_SUCCESSOR(Node* x)
{
	Node* y;
	if (x->right != NULL)/* Если у узла есть правое поддерево, то возвращаем самый левый узел правого поддерева. */
		return TREE_MINIMUM(x->right);
	y = x->parent;
	while (y != NULL & x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}
void RB_DELETE(Node **T, Node *z)
{
	Node* y, * x;
	// На вход подается дерево T и узел z, который необходимо удалить из дерева, возвращается удаленный узел. 
	if (z->left == NULL or z->right == NULL)  //один из сыновей узла z – фиктивный лист 
		y = z;
	else
		y = TREE_SUCCESSOR( z);
	/*{
		if (x->right != NULL)
		{
			x = *T;
			while (x->left != NULL) // ищем самый левый узел в дереве 
				x = x->left;
		}
			
		y = x->parent;
		while (y != NULL & x == y->right)
		{
			x = y;
			y = y->parent;
		}
	}*/
		
	if (y->left != NULL)// присваиваем x единственного сына y 
		x = y->left;
	else
		 x = y->right;
	if(x!=NULL)
		x->parent = y->parent;
	
	if (y->parent == NULL)
		*T = x;
	else
	{
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	}
	if (y != z)
		z->key = y->key;
	if (y->color == BLACK)
		// если удаленный узел y – черный, то вызываем процедуру восстановления, которой передаем его сына 
		RB_DELETE_FIXUP(T, x);
		//return y
}

struct Node* delete_tree(Node* k, int A[], int n )
{
	
	int j = 0, l;
	int* B = new int[n-1];
	Node* root = 0;
	for(int i=0; i<n; i++)
	{
		if (A[i] != k->key)
		{
			l = A[i];
			B[j] = A[i];
			j++;
		}
	}
	n--;
	j = 0;
	while (n != 0)
	{
		 l= B[j];
		 j++;
		 n--;
		TREE_SEARCH(&root, l);
	}
	return root;
}

void Print_RBTree(Node* T, int l)
{
	int i;
	if (T != NULL) {
		Print_RBTree(T->right, l + 1);
		for (i = 0; i < l; i++) cout << "    ";
		//if (Node->color == RED)
			//SetConsoleTextAttribute(hStd, FOREGROUND_RED);
		printf("%4ld", T->key);
		if(T->color==0)  printf("  b");
		else printf( "  r");
		//SetConsoleTextAttribute(hStd, atr);
		Print_RBTree(T->left, l + 1);
	}
	else cout << endl;

}

struct Node *INTERATIVE_TREE_SEARCH(Node **T, int k)
{
	Node* x;
	x = *T;
	while (x != NULL & k != x->key)
		/* Просматриваем текущий узел, спускаясь по дереву вниз, пока не найдем искомый ключ или не дойдем до пустого поддерева. */
		if (k < x->key)
			x = x->left; /* присваиваем x его левого сына */
		else
			x = x->right; /* присваиваем x его правого сына */
	return x;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int k, n, p_n,s=1;
	Node* root = 0;
	cout << "Введите количество элементов: ";
	cin >> n;
	cout << "---------------------------------------------------------------------------------------";
	p_n = n;
	int* A = new int[n];
	while (n != 0)
	{
		k= rand() % 100;
		TREE_SEARCH(&root, k);
		for (int i = 0; i < s - 1; i++)
		{
			if(A[i]==k)
				k = rand() % 100;

		}
		A[s - 1] = k;
		cout <<endl<< s << ". "<<k;
		
		s++;
		
		n--;
	}
	Print_RBTree(root, p_n);
	cout << "===============================================================================================" << endl << "Введите элемент, который необходимо удалить" << endl;
	cin >> k;

	Node* current = INTERATIVE_TREE_SEARCH(&root,k);
	char col;
	if (current->color == 1)
		cout <<"Найден элемент "<< current->key << "   " << "Красный" << endl;
	else 
		cout << "Найден элемент " << current->key << "   " << "Черный" << endl;

	root=delete_tree(current, A, p_n);
	p_n--;
	
	Print_RBTree(root,p_n );
}

