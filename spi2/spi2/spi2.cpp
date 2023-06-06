using namespace std;
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

struct Che
{
	int a;
	Che* head;
	Che* tail;
};
void add(Che **de, int *h)
{
	Che* p = *de;
	int nel;
	int hh, hg;
	hh = *h;
	
	cout << "Введите номер элемента" << endl;
	cin >> nel;
	hg = nel;
	int count = 1;
	Che* u = p;
	if (nel == 1)
	{
		Che* k;

		int number;
		cout << "Введите значение добавляемого элемента" << endl;
		cin >> number;
		k = new(Che);
		k->a = number; // сохранение поля данных добавляемого узла
		k->tail = *de;
		k->head = NULL;
		while (k != NULL)
		{
			cout << k->a << " ";
			k = k->tail;            // переход к следующему узлу
		}
		cout << endl << endl;
	}

	if (nel == *h)
	{
		Che* m;

		int number;
		cout << "Введите значение добавляемого элемента" << endl;
		cin >> number;

		m = new(Che);
		m->a = number;
		m->tail = NULL;
		Che* p = *de;
		while (p->tail != NULL)
			p = p->tail;
		p->tail = m;
		m->head = p;
		Che* e = *de;

		while (e != NULL)
		{
			cout << e->a << " ";
			e = e->tail;  // переход к следующему узлу

		}


		cout << endl << endl;
	}

	if (nel != 1 && nel != *h )
	{

		while (count < nel - 1 && p->tail != NULL)
		{
			p = p->tail;
			u = u->tail;
			count++;
		}
		Che* m = new(Che);
		int number;
		cout << "Введите значение добавляемого элемента" << endl;
		cin >> number;
		m->a = number;
		m->tail = p->tail;
		m->head = u;
		p->tail = m;
		p = *de;
		while (p != NULL)
		{
			cout << p->a << " ";
			p = p->tail;  // переход к следующему узлу

		}
		cout << endl << endl;
	}

	*h = hg + hh;
	}

		
void del(Che **de,int*h) 
{
	int nel;
	int hh, hg;
	cout << "Введите номер элемента" << endl;
	cin >> nel;
	hh = *h;
	hg = nel;
	if (nel == 1)
	{
		Che* m = *de;
		Che* p = new (Che);
		p = m->tail;
		delete m;
		p->head = NULL;
		while (p != NULL)
		{
			cout << p->a << " ";
			p = p->tail;            // переход к следующему узлу
		}

		cout << endl << endl;
	}
	if (nel == *h)
	{

		Che* m;
		Che* l;
		m = new(Che);

		Che* p = *de;
		m = p->tail;
		l = m->tail;
		while (l != NULL)
		{
			l = l->tail;
			m = m->tail;
			p = p->tail;
		}
		delete m;
		p->tail = NULL;
		l = *de;
		while (l != NULL)
		{
			cout << l->a << " ";
			l = l->tail;  // переход к следующему узлу

		}
	}
	if (nel != 1 & nel != *h)
	{
		Che* oq;
		Che* p = *de;
		oq = p->tail;
		int count = 1;
		while (count < nel - 1 && p->tail != NULL)
		{
			p = p->tail;
			oq = oq->tail;
			count++;
		}
		Che* m = new(Che);
		m = p->tail;
		p->tail= m->tail;
		oq->head = p;
		delete m;
		Che* e = *de;
		while (e != NULL)
		{
			cout << e->a << " ";
			e = e->tail;  // переход к следующему узлу

		}
		cout << endl << endl;
	}
	*h = hg + hh;
}

