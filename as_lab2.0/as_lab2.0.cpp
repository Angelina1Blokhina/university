using namespace std;
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <ctime>

struct Che
{
	string a;
	Che* next;
};


void stack(Che*** head, int* newmas)
{

	if (**head == NULL)
	{
		Che* b1;
		b1 = new Che();
		//b1 = **head;

		b1->a = *newmas;
		**head = b1;
		b1->next = NULL;

	}
	else
	{
		Che* b1 = **head;
		Che* k;
		k = new(Che);

		//Che* j = **head;

		while (b1->next != NULL)
		{
			b1 = b1->next;
			b1->next = new (Che);
			b1 = b1->next;
			b1->a = *newmas;
			b1->next = NULL;
		}
	}


}


void merge(Che** head, int last_size, int minrun, int raz_mas)
{
	//int* A;
	Che* m = *head; Che* m1 = *head; Che* m2 = m1->next; Che* m3 = *head;
	int* sliv_mas_1 = new int[raz_mas];
	int j;
	int* mas = new int[raz_mas];
	int n, n1(0);
	int kol_mas = (raz_mas / minrun);
	Che* c = *head;


	while (c->next != NULL)
	{
		if (kol_mas > 0) kol_mas = kol_mas;

		else
		{
			kol_mas = kol_mas / 2;
			if (n1 != 0)
			{
				last_size = n1;
				minrun = n;
			}
			else last_size = minrun = n;
		}


		while (m->next != NULL)
			m = m->next;
		while (m1->next->next != NULL)
			m1 = m1->next;
		while (m3->next->next->next != NULL)
			m3 = m3->next;

		if (last_size == minrun)
		{
			for (int i = 0; i < minrun; i++)
			{
				sliv_mas_1[i] = m->a[i];

			}

			n = minrun * 2;
			kol_mas = kol_mas - 2;

		}
		else
		{
			for (int i = 0; i < minrun; i++)
			{
				sliv_mas_1[i] = m->a[i];

			}

			n = minrun + last_size;
			n1 = minrun + last_size;
			kol_mas = kol_mas - 2;

		}

		int i(0), k = 0;
		for (j = 0; j < minrun + last_size; j++)
		{

			if (sliv_mas_1[i] < m1->a[k])
			{
				mas[j] = sliv_mas_1[i];
				i++;
			}
			else
				mas[j] = m1->a[k];
			k++;
		}
		m3->next = NULL;
		m->a = *mas;
		*head = m;
		m->next = m2;
	}


	//delete[] sliv_mas_1;
}




void sort(Che** head, int* minrun, int run[])
{
	int x, j;
	for (int i = 2; i < *minrun; i++)
	{
		x = run[i];
		j = i;
		while (j > 0 and run[j - 1] > x)
		{
			run[j] = run[j - 1];
			j = j - 1;
		}
		run[j] = x;
	}
	stack(&head, run);
}
int GetMinrun(int n)
{
	int r = 0;           /* станет 1 если среди сдвинутых битов будет хотя бы 1 ненулевой */
	while (n >= 64) {
		r |= n & 1;
		n >>= 1;
	}
	return n + r;
}

void delete_st(Che** head, int* A, int raz_mas)
{
	Che* b1 = *head;
	for (int i = 0; i < raz_mas; i++)
	{
		A[i] = b1->a[i];
	}
	delete b1;


}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, raz_mas, last_size, minrun;
	srand(time(NULL));
	Che* head = 0;
	cout << "Введите количечество элементов" << endl;
	cin >> n;
	raz_mas = n;
	//int l;
	cout << "Введите элементы " << endl;
	int* A = new int[n]; // Выделение памяти для массива
	for (int i = 0; i < n; i++)// Заполнение массива и вывод значений его элементов
	{
		//cin >> l;
		A[i] = rand() % 100;
		cout << A[i] << ' ';

	}
	minrun = GetMinrun(n);
	int j = 0;
	while (n > 0)
	{
		int* run = new int[minrun];
		for (int i = 0; i < minrun; i++)
		{
			run[i] = A[j];
			j++;
		}
		sort(&head, &minrun, run);
		j = j + minrun;

		if (n >= minrun)
		{
			n = n - minrun;
			last_size = minrun;
		}
		else
		{
			last_size = n;
			int* run = new int[minrun];
			for (int i = 0; i < minrun; i++)
			{
				run[i] = A[j];
				j++;
			}
			sort(&head, &last_size, run);
			n = 0;
		}
	}
	//cr_sliv_mas(last_size, minrun, raz_mas);
	merge(&head, last_size, minrun, raz_mas);

	delete_st(&head, A, raz_mas);
	cout << endl << "Массив" << endl;
	for (int i = 0; i < raz_mas; i++)
		cout << A[i] << ' ';
	delete[] A; // очистка памяти
}

