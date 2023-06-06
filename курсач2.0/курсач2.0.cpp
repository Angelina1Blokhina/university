#include <iostream>

using namespace std;
	struct DSU
	{
		char data; 
		//int rank;
		//char mn[50];
		DSU* gol;
		DSU* nex;
		DSU *tail;
	};
class Graph
{
private:
	struct Edge
	{
		int weight;
		char start;
		char end;
		Edge* next;

	};

	struct Tree
	{
		int vess;
		char nachh;
		char konn;
		Tree* sled;
	};
	int Ver;
	int Edgee;

	Edge* head = 0;
	DSU* s[50];
	
	Tree* golova = 0;

public:
	Graph(int ver, int ed)
	{
		Ver = ver;
		Edgee = ed;
		
	}


	void Enter();
	void isort();
	void Make();
	int Union(DSU* x, DSU* y);

	void Output();
	void Kruskal()
	{

		Make();
		Edge* c = head;
		Tree* nov = golova;
		DSU* uRep(0), * vRep(0);

		int m(0), n;
		char x, y;
		while (m < Edgee) {

			m++;
			for (int i = 0; i < Ver; i++)
			{
				if (s[i]->data == c->start)
				{
					uRep = s[i];
				}
			}
			for (int i = 0; i < Ver; i++)
			{
				if (s[i]->data == c->end)
				{
					vRep = s[i];
				}
			}
		
			if (uRep != vRep)
			{
				
				n=Union(uRep, vRep);
				if (n == 1)
				{
					if (!golova)
					{
						golova = new Tree;

						golova->nachh = c->start;
						golova->konn = c->end;
						golova->vess = c->weight;
						golova->sled = NULL;

						nov = golova;

					}
					else
					{
						nov->sled = new (Tree);
						nov = nov->sled;
						nov->nachh = c->start;
						nov->konn = c->end;
						nov->vess = c->weight;
						nov->sled = NULL;



					}
				}
				
			}
			c = c->next;
		}
	}
	};
	

int Graph::Union(DSU *x, DSU* y)
{ 
	bool n(0);
	x = x->gol;
	y = y->gol;
	if (x == y) return n;
	x->tail->nex = y;                         
	x->tail = y->tail;                          
	while (y != NULL)                          
	{
		y->gol = x;
		y = y->nex;
	}
	n = 1;
	return n;
}
void Graph::Make()
{
	char mas_o[50];
	Edge* c = head; 
	

	int g;
	for (g = 0; c != NULL; g++)
	{
		mas_o[g] = c->start;
		g++;
		mas_o[g] = c->end;
		c = c->next;
	}
	for (int counter1 = 0; counter1 < g; counter1++)
	{
		for (int counter2 = counter1 + 1; counter2 < g; counter2++)
		{
			if (mas_o[counter1] == mas_o[counter2]) // если найден одинаковый элемент
			{
				for (int counter_shift = counter2; counter_shift < g - 1; counter_shift++)
				{
					// выполнить сдвиг всех остальных элементов массива на -1, начиная со следующего элемента, после найденного дубля
					mas_o[counter_shift] = mas_o[counter_shift + 1];
				}
				g -= 1; // уменьшить размер массива на 1

				if (mas_o[counter1] == mas_o[counter2]) // если следующий элемент - дубль
				{
					counter2--; // выполнить переход на предыдущий элемент     
				}
			}
		}
	}
	
	
	for (int counter1 = 0; counter1 < Ver; counter1++)
	{
		s[counter1] = new DSU;

		s[counter1]->data = mas_o[counter1];
		s[counter1]->gol = s[counter1];
		s[counter1]->tail = s[counter1];
		s[counter1]-> nex = NULL;
		
	}
	
		cout << endl;
}
void Graph::isort()
{
	Edge* a, * b, * p, * h = NULL;

	for (Edge* i = head; i != NULL; ) {
		a = i;
		i = i->next;
		b = h;
		for (p = NULL; (b != NULL) && (a->weight > b->weight); ) {
			p = b;
			b = b->next;
		}

		if (p == NULL) {
			a->next = h;
			h = a;
		}
		else {
			a->next = b;
			p->next = a;
		}
	}
	if (h != NULL)
		head = h;
}
void Graph::Enter()
{
	

	int m(0);
	
	Edge* nach = head;
	
	while (m < Edgee)
	{
		m++;
		if (!head)
		{
			head = new Edge;
			
			cin >> head->start >> head->end >> head->weight;//вводим
			head->next = NULL;
			
			nach = head;
		}
		else
		{
			nach->next = new (Edge);
			nach = nach->next;
			cin >> nach->start >> nach->end >> nach->weight; 
			nach->next = NULL;
			
		}

	};

	

}



void Graph:: Output()
{
	Tree* a = golova;
	int ml = 0;
	cout << "Ребро-----" << "Вес" << endl;
	while (a != NULL)
	{
		cout << a->nachh << " " << a->konn << " " << a->vess << endl;
		ml = ml + a->vess;
		a = a->sled;

	}
	cout <<endl<< "Вес остовного дерева:" << ml;

}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	int ed, ver;
	cout << "Введите количество ребер" << endl;
	cin >> ed;
	cout << "Введите количество вершин" << endl;
	cin >> ver;
	cout << "Введите ребра и вес" << endl;
	Graph g(ver, ed);
	g.Enter();
	g.isort();
	//g.Make();
	g.Kruskal();
	g.Output();

	
}
 
