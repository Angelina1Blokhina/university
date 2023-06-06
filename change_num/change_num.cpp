using namespace std;

#include <iostream>
struct Che
{
	int a;
	Che* tail;
	//Che* head;
};


int main()
{
	int n;
	int m;
	cout << "Введите количечество элементов" << endl;
	cin >> n;
	m = n;
	Che* o = 0;
	Che* b = o;
	Che* g = 0;


	cout << "Введите 1 или 2" << endl;
	int j(0);

	while (n != 0)
	{
		n--;
		if (j == 0)
		{
			j++;
			b = new Che;
			cin >> b->a;
			//o->head = NULL;
			b->tail = NULL;
			//b = o;
			g = b;
		}

		else
		{
			b->tail = new Che;
			b = b->tail;
			cin >> b->a;
			//b->head = o;
			b->tail = NULL;
			//o = b;

		}
	}
	cout << "====================";
	int f(0), l;
	while (m > -1)
	{
		cout << endl;

		if (f == 0)
		{
			cout << g->a;
			f--;
		}

		if (g->tail != NULL)
		{
			g = g->tail;
			if (g->tail != NULL)
			{


				if ((g->tail->a) == 1)
				{
					f = g->tail->a;
					l = g->a;//следующий элемент не единица
					g->a = f;//элемент стал единицой
					g->tail->a = l;//хвост единцы предыдущий элемент
					//o->tail = b;



					//this_thread::sleep_for(chrono::milliseconds(2500));



				}
			}
			
				
		}
		
		cout << g->a;
		
		m--;
	}

		return 1;
    
}

