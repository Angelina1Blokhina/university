#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>



#define V 12
#define S 12

void cl() 
{
	system("cls");
}
void save(int count, int sn,int m, int n, int a[12][12])
{
	FILE* ter;
	printf("\nВведите название файла ");
	char name[45];
	scanf_s("%s", name, 45);
	fopen_s(&ter, name, "wt");
	if (!ter) printf("ошибка");
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				fprintf(ter,"%5d ", a[i][j]);
			}
			fprintf(ter,"\n");
		}
	}
	fclose(ter);
	

}
void otk(int n, int m,int sn, int count) 
{
	char b[200];
	FILE*r;
	printf("Введите название файла ");
	char name[45];
	scanf_s("%s", name, 45);
	fopen_s(&r, name, "r");
	while(fgets(b,200,r))
	printf("%s", b);
	fclose(r);
}
int main()
{
	setlocale(LC_ALL, "ru");
	int m(0), n(0);
	int array[V][S];


	while (n < 1 || n > 12)
	{
		printf("Введите высоту (от 1 до 12): ");
		scanf_s("%d", &n);
		if (n < 1 || n > 12)
			printf("Ошибка! Введите целое число от 1 до 12!\n");
	}
	while (m < 1 || m > 12)
	{
		printf("Введите ширину (от 1 до 12): ");
		scanf_s("%d", &m);
		if (m < 1 || m > 12)
			printf("Ошибка! Введите целое число от 1 до 12!\n");
	}

	// sn pp
	// 1 1 снаружи по часовой
	// 1 2 снаружи против часовой
	// 2 1 изнутри по часовой
	// 2 2 изнутри против часовой

	int sn = 1, pp = 1, key = 1, ch = 0;

	while (1) {
		//system("cls"); // очистка консоли #include <stdlib.h>

		for (int i = 0; i < S; i++)
			for (int j = 0; j < V; j++)
				array[i][j] = 0;

		printf("Для построения спирали выберите нужные параметры\n");
		printf("Для управления используйте клавиши стрелок (вверх, вниз) или цифр (от 1 до 4)\n\n");
		printf("Для сохранения нажмите клавишу цифры 5 \n\n");

		printf("1) Снаружи, по часовой стрелке");
		if (key == 1) printf(" <--");
		printf("\n2) Снаружи, против часовой стрелки");
		if (key == 2) printf(" <--");
		printf("\n3) Изнутри, по часовой стрелке");
		if (key == 3) printf(" <--");
		printf("\n4) Изнутри, против часовой стрелки");
		if (key == 4) printf(" <--");
		printf("\n5) Сохранить");
		if (key == 5) printf(" <--");
		printf("\n6) Открыть");
		if (key == 6) printf(" <--");
		printf("\n\n");

		




		int w = m, h = n;
		int i = 0, j = 0, count = 1, dif_i = 1, dif_j = 1, len = w;

		if (sn != pp)
		{
			dif_j = -1;
			j = w - 1;
		}


		while (count != m * n + 1)  // построение спирали
		{
			if (sn == pp)
			{
				while (-1 < j && j < m && len > 0)
				{
					if (array[i][j] == 0)
					{
						array[i][j] = count++;
					}
					j += dif_j; len--;
				}
				dif_j *= -1; j += dif_j; len = h;

				while (-1 < i && i < n && len > 0)
				{
					if (array[i][j] == 0)
					{
						array[i][j] = count++;
					}
					i += dif_i; len--;
				}
				dif_i *= -1; i += dif_i; len = w;

				w--; h--;


			}
			else
			{
				//sn != pp (1 2; 2 1)
				while (-1 < j && j < m && len > 0)
				{
					if (array[i][j] == 0)
					{
						array[i][j] = count++;
					}
					j += dif_j; len--;
				}
				dif_j *= -1; j += dif_j; len = h;

				while (-1 < i && i < n && len > 0)
				{
					if (array[i][j] == 0)
					{
						array[i][j] = count++;
					}
					i += dif_i; len--;
				}
				dif_i *= -1; i += dif_i; len = w;

				w--; h--;
			}

		}



		// вывод
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (sn == 2)
				{
					array[i][j] = count - array[i][j];
				}
				printf("%6d ", array[i][j]);
			}
			printf("\n");
		}

		printf("\nДля выхода нажмите ESC");

		// 1 - 49
		// 2 - 50
		// 3 - 51
		// 4 - 52
		// H - 72
		// P - 80
		// ESC - 27
		// up - 224 72
		// down - 224 80

		int snt = 0;
		int ch = _getch(); // #include <conio.h>
		if (ch == 224)
		{
			ch = _getch();
			snt = 1;
		}

		// sn pp
		// 1 1 снаружи по часовой
		// 1 2 снаружи против часовой
		// 2 1 изнутри по часовой
		// 2 2 изнутри против часовой

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
			case 27:
				return 0;
		
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
			/*case '5':
				key = 5;
				break;
			case '6':
				key = 6;
				break;*/
			}

		switch (key) {
		case 1:
			cl();sn = 1; pp = 1; 
			break;
		case 2:
			cl(); sn = 1; pp = 2;
			break;
		case 3:
			cl(); sn = 2; pp = 1;
			break;
		case 4:
			cl(); sn = 2; pp = 2;
			break;
		
		case 5:
			save(count,sn,m,n,array);
			cl();
			break;
		case 6:
			cl();
			otk(n,m,sn,count);
			break;
		}
		
	}
	
	return 0;
}