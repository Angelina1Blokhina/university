#include <thread>
#include <chrono>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <mutex>
#include <iostream>
#include <fstream>
using namespace std;
int dog1(0), spr1(0), spr2(0), kv1(0), kv2(0);//счетчик количества договоров, справок и квитанций
int i(0),kont(0),f1, l1,u, u1;
int posetitel(0), posetitel1, posetitel2;// счетчик посетителей
int arr1[45], arr2[45], ar1(0), ar2(0);//сохраняем в эти массивы какие категории посетителей в какие окна зашли

struct Che
{
	int a;
	Che* tail;
};

void Open(char name[45])//вывод данных из файла 
{
	system("cls");
	char buff;
	ifstream fin;
	fin.open(name);
	while (fin.get(buff))
		cout << buff;
	
	cout << endl << endl;

	fin.close();

}

void Save(Che**h, int b1[40], int *n)//ввод данных в файл
{
	int qa(0), qa1(0), qq(1);
	char name[45];
	cout << "Введите название файла" << endl;
	cin >> name;
	Che* p = *h;
	ofstream fout;
	fout.open(name);
	fout <<"Очередь до начала работы  ";//записываем массив в файл
	for(int y=0; y<*n;y++)
		fout << b1[y]<<" ";
	fout << endl;
	fout << "Очередь во время работы  ";//записываем односвязный список в файл
	while (p != NULL)
	{
		fout << p->a<<" ";
		p = p->tail;
	}
	fout<<endl << "_________________________________________________________________________________________" << endl;
	fout << "окно 1                                                                             окно 2" << endl;
	fout << "_________________________________________________________________________________________" << endl;
	while ((ar1 > 0) | (ar2 > 0))//записываем какие посетители были в окнах
	{

		if (ar1 > 0)
		{
			fout << arr1[qa];
			qa++;
			ar1--;
		}
		if (ar2 > 0)
		{
			if (ar1 == 0)
			{
				if (qq == 0)
					fout << "                                                                                      " << arr2[qa1];
				else
				{
					fout << "                                                                                     " << arr2[qa1];
					qq = 0;
				}

			}

			else
				fout << "                                                                                     " << arr2[qa1];
			qa1++;
			ar2--;
		}
		fout << endl;
	}
	fout << endl << endl << endl; //записываем количество оформленных документов
	fout << "_________________________________________________________________________________________________________" << endl;

	fout<<"______________ окно 1 _____________________________________________________________________________окно 2" << endl;
	fout << "|Договоры     |" << dog1 << "     |_____________________________________________________________________________| " << "-  |" << endl;
	fout << "|Справки      |" << spr1 << "     |_____________________________________________________________________________|" << spr2 << "   |" << endl;
	fout<<"|Квитанции    |" << kv1 << "     |_____________________________________________________________________________|" << kv2 << "   |" << endl;

	fout.close();
	Open(name);
}

void kvi()
{
	this_thread::sleep_for(chrono::milliseconds(1500));
}
void spravka() 
{
	this_thread::sleep_for(chrono::milliseconds(2500));
}
void dogovor()
{
	this_thread::sleep_for(chrono::milliseconds(6000));
}

int random()//случайным образом выбирается какой вид документа оформляет посетитель
{
	int s;
	srand(time(NULL));
	s = 1+rand() % 3;
	return s;
}

void okno1(Che **h,  int m)

