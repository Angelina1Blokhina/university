#include <iostream>
#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>
using namespace std;

void razmer(char *a, char b[25])
{
	int k = 0;
	int m = 0;
	for (int i = 0;a[i] != '\0'; ++i)
	{
		k++;
	}
	cout << "Размер первой строки:" << k << endl;
	for (int i = 0; b[i] != '\0'; ++i)
	{
		m++;
	}
	cout << "Размер второй строки:" << m << endl;

}

void srav(char a[51], char b[25])
{    
	int bn = 0;
	int p = 0;
	for (int i = 0; a[i] != '\0'; ++i)
	{   
		if (97 < a[i] < 122 and 97 < b[i] < 122 )
		{
			if (a[i] < b[i])
			{
				cout << "Вторая строка больше" << endl;
				bn = 0;
				break;
			}
			if (a[i] > b[i])
			{
				cout << "Первая строка больше" << endl;
				bn = 0;
				break;
			}
			if (a[i] == b[i])
			{
				bn = 1;
			}
	
		}
		
	}
	if (bn==1)
		cout << "Равны" << endl;

}
void skl1(char a[51], char b[25])
{
	char c[100];
	int l = 0;
	for (int i = 0; a[i] != '\0'; ++i)
	{
		c[i] = a[i];
		l = l + 1;
	}
	int g = 0;
	int my=0;
	for (int i = l; b[g] != '\0'; ++i)
	{
		my = i;
		c[i] = b[g];
		g++;
	}
	my++;
	c[my] = '\0';
	cout << c << endl;
}
/*void skl2(char a[51], char b[25])
{
	int z = 0;
	char me[51];
for (int i = 0; a[i] != '\0'; ++i)
{
	z++;
}
int q = -1;

for (int i = z; b[q] != '\0'; ++i)
{
	q = q + 1;
	a[i] = b[q];
	

}cout << a;
}
	


}*/

int main()
{
	setlocale(LC_ALL, "Russian");
	char a[51];
	cout << "Введите первую строку:";
	cin >> a;
	

	char b[25];
	cout << "Введите вторую строку:";
	cin >> b;
	

	/*razmer(a, b);
	srav(a, b);
	skl1(a, b);
	skl2(a, b);*/
	int key = 1; int ch = 0;
	while (1) {
		system("cls");
		

		printf("Размер строк");
		if (key == 1) printf(" <--");
		printf("\nСравнение строк");
		if (key == 2) printf(" <--");
		printf("\nСоединение строк 1");
		if (key == 3) printf(" <--");
		printf("\nСоединение строк 2");
		if (key == 4) printf(" <--");
		printf("\n\n"); 

switch (key) {
		case 1:
			razmer(a, b);
			break;
		case 2:
			srav(a, b);
			break;
		case 3:
			skl1(a, b);
			break;
		/*case 4:
			skl2(a, b);
			break;*/
		}

		int snt = 0;
		int ch = _getch(); // #include <conio.h>
		if (ch == 224)
		{
			ch = _getch();
			snt = 1;
		}

		
		if (snt == 0) // одно считывание
			switch (ch)
			{
			case 27:
				return 0;
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
			}
		else  // snt = 1 два считывания
			switch (ch) {
			case 72:
				key--;
				if (key < 1) key = 4;
				break;
			case 80:
				key++;
				if (key > 4) key = 1;
				break;
			}

		
		
	}

	return(0);
}