void cep1(Che **de, int *h)
{
	int jo, nel, hh, hg;
	cout << "Введите количество элементов цепочки  " << endl;
	cin >> jo;
	cout << "Введите номер элемента, на месете которого должна стоять цепочка " << endl;
	cin >> nel;
	
	hh = *h;
	hg = jo;
	if (jo != 0)
	{

		if (nel == *h)
		{
			Che* m =new Che;
			cout << "Введите значение добавляемого элемента" << endl;
			Che* p = *de;
			while (p->tail != NULL)
				p = p->tail;
			
			int r(1);
			while (jo != 0)
			{
				jo--;
			    m->tail=new Che;
				m = m->tail;
				cin >> m->a;
				m->tail = NULL;
				if (r == 1)
				{
					r--;
					p->tail = m;
					m->head = p;
					

				}
			}
			
			p = *de;
			while (p != NULL)
			{
				cout << p->a << " ";
				p = p->tail;  // переход к следующему узлу

			}
			cout << endl << endl;
		}

		if (nel == 1)
		{
			Che* p = *de;
			Che* m = new Che;
			Che* b = new Che;
			Che* o = new Che;
			int j(0);
			cout << "Введите значение элементов цепочки " << endl;
			while (jo != 0)
			{
				jo--;

				if (j == 0)
				{
					j++;
					cin >> m->a;
					m->head = NULL;
					m->tail = p;
					b = m;
					o = m;
				}

				else
				{
					b->tail = new Che;
					b = b->tail;
					cin >> b->a;
					b->head = m;
					b->tail = p;
					m = b;

				}
			}

			p->head = m;
			b = o;
			while (b != NULL)
			{
				cout << b->a << " ";
				b = b->tail;  // переход к следующему узлу

			}
			cout << endl << endl;
		}

		if (nel != 1 & nel != *h)
		{

			int count(1);
			Che* p = *de;
			Che* u = p->tail;
			while (count < nel - 1 && p->tail != NULL)
			{
				p = p->tail;
				u = u->tail;
				count++;
			}
			Che* m = new(Che);
			//int number;

			cout << "Введите значение элементов цепочки " << endl;
			//int ss(1);
			while (jo != 0)

			{
				m->tail = new Che;
				m = m->tail;
				cin >> m->a;
				p->tail = m;
				m->head = p;
				m->tail = u;
				p = m;

				jo--;


			}
			p = *de;
			while (p != NULL)
			{
				cout << p->a << " ";
				p = p->tail;  // переход к следующему узлу

			}
			cout << endl << endl;
		}
	}
	else
		cout << "Ошибка";
	*h = hg + hh;

}