{
	
	if (m > -1)
	{
	
	Che* p = *h;
	cout << endl;
	posetitel++;
	posetitel1 = posetitel;//присваиваем номер посетителя
	cout << endl << "_____________________________________" << endl;
	cout << "Зашел посетитель № "<<posetitel<<endl;
	
	if (p!=NULL)
		if(p->a==1)
		cout <<"Льготная категория ("<< p->a<<")"<< endl;
		else
		cout << "Нельготная категория (" << p->a <<")"<< endl;
	
	u=random();

	switch (u)// вызов функций с документами
	{
		case 1:
		{
			if(kont!=0) kont = 0;
			spravka();
			spr1++;
			
			cout << "Посетитель оформил справку";
			break;
			
		}
		case 2:
		{
			i=i+2;//блокирует первое окно
			if (kont != 0) kont = 0;
			if (p->tail != NULL)//пропускаем без очереди льготного посетителя, если он есть
			{
				if (p->tail->tail != NULL)
				{
					if ((p->tail->tail->a) == 1)
					{
						f1 = p->tail->tail->a;
						l1 = p->tail->a;//следующий элемент не единица
						p->tail->a = f1;//элемент стал единицой
						p->tail->tail->a = l1;//хвост единцы предыдущий элемент

					}
				}
			}
			dogovor();
			dog1++;
			cout << "Посетитель оформил договор";
			i = i - 2;//снимает блок 
			break;
		}
		case 3:
		{

			
			kvi();
			kv1++;
			kont++;
			cout << "Посетитель оформил квитанцию ";
			break;
		}

	}
	arr1[ar1] = p->a;//записываем какой посетитель зашел в первое окно
	ar1++;
	
	cout <<endl<< "Вышел посетитель № " << posetitel1 << endl;
		
	cout << "_____________________________________" << endl<<endl;
	
	

	}
	
}
void okno2(Che **h, int m) 
{
	Che* p = *h;
	if (m > -1)
	{
		
		
		posetitel++;
		posetitel2 = posetitel;
		cout << endl << "                                                                                      _____________________________________" << endl;
		cout <<"                                                                                      Зашел посетитель № " << posetitel << endl<<endl;
		
		if (p != NULL)
			if(p->a==1)
			cout << "                                                                                      Льготная категория (" << p->a <<")"<< endl << endl;
			else
			cout << "                                                                                      Нельготная категория ( " << p->a <<")"<<endl << endl;

		u1 = random();

		switch (u1)
		{
		case 1:
		{

			spravka();
			spr2++;
			cout << "                                                                                      Посетитель оформил справку";
			break;

		}
		case 2:
		{
			kvi();
			kv2++;
			cout << "                                                                                      Посетитель оформил квитанцию ";
			break;
		}
		case 3:
		{
			kvi();
			kv2++;
			cout << "                                                                                      Посетитель оформил квитанцию ";
			break;
		}
		}
		arr2[ar2] = p->a;
		ar2++;
		cout <<endl << "                                                                                      Вышел посетитель № " << posetitel2 << endl;
		cout << "                                                                                      _____________________________________" << endl << endl;

		
		
	}
}

void ochered(int m, Che **h)
{
	system("cls");
	Che* g = *h;
	
	cout << "Очередь ";//выводим порядок посетителей
	while (g != NULL)
	{
		cout<<" "<<g->a;
		g = g->tail;
	}
	g = *h;
	cout << endl << "========================================================================================================"<<endl;
	cout << "О К Н О 1" << " ________________________________________________________________________________" << "О К Н О 2" << endl;

	while (m > -1)
	{
		m--;
		if (i == 0)// если окно 1 свободно
		{
			thread th(okno1, &g, m);
			th.detach();
			this_thread::sleep_for(chrono::milliseconds(1600));

			if (g->tail != NULL)
				g = g->tail;
			
			while (kont > 0)//если в окно 1 оформили квитанцию, следующий посетитель идет в окно 1
			{
				m--;
				thread th(okno1, &g, m);
				th.detach();
				this_thread::sleep_for(chrono::milliseconds(1600));
				if (g->tail != NULL)
					g = g->tail;
				
			}
				m--;
				this_thread::sleep_for(chrono::milliseconds(900));
				thread rt(okno2, &g, m);// поетитель заходит во 2 окно
				rt.detach();

				this_thread::sleep_for(chrono::milliseconds(2500));

				if ((g->tail) != NULL)
					g = g->tail;

			

		}
		else//если окно 1 занято 
		{
			while (i != 0)
			{

			
			thread rt(okno2, &g, m);
			rt.detach();

			this_thread::sleep_for(chrono::milliseconds(2500));



			if (g->tail != NULL)
			{
				g = g->tail;
			}
			}

		}


	}
}

int main()

{
	setlocale(LC_ALL, "Russian");
	int n,m;
	int b1[40];
	cout << "Введите количечество посетителей" << endl;
	cin >> n;
	m = n;
	Che* b = 0;
	Che* g = 0;
	cout << "Введите 1, если посетитель из льготной категории" << endl;
	cout << "Введите 2, если посетитель не из льготной категории" << endl;
	int j(0);

	while (n != 0)//ввод данных в форме односвязного списка
	{
		n--;
		if (j == 0)
		{
			
			
			b = new Che;
			cin >> b->a;
			b->tail = NULL;
			b1[j] = b->a;
			g = b;
			j++;

		}
		else
		{
			b->tail = new Che;
			b = b->tail;
			cin >> b->a;
			b1[j] = b->a;
			b->tail = NULL;
			j++;

		}
	}
	
	b = g;
	n = m;
	ochered(m, &g);//вызов функции, которая распределяет очередь по окнам

	this_thread::sleep_for(chrono::milliseconds(2500));
	Save(&b,b1,&n);//сохранение полученных данных 
	
	return 0;
}

