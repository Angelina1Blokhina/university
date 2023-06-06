using namespace std;
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Che 
	{
		int a;
		Che* next;
	};

void addnach(Che **head, int *ln) 
{
	Che* k;
	
	int number;
	cout << "Введите значение добавляемого элемента" << endl;
	cin >> number;
	k = new(Che);
	k->a = number; // сохранение поля данных добавляемого узла
	k->next = *head;
	*head = k;
	while (k != NULL)
	{
		cout << k->a << " ";
		k = k->next;            // переход к следующему узлу
	}
	cout << endl << endl;
	*ln = *ln + 1;

};
void addkon(Che **head, int*ln)
{
	Che* m;

	int number;
	cout << "Введите значение добавляемого элемента" << endl;
	cin >> number;
	
	m = new(Che);
	m->a = number;
	m->next = NULL;
	Che* p = *head;
	while (p->next != NULL)
		p = p->next;
	p->next = m;
	Che*e = *head;
	
	while ( e!= NULL)
	{
		cout << e->a << " ";
		e= e->next;  // переход к следующему узлу
		           
	}
	

	cout << endl << endl;
	*ln = *ln + 1;
}
void addmid(Che**head, int*ln )
{
	Che* p = *head;
	int nel;
	cout << "Введите номер элемента" << endl;

	cin >> nel;
	int count = 1;

	while(count<nel-1 && p->next!=NULL)
	{
		p = p->next;
		count++;
	}
	Che* m = new(Che);
	int number;
	cout << "Введите значение добавляемого элемента" << endl;
	cin >> number;
	m->a = number;
	m->next = p->next;
	p->next = m;
	p = *head;
	while (p != NULL)
	{
		cout << p->a << " ";
		p = p->next;  // переход к следующему узлу

	}
	cout << endl << endl;
	*ln = *ln + 1;
}

void cancelnach(Che**head,int*ln)
{
	Che* m = *head;
	Che* p = new (Che);
	p = m->next;
	delete m;
	*head = p;
	while (p != NULL)
	{
		cout << p->a << " ";
		p = p->next;            // переход к следующему узлу
	}
	cout << endl << endl;
	*ln = *ln - 1;
}
void cancelkon(Che** head, int *ln) 
{
	Che* m;
	Che* l;
	m = new(Che);
	
	Che* p = *head;
	m = p->next;
	l = m->next;
	while (l != NULL)
	{
		l = l->next;
		m = m->next;
		p = p->next;
	}
	delete m;
	p->next=NULL;
	l= *head;
	while (l != NULL)
	{
		cout << l->a << " ";
		l = l->next;  // переход к следующему узлу

	}
	*ln = *ln - 1;
}
void cancelmid(Che** head, int nel,int *ln) 
{
	Che* p = *head;
	int count = 1;
	while (count < nel - 1 && p->next != NULL)
	{
		p = p->next;
		count++;
	}
	Che* m = new(Che);
	m = p->next;
	p->next = m -> next;
	delete m;
	Che* e = *head;
	while (e!= NULL)
	{
		cout << e->a << " ";
		e = e->next;  // переход к следующему узлу

	}
	cout << endl << endl;
	*ln = *ln - 1;

}

void kol(Che **head, int *ln) 
{
	Che* p = *head;
	Che* m = *head;
	while (*ln-1!=0)
	{
		p = p->next;
		(*ln)--;
	}
	p->next = m;
	
	cout << endl << endl;

	cout <<"Выполнено";
	cout << endl << endl;

}
void antkol(Che** head, int *ln) 
{
	Che* m = *head;
	Che* p = *head;
	int h, k(0);
	cout << "Выберете в каком месте сделать разрыв кольца "<<endl;
	cin>>h;
	int yy;
	yy = *ln;
	int iu = *ln;
	if (h == *ln) 
	{
		while ((ln - 1) != 0)
		{
			p = p->next;
			(ln)--;
		}
		*head=p;
		p->next =m;
		while ( yy!=0 ) 
		{
			cout << p->a << " ";
			p = p->next;
			yy--;
		}
		p->next = NULL;
	}
	else
	{
		int count = 1;
		while (count < h - 1 && p->next != NULL)
		{
			p = p->next;
			count++;
		}
		Che* l = new(Che);
		l = *head;
		*head = p->next;
		m = *head;
		while ((m != NULL) & (*ln!= 0))
		{
			*ln--;
			cout << m->a << " ";
			m = m->next;  // переход к следующему узлу

		}
		
		
		cout << endl << endl;
	}

	*ln = iu;


}


int main()

{

	setlocale(LC_ALL, "Russian");
	int n;
	int ky;
	cout << "Введите количечество элементов" << endl;
	cin >> n;
	ky= n;
	Che* head = 0;
	Che* b1 = head;
	




	
		cout << "Введите значения элементов" << endl;
		while (n != 0)
		{
			n--;
			if (!head)
			{
				head = new Che; //выделяем память
				cin >> head->a;//вводим
				head->next = NULL;//присваеваем следующему узлу ноль
				b1 = head;//текущий

			}
			else
			{
				b1->next = new (Che);//выделяем память
				b1 = b1->next;//переход на узел
				cin >> b1->a;//значение
				b1->next = NULL;//присваеваем следующему ноль

			}

		};
		b1 = head;
		while (b1 != NULL)
		{
			cout << b1->a << " ";
			b1 = b1->next;            // переход к следующему узлу
		}
		cout << endl << endl;

		int key = 0, ch = 0, lu;
		lu = ky;
		while (1)
		{
			system("cls");
			cout << "Выберите действие   ";              
			if (key == 0)cout << "<--" << endl;
			cout << endl << endl;
			cout << "Если хотите добавить число в начале, то нажмите 1   ";
			if (key == 1)cout << "<--" << endl;
			cout << endl << endl;
			cout << "Если хотите добавить число в конец , то нажмите 2   ";
			if (key == 2)cout << "<--"<< endl;
			cout << endl << endl;
			cout << "Если хотите добавить число в произвольное место , то нажмите 3  ";
			if (key == 3)cout << "<--"<< endl;
			cout << endl << endl;
			cout << "Если хотите удалить элемент, то нажмите 4 ";
			if (key == 4)cout << "<--"<< endl;
			cout << endl << endl;
			cout << "Если хотите закольцевать, то нажмите 5 ";
			if (key == 5)cout << "<--" << endl;
			cout << endl << endl;
			cout << "Если хотите раскольцевать, то нажмите 6  ";
			if (key == 6)cout << "<--" << endl;
			cout << endl << endl;

			switch (key)
			{
			case 1:

				addnach(&head, &ky);
				break;
			case 2:
				addkon(&head, &ky);
				break;
			case 3:
				addmid(&head, &ky);
				break;
			case 4:	
				cout << "Введите номер элемента" << endl;
				int ber;
				cin >> ber;
				if (ber == 1)
					cancelnach(&head, &ky);
				if (ber == ky)
					cancelkon(&head, &ky);

				else
					cancelmid(&head,ber, &ky);
				break;
			case 5:
				kol(&head, &ky);
				break;
			case 6:
				antkol(&head, &ky);
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

