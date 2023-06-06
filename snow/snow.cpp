#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
using namespace std;

const int width = 75;
const int height = 20;
char area[height][width], area2[width][height];
int wx, wallx, wally, l(0);
int x = 0, y = 0, step = 5;
char ch, mu;
int key(0), k(0),mx, my;

void Setup()
{if (l == 0) 
	
	{for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width - 1; j++)
			area[i][j] = ' ';

	}

int d(0), d1(0);
		l++;
		srand(time(NULL));
		while (d != 5)
		{
			wallx = 3+rand()%(width-1);
			wally =2+rand()%(height -1);
			area[wally][wallx] = '_';
			d++;

		}
		while (d1 != 4)
		{
			
			wallx = 3 + rand() % (width - 1);
			wally = 2 + rand() % (height - 1);
			area[wally][wallx] = '/';
			d1++;
		}
		
		
	}



}

void open()
{
	
	
	char b[200]; int g(0);
	FILE* r;
	printf("Введите название файла ");
	char name[45];
	scanf_s("%s", name, 45);
	fopen_s(&r, name, "r");
	
	
		for (int i = 0; i < height; i++)
		{
			g = 0;
			fgets(b, 75, r);
			for (int j = 0; j < width; j++)
			{
				if ((b[g] == '_') || (b[g] == '/'))
				{
					area[i][j] = b[g];
					b[g] = ' ';
					
				}
				else
					area[i][j] = ' ';
				g++;
			}
			cout << endl;
		}

	
		//printf("%s", b);
	fclose(r);
	
}
void save()
{
	char sa;
	FILE* ter;
	printf("\nВведите название файла ");
	char name[45];
	scanf_s("%s", name, 45);
	fopen_s(&ter, name, "wt");
	if (!ter) printf("ошибка");
	else
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				//sa = area[i][j];


				fprintf(ter, "%c ", area[i][j]);
			}
			fprintf(ter, "\n");
		}
	}
	fclose(ter);
}
void gotoXY(int x, int y)
{

	COORD c = { x+1,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	
}

void updatearea(int j, int i) 

{
	
	

	if (i < height-2)

		{
			gotoXY(j, y);
			cout << ' ';
			y++;
			gotoXY(j, y);
			cout << '*';
			Sleep(200);
		}
		if(i==height-2)
		{ 
			gotoXY(j, y);
			cout << ' ';
			y++;
			gotoXY(j, y);
			cout << '*';
			gotoXY(j, y);
			cout << ' ';
			//Check(j, y);
			/*if (area[y][j + 1] == '*')
				area[y-1][j 
				+ 1] = '*';
			else*/
				area[y][j+1] = '*';
			x = mx; y = 0;
			key = 0;
			step = 5;
		}	

}

void draw1()
{
	for (int i = 0; i < width; i++)
		cout << "^";
	cout << endl;
	for (int i = 0; i < height; i++)
	{

		for (int j = 0; j < width; j++)
		{
			if ((i == y) & (j == x+1))
				cout << "#";
			
			if (area[i][j] == '_')
				cout << '_';
			if (area[i][j] == '/')
				cout << '/';
			if (area[i][j] == ' ')
				cout << ' ';
			if (area[i][j+1] == '*')
				cout << '*';
		}
		cout << endl;
	}

	for (int i = 0; i < width; i++)
	{
		area[20][i] = '^'; cout << "^";
	}

	cout << endl;


}


void Ru()
{
	
	if (key == 3)
	{gotoXY(0, 2);


		for (int i = 0; i < height; i++)
		{

			for (int j = 0; j < width; j++)
			{
				if ((i == y ) & (j == x))
				{
					
					
						if (step == 5)
						{
							mx = j; my = i;
							y++;
							step--;
						}
							
						if (area[i + 1][j + 1] != '/')
						{
							if (area[i + 1][j + 1] == ' ')
							{
								if ((area[i + 1][j + 1] != '_') & (area[i + 1][j + 1] != '%'))
									updatearea(x, y);
								if ((area[i + 1][j + 1] == '%') & (area[i + 1][j + 2] == '*'))
								{
									gotoXY(j, y);
									cout << ' ';
									y++;
									y++;
									gotoXY(j, y);
									cout << '*';
									gotoXY(j, y);
									cout << ' ';
									area[i][j + 1] = '%';
									area[i][j + 2] = '*';
									x = mx; y = 0;
									key = 0;
									step = 5;
									gotoXY(mx, my);
								}
								if (area[i + 1][j + 1] == '_')
								{
									gotoXY(j, y);
									cout << ' ';
									y++;
									y++;
									gotoXY(j, y);
									cout << '*';
									/*gotoXY(j, y);
									cout << ' ';*/
									area[i][j + 1] = '%';
									area[i][j + 2] = '*';

									x = mx; y = 0;
									//i = 0, j = 0;
									key = 0;
									step = 5;
									gotoXY(mx, my);
								}



							}

							else
							{
								area[i][j + 1] = '*';
								x = mx; y = 0;
								//i = 0, j = 0;
								key = 0;

								step = 5;
								gotoXY(mx, my);

							}
						}
						else
						{
							
								gotoXY(x, y);
								cout << ' ';
								x--;
								updatearea(x, y);
							
						}
					

					
			

				}gotoXY(j - 1, i);

			}
			cout << endl;

			
		}

	}
	

}


void Input()
{
	
		
		switch (key)
		{
		case 1:
			key = 0;
			x++;
			break;
		case 2:
			key = 0;
			x--;
			break;
		case 4:
			save();
			break;
		//case 5:
			

		}
		if(_kbhit())
		{ 
			ch = _getch();
		
			switch (ch)
			{
			case 77:
				key = 1;
				break;

			case 75:
				key = 2; 
				break;
			case 13:
				key = 3;
				break;
			case'1':
				key = 4;
				break;
			}
		
		
		}

		

		
	}

void Check()
{
	mu = _getch();
	switch (mu) 
	{
		case 72:
			k--;
			if (k < 2) k = 1;
			break;
		case 80:
			k++;
			if (k > 2) k= 1;
			break;
	}
			
}

int main()
{
	setlocale(LC_ALL, "ru");
	
	while (mu!= 13)
	{
		system("cls");
		cout << "Выберете действие " << endl;
		
		cout<<endl << "Загрузить препятствия из файла ";
		if (k == 1) cout << "<---";
		
		cout <<endl<< "Случайное заполнение препятсвиями " ;
		if (k == 2) cout << "<---" ;
		cout << endl;
		Check();
		Sleep(500);
	}
		
		
		if (mu == 13 & k == 1)
		{
			
				open();
				
				while (1)
				{
					system("cls");
					draw1();
					Ru();
					cout << "Чтобы cохранить в файл, нажмите 1 ";
					if (key == 7) save();
					Input();
					Sleep(1000);
					
				}


		}
	
		
		if (mu== 13 & k == 2)
		{


		while (1) 
		{
		system("cls");
		Setup();
		draw1();
		Ru();
		cout << "Чтобы cохранить в файл, нажмите 1 ";
		if(key==7) save();
		Input();
		Sleep(1000);
		
		
		}
		}

	

	return 0;
}