void cep2(Che** de, int* h)
{
	int nel, len, nl;
	cout << "Введите номера элементов, в диапозоне которых необходимо удалить элементы" << endl;
	cin >> nel >> len;
	nl = len - nel;
	int yy, hh, hg;
	hh = *h;
	hg = nl;
	yy = *h + 1;
	if (nel == 0)
	{
		Che* m;
		Che* u;
		m = *de;
		while ((nl) != 0)
		{
			nl--;
			u = m->tail;
			delete m;
			m = u;
			m->head = NULL;

		}
		while (m != NULL)
		{
			cout << m->a;
			m = m->tail;

		}


	}
	if (len == yy)
	{
		Che* m;
		Che* u;
		m = *de;
		u = *de;
		Che* k;
		while (nel != 0)
		{
			nel--;
			u = m;
			m = m->tail;
			
		}
		u->tail = NULL;
		while (m != NULL)
		{
			len--;
			k = m->tail;
			delete m;
			m = k;
		}
		if (nl != *h)
		{
			u = *de;
			while (u != NULL)
			{
				cout << u->a;
				u = u->tail;

			}
		}
		else
			cout << "Список удален" << endl;

	}
	if (nel != 0 & len != yy)
	{
		int count(1);
		Che* p = *de;
		Che* u = *de;

		while (count < nel  && p->tail != NULL)
		{
			u = p->tail;
			p = p->tail;
			
			count++;
		}
		count = 1;
		Che* k = new Che;
		int qq(1);
		p = p->tail;
		while (nl != 0)
		{
			
			k = p->tail;
			delete p;
			p = k;
			nl--;
		}
		p->head = u;
		u->tail = p;
		p = *de;
		while (p != NULL)
		{
			cout << p->a;
			p = p->tail;

		}

		


	}
	*h = hh + hg;
}
void save(Che **de)
{
	char name[45];
	cout << "Введите название файла" << endl;
	cin >> name;
	Che* p = *de;
	ofstream fout;
	fout.open(name);
	while (p != NULL)
	{
		fout << p->a;
		p = p->tail;
	}
	fout.close();
}
void open(Che **de)
{
	char name[45];
	cout << "Введите название файла" << endl;
	cin >> name;
	int g (0), j(0);
	Che* p = new Che;
	Che* u = new Che;
	Che* e =new Che;
	char buff[50];
	ifstream fin;
	fin.open(name);
	fin >>buff ; 
	while (buff[g] != '\0')
	{
		
		if (j == 0)
		{
			j++;
			p->a = buff[g] -'0';
			p->head = NULL;
			p->tail = NULL;
			u=p;
			e = u;
			g++;
		}

		else
		{
			p->tail = new Che;
			p = p->tail;
			p->a = buff[g] -'0';
			p->head = u;
			p->tail = NULL;
			u = p;
			g++;

		}

	}
	while (e != NULL)
	{
		cout << e->a << " ";
		e = e->tail;  // переход к следующему узлу

	}
	cout << endl << endl;
	
	fin.close();

}
void kol(Che** de, int *h)
{
	Che* p = *de;
	Che* m = *de;
	while (p->tail != NULL)
	{
		p = p->tail;
		
	}
	p->tail = m;
	m->head = p;

	cout << endl << endl;

	cout << "Выполнено";
	cout << endl << endl;
}
void ankol(Che** de, int* h)
{
	Che* m = *de;
	Che* p = *de;
	int er, k(0);
	cout << "Выберете в каком месте сделать разрыв кольца " << endl;
	cin >> er;
	int yy;
	yy = *h;
	if (er == *h)
	{
		while ((*h - 1) != 0)
		{
			p = p->tail;
			(*h)--;
		}
		m = NULL;
		*de = p;
		while ( yy!=0)
		{
			yy--;
			cout << p->a << " ";
			p->head = m;
			m = p;
			p = p->tail;
		}
		p->tail = NULL;
		
	}

	else
	{
		int count = 1;
		while (count < er - 1 && p->tail != NULL)
		{
			p = p->tail;
			count++;
		}
		//Che* m = new(Che);
		Che* l = NULL;
		p->head = NULL;
	
		*de = p;
		m = *de;
		m = m->tail;
		
		while (/*(m != NULL)*/  ( yy!= 0))
		{
			yy--;
			cout << m->a << " ";
			m->head = l;
			l = m;
			m = m->tail;  // переход к следующему узлу
		}
		m->tail = NULL;
		
		
	}
	
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	int m;
	int s;
	cout << "Введите количечество элементов" << endl;
	cin >> n;
	m = n;
	s = m;
	Che* o = 0;
	Che* b = o;
	Che* g = 0;
	cout << "Введите значение элементов" << endl;
	int j(0);
	while (n != 0)
	{
		n--;
		if (j == 0)
		{
			j++;
			o = new Che;
			cin >> o->a;
			o->head = NULL;
			o->tail = NULL;
			b = o;
			g = o;
		}

		else
		{
			b->tail = new Che;
			b = b->tail;
			cin >> b->a;
			b->head = o;
			b->tail = NULL;
			o = b;

		}
	}

	int key = 0, ch = 0;
	while (1)
	{
		system("cls");
		cout << "Выберите действие   ";
		if (key == 0)cout << "<--" << endl;
		cout << endl << endl;
		cout << "Если хотите добавить число, то нажмите 1   ";
		if (key == 1)cout << "<--" << endl;
		cout << endl << endl;
		cout << "Если хотите удалить элемент, то нажмите 2  ";
		if (key == 2)cout << "<--" << endl;
		cout << endl << endl;
		cout << "Если хотите добавить цепочку из чисел, то нажмите 3  ";
		if (key == 3)cout << "<--" << endl;
		cout << endl << endl;
		cout << "Если удалить цепочку, то нажмите 4  ";
		if (key == 4)cout << "<--" << endl;
		cout << endl << endl;
		cout << "Если хотите сохранить, то нажмите 5 ";
		if (key == 5)cout << "<--" << endl;
		cout << endl << endl;
		cout << "Если хотите открыть файл, то нажмите 6 ";
		if (key == 6)cout << "<--" << endl;
		cout << endl << endl;
		cout << "Если хотите закольцевать, то нажмите 7";
		if (key == 7)cout << "<--" << endl;
		cout << endl << endl;
		cout << "Если хотите раскольцевать, то нажмите 8 ";
		if (key == 8)cout << "<--" << endl;
		cout << endl << endl;


		switch (key)
		{
		case 1:

			add(&g, &m);
			break;
		case 2:
			del(&g, &m);
			break;
		case 3:
			cep1(&g, &m);
			break;
		case 4:
			cep2(&g, &m);
			break;
		case 5:
			save(&g);
			break;
		case 6:
			open(&g);
			break;
		case 7:
			kol(&g, &m);
			break;
		case 8:
			ankol(&g, &m);
			break;

		}

		int snt = 0, vkl = 0, ch = 0;
		do {                             //добавила здесь цикл, чтобы всё не стиралось 
			vkl = 1;
			ch = _getch();
			if (ch == 224)
			{
				ch = _getch();
				snt = 1;
			}

			if (snt == 0) // одно считывание
				switch (ch)
				{

				case 49:
					key = 1;
					break;
				case 50:
					key = 2;
					break;
				case 51:
					key = 3;
					break;
				case 52:
					key = 4;
					break;
				case '5':
					key = 5;
					break;
				case '6':
					key = 6;
					break;
				case'7':
					key = 7;
					break;
				case'8':
					key = 8;
					break;
				case 27:
					return 0;

				}

			else  // snt = 1 два считывания
				switch (ch) {
				case 72:
					key--;
					if (key < 1) key = 7;
					break;
				case 80:
					key++;
					if (key > 7) key = 1;
					break;

				}

		} while (vkl != 1);

	}
		return 0;


	
}

