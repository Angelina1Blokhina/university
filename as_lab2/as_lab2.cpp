
using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <math.h>

struct Che
{
	int *a;
	Che* next;
};


void stack( Che*** head,int *newmas)
{
	
	if (**head == NULL)
	{
		Che* b1;
		b1 = new Che();
		b1->a = newmas;
		**head = b1;
		b1->next = NULL;

	}
	else
	{
		Che* b1 = **head;
		
		
		while (b1->next!= NULL)
			b1 = b1->next;	
		b1->next = new (Che);
		b1 = b1->next;
		b1->a = newmas;
		b1->next = NULL;
	}
		
	
}


void merge(Che** head,int last_size,int minrun, int raz_mas)
{
	Che* m = *head; Che* m1 = *head; Che* m2 =*head; 
	int i(0), k = 0;
	Che* m3 = *head;
	int* sliv_mas_1 = new int[raz_mas];
	
	int sliv_mas_2[3000];
	int j;
	int *mas = new int[raz_mas];

	int n1(0); int kol_mas, kol_mas2;
	int prisv_next(0);

	bool prov, chet(1), vhod(0);

	int last_size_time = last_size;
	kol_mas =raz_mas / minrun;
	if (kol_mas % 2 != 0)kol_mas++;
	
	kol_mas2 = kol_mas/2;
	if (kol_mas2 % 2 != 0) kol_mas2++;

	
	while( vhod!=1 & (kol_mas > 1) & (minrun+last_size<=raz_mas))
	{
		prov = 0;
		if (chet==0) last_size=minrun;
		
		if (kol_mas2!= kol_mas) kol_mas = kol_mas;
		else
		{
			last_size_time = last_size_time + minrun;
			kol_mas2 = kol_mas2 / 2;
			if (kol_mas2 % 2 != 0) kol_mas2++;
			chet = 1;
			/*if (last_size == minrun)
			{
				last_size = minrun * 2;
				minrun = last_size;
			}
			else*/
			
				last_size = last_size_time;
				minrun = minrun*2;
			

		}
		kol_mas--;

		if (minrun + last_size == raz_mas) vhod++;
		while (m->next != NULL)
		{
			m = m->next;
			if (prov == 0) prov = 1;
			else m1 = m1->next;
			
		}
		prov = 0;
		

		if (last_size == minrun)
		{
			for (int i = 0; i < minrun; i++)
			{
				sliv_mas_1[i] = m->a[i];

			}

		

		}
		else
		{
			for (int i = 0; i < last_size; i++)
			{
				sliv_mas_1[i] = m->a[i];

			}
		
		}

		
		i = 0; k = 0;
		for (j = 0; i < last_size and k < minrun; j++)
		{


			if (sliv_mas_1[i] < m1->a[k])
			{
				mas[j] = sliv_mas_1[i];
				sliv_mas_2[j]= sliv_mas_1[i];
				i++;
			}
			else
			{
				if (sliv_mas_1[i] > m1->a[k])
				{
					mas[j] = m1->a[k];
					sliv_mas_2[j] = m1->a[k];
					k++;
				}
				else
				{
					mas[j] = m1->a[k];
					sliv_mas_2[j] = m1->a[k];
					j++;
					mas[j] = sliv_mas_1[i];
					sliv_mas_2[j] = sliv_mas_1[i];
					
					i++;
					k++;

				}
			}
		}

		if (i == last_size)
		{
			while (k < minrun)
			{
			mas[j] = m1->a[k];
			sliv_mas_2[j] = m1->a[k];
			j++;
			k++;
			}
			
		}
		else
		{
			while (i < last_size)
			{
				mas[j] = sliv_mas_1[i];
				sliv_mas_2[j] = sliv_mas_1[i];
				j++;
				i++;
			}
		}
		m1 = new Che();
		m1->a = mas;
		m1->next = *head;
		*head=m1;
		while (prisv_next != 2)
		{
			if (m3->next != NULL) 
			{
				while (m3->next != NULL)
			{	
				m3 = m3->next;
				if (prov == 0)prov = 1;
				else m2 = m2->next;
			}delete m3;
			
				if (prov == 1) m2->next = NULL;
				else m2 = NULL;
			}
			
			
			

			
			
			m3 = *head;
			m2 = *head;
			prov = 0;
			prisv_next++;
		}
		prisv_next = 0;

		m1 = *head;
		m = *head;
		chet = 0;
		mas = new int[raz_mas];
		
		//m3= NULL;
		
	}

	if (m->next != NULL)
	{
		m = m->next;
		for (int i = 0; i < last_size; i++)
		{
			sliv_mas_1[i] = m->a[i];

		}
		i = 0; k = 0;
		for (j = 0; i < last_size and k < minrun; j++)
		{


			if (sliv_mas_1[i] < m1->a[k])
			{
				mas[j] = sliv_mas_1[i];
				sliv_mas_2[j] = sliv_mas_1[i];
				i++;
			}
			else
			{
				if (sliv_mas_1[i] > m1->a[k])
				{
					mas[j] = m1->a[k];
					sliv_mas_2[j] = m1->a[k];
					k++;
				}
				else
				{
					mas[j] = m1->a[k];
					sliv_mas_2[j] = m1->a[k];
					j++;
					mas[j] = sliv_mas_1[i];
					sliv_mas_2[j] = sliv_mas_1[i];

					i++;
					k++;

				}
			}
		}

		if (i == last_size)
		{
			while (k < minrun)
			{
				mas[j] = m1->a[k];
				sliv_mas_2[j] = m1->a[k];
				j++;
				k++;
			}

		}
		else
		{
			while (i < last_size)
			{
				mas[j] = sliv_mas_1[i];
				sliv_mas_2[j] = sliv_mas_1[i];
				j++;
				i++;
			}
		}
		m1 = new Che();
		m1->a = mas;
		delete m;
		m1->next = NULL;
		*head = m1;
	

	}
	
	//delete[] sliv_mas_1;
	}




void sort(Che **head,int *minrun, int run[])
{
	int x, j;
	for (int i =1; i < *minrun; i++)
	{
		x = run[i];
		j = i-1;
		while (j >=0 and run[j] > x)
		{
			run[j+1] = run[j];
			j--;
		}
		run[j+1] = x;
	}	
	stack(&head,run);
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

void delete_st(Che **head,int raz_mas)
{
	Che *b1 = *head;
	for (int i = 0; i < raz_mas; i++)
	{
		cout<< b1->a[i]<<" ";
	}
	delete b1;
	

}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, raz_mas,last_size, minrun;
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
		A[i] =rand() % 100; 
		cout << A[i] << ' ';

	}
	minrun = GetMinrun(n);
	int j=0;
	while (n > 0)
	{	
		
		
		
		if (n >= minrun)
		{int* run = new int[minrun];
		for (int i = 0; i < minrun; i++)
		{
			run[i] = A[j];
			j++;
		}
		sort(&head,&minrun,run);
		//j = j+minrun;
			n = n - minrun;
			last_size = minrun;
		}
		else
		{
			last_size = n;
			int* run = new int[last_size];
			for (int i = 0; i <last_size; i++)
			{
				run[i] = A[j];
				j++;
			}
			sort(&head,&last_size, run);
			n = 0;
		}
	}
	
	merge(&head,last_size, minrun, raz_mas);
	cout << endl << "Массив" << endl;
	delete_st(&head, raz_mas);
	
	
	
	//for (int i = 0; i < raz_mas; i++)
		//cout << A[i] << ' ';
	delete[] A; // очистка памяти
}

