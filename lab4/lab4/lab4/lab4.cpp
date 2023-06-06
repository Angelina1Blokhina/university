#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<stdio.h>
using namespace std;
 
int main()
{
	char a[45];
	cout << "Vvedite pervoe chislo:";
	cin >> a;
	char b[45];
	cout << "Vvedite vtoroe chislo:";
	cin >> b;

	int k, m(0);
	int c[2025];
	int schet1(0), schet2(0);
	int bn;

	for (int i = 0; a[i] != '\0'; ++i)
	{
		schet1++;
	}
	for (int i = 0; b[i] != '\0'; ++i)
	{
		schet2++;
	}
	if (schet1 == schet2)
	{

		for (int i = 0; a[i] != '\0'; ++i)
		{
			if (a[i] < b[i])
			{
				// "Вторая строка больше" 
				bn = 2;
				break;
			}
			if (a[i] > b[i])
			{
				//"Первая строка больше"
				bn = 3;
				break;
			}
			if (a[i] == b[i])
			{
				bn = 1;
			}
		}
	}
	
	/*
	int ret = -1, dop = 0, ol;
	if (schet1 == schet2)
	{
		for (int i = schet1 - 1; i >= 0; i--)
		{
			ret++;
			int j = schet2 - 1;
			j = j - ret;

			if (j >= 0)
			{
				if (dop == 0)
				{
					k = (a[i] - 48) + (b[j] - 48);
				}
				if (dop != 0)
				{
					k = (a[i] - 48) + (b[j] - 48) + 1;

					dop = 0;
				}

				if (k >= 10)
				{
					dop = k;
					ol = dop / 10;
					m = k - 10;
					c[i] = m;

				}
				else
					c[i] = k;
			}
			if (j < 0)
			{
				if (dop == 0)
				{
					c[i] = a[i] - 48;
				}
				if (dop != 0)
				{
					c[i] = (a[i] - 48) + 1;
					dop = 0;

				}


				if (c[i] >= 10)
				{
					dop = c[i];
					ol = dop / 10;
					m = c[i] - 10;
					c[i] = m;
				}

			}

		}
		int f[2026];
		if (ol == 1)
		{
			int kl = 0;

			for (int i = 0; i < schet1; ++i)
			{
				f[0] = 1;
				
				kl++;
				f[kl] = c[i];
			}

			for (int i = 0; i < schet1 + 1; i++)
				cout << f[i];


		}
		if (ol != 1)
		{
			for (int i = 0; i < schet1; i++)
			{
				cout << c[i];
			}
		}
	}
	
	if (schet1 > schet2)
	{
		for (int i = schet1 - 1; i >= 0; i--)
		{
			ret++;
			int j = schet2 - 1;
			j = j - ret;

			if (j >= 0)
			{
				if (dop == 0)
				{
					k = (a[i] - 48) + (b[j] - 48);
				}
				if (dop != 0)
				{
					k = (a[i] - 48) + (b[j] - 48) + 1;

					dop = 0;
				}

				if (k >= 10)
				{
					dop = k;
					//ol = dop / 10;
					m = k - 10;
					c[i] = m;

				}
				else
					c[i] = k;
			}
			if (j < 0)
			{
				if (dop == 0) 
				{
					c[i] = a[i] - 48; 
				}
				if (dop != 0)
				{
					c[i] = (a[i] - 48) + 1;
					dop = 0;

				}


				if (c[i] >= 10)
				{
					dop = c[i];
					//ol = dop / 10;
					m = c[i] - 10;
					c[i] = m;
				}
				
			}

		}
		
			for (int i = 0; i < schet1; i++)
			{
				cout << c[i];
			}
		
	}

	if (schet2 > schet1)
	{
		for (int i = schet2 - 1; i >= 0; i--)
		{
			ret++;
			int j = schet1 - 1;
			j = j - ret;

			if (j >= 0)
			{
				if (dop == 0)
				{
					k = (b[i] - 48) + (a[j] - 48);
				}
				if (dop != 0)
				{
					k = (b[i] - 48) + (a[j] - 48) + 1;
					dop = 0;
				}

				if (k >= 10)
				{
					dop = k;
					m = k - 10;
					c[i] = m;

				}
				else
					c[i] = k;
			}
			if (j < 0)
			{
				if (dop != 0)
					c[i] = (b[i] - 48) + 1;
				else
					c[i] = b[i] - 48;
			}

		}

		for (int i = 0; i < schet2; i++)
		{

			cout << c[i];
		}
	}
}*///summa

	int sum1(0), sum2(0), rt(0);

	int ger = -1, hi = 0, qu, l;
/*
if (schet1>schet2 or bn==3 or bn==1)
{
	for (int i = schet1-1; i >= 0; i--)
	{
		ger++;
		int j = schet2 - 1;
		j = j - ger;
		if (j >= 0)
		{
			if (a[i] >= b[j])
			{

				qu = (a[i] - 48) - (b[j] - 48) - hi;
				hi = 0;

			}
			if (b[j] > a[i])
			{
				qu = (a[i] - 38) - (b[j] - 48) - hi;
				hi = 1;

			}
		}
		if (j < 0) 
		{
			qu = a[i] - 48 - hi;
			hi = 0;
		}
		c[i] = qu;

	}
	for (int i = 0; i < schet1; i++)

	{
		cout << c[i];
	}
}
if (schet2 > schet1 or bn==2) 
{
	for (int i = schet2 - 1; i >= 0; i--)
	{
		ger++;
		int j = schet1 - 1;
		j = j - ger;
		if(j>=0)
		{
			if (a[j] >b[i]) 
			{
				qu = (b[i] - 38) - (a[j] - 48) - hi;
				hi = 1;
			}	
			if (b[i] >= a[j])
			{
				qu =( b[i] - 48) - (a[j] - 48) - hi;
				hi = 0;
			}
		}
		if (j < 0) 
		{
			qu = b[i] - 48 - hi;
			hi = 0;
		}
		c[i] = qu;
	}
	cout << '-';
	for (int i = 0; i < schet2; i++)
	{
		cout << c[i];
	}
}
*/
	int wa, lp(0);
for (int i = schet1 - 1; i >= 0; --i)
{
	while(i!=0)
	{
		wa = (a[i]-48)* (b[]-48)+lp;
		if (wa >= 10) 
		{
			lp = wa / 10;

		}
		c[i] = wa;
	}
	for (int i = 0; i < schet1; i++)

	{
		cout << c[i];
	}

}




}


















	
/*const int size = 45;
	int* pos1;
	int* pos2;
	pos1 = new int[size];
	pos2 = new int[size];
	int p[size];
	 


	for (int i = 0; i < size; i++)
		cin >> pos1[i];
	cout << endl;
	for (int i = 0; i < size; i++)
		cin >> pos2[i];

	while (ch != 27)
	{

		system("cls"); // очистка консоли #include <stdlib.h>

		printf("Выберите математическую операцию");
		printf("\nДля управления используйте клавиши стрелок (вверх, вниз) или цифр (от 1 до 4)\n\n");

		printf("1)Сложение");
		if (key == 1) printf(" <--");
		printf("\n2) Вычитание");
		if (key == 2) printf(" <--");
		printf("\n3) Умножение");
		if (key == 3) printf(" <--");
		printf("\n4) Деление");
		if (key == 4) printf(" <--");
		printf("\n\n");

		switch (key)
		{
		case 1:
			 for (int i = 0; i < sizeof pos1 / sizeof pos1[0]; i++)
				p[i] = pos1[i] + pos2[i];;
			break;
		case 2:
			cout << pos1 - pos2;
			break;
		/*case 3:
			cout << pos1 * pos2;
			break;
		case 4:
			cout << (float)pos1 / pos2;
			break;
		}

		printf("\nДля выхода нажмите ESC");
		int snt = 0, sign = 0;
		ch = 0;
		do
		{
			ch = _getch();// #include <conio.h>
			sign = 1;
			if (ch == 224)
			{
				ch = _getch();
				snt = 1;
			}
			if (snt) // одно считывание
				switch (ch)
				{
				case 72:
					key--;
					if (key < 1) key = 4;
					break;
				case 80:
					key++;
					if (key > 4) key = 1;
					break;
				default:
					sign = 0;
					break;
				}
			else
			{
				switch (ch)
				{
				case 27:
					break;
				case '1':
					key = 1;
					break;
				case '2':
					key = 2;
					break;
				case '3':
					key = 3;
					break;
				case '4':
					key = 4;
					break;
				default:
					sign = 0;
					break;
				}
			}
		} while (sign != 1);
	}
}*/



