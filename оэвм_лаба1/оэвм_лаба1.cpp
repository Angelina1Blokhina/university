#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void cursor() {
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

union MyDouble {       
	double b;
	char a[sizeof(b)];

};

void conv_double(MyDouble md) {        //функция перевода типа double в двочное представление
	unsigned char help;
	unsigned int kk[8];
	for (int i = sizeof(md) - 1; i >= 0; --i)  //i равно количеству бит размера переменной md - 1 пока i больше либо равно нулю --i
	{
		help = md.a[i];         
		for (int j = 0; j < 8; ++j) //цикл для заполнения массива
		{
			kk[j] = (help & 1); //элемент массива = первому биту исходного числа
			help >>= 1; //сдвигаем на бит

		}
		for (int j = 7; j >= 0; --j)
		{
			cout << kk[j]; //переворачиваем внутри байта 
		}

		cout << " ";
	}
	cout << endl;
}


void change_intbits(unsigned int var) {

	unsigned int lsb, amount;
	cout << "Enter LSB" << endl;
	cin >> lsb;
	cout << "Enter amount of bits" << endl;
	cin >> amount;
	unsigned int a, x = 16;
	unsigned int kk[17];
	int i = 0;
	for (a = pow(2, 16); a != 0; a = a >> 1)
	{
		kk[i] = (var & a) >> (x--); //по аналогии с conv_int, только биты заносятся в массив
		i++;
	}
	cout << endl;
	amount = lsb + amount;
	cout << "Conversion result: " << endl;
	for (i = 0; i <= 16; i++) {
		if (i == 17 - amount) { //если номер массива равен lsb
			while (i <= 16 - lsb) //пока номер массива меньше или равен сумме наим бита и количества
			{
				if (kk[i] == 0) kk[i] = 1; //если элемент равен 0 то меняется на 1 иначе на 0
				else kk[i] = 0;
				cout << kk[i]; 
				i++;
			}
		}
		if (i != 17) 
			cout << kk[i];
	}
	cout << endl;
}
void change_doublebits(MyDouble md) {

	unsigned int lsb, amount;
	cout << "Enter LSB" << endl;
	cin >> lsb;
	cout << "Enter amount of bits" << endl;
	cin >> amount;
	unsigned char help;
	unsigned char hh[64];
	unsigned int kk[8];
	int k = 0;
	for (int i = sizeof(md) - 1; i >= 0; --i)
	{
		help = md.a[i];
		for (int j = 0; j < 8; ++j)
		{
			kk[j] = (help & 1);       
			help >>= 1;

		}
		for (int j = 7; j >= 0; j--)
		{
			hh[k] = kk[j];
			k++;
		}

		cout << " "; //в этом цикле по аналогии с функцией перевода только биты заносятся в массив hh
	}


	amount = lsb + amount;
	cout << "Conversion result: " << endl;
	for (int i = 0; i < 64; i++) {
		if (i == 64 - amount) {
			while (i <= 63 - lsb)
			{
				if (hh[i] == 1) hh[i] = 0;
				else hh[i] = 1;
				printf("%d", hh[i]);
				i++;
			}
		}
		if (i != 64)
			printf("%d", hh[i]);
	}
	cout << endl;
}

void input_int(unsigned int* var)
{
	cout << "Enter unsigned integer" << endl;
	cin >> *var;
}

void input_double(double* var)
{
	cout << "Enter double" << endl;
	cin >> *var;
}

void conv_int(unsigned int var) {
	unsigned int a, x = 16;
	for (a = pow(2, 16); a != 0; a = a >> 1) //a=2^16 пока а не равно 0 сдвигаем на 1 бит, т.е изначально число 10000000000....
		cout << ((var & a) >> (x--)); //выводим результат лог сложение исходной пер с а и сдвигаем на x-- бит
	cout << endl;
}

int main()
{
	cursor();
	int level = 1;
	int code;
	do {
		system("cls");

		cout << "Choose data type:";

		cout << "\n 1. Unsigned integer  ";
		if (level == 1)
			cout << "<--";

		cout << "\n 2. Double ";
		if (level == 2)
			cout << "<--";

		code = _getch();
		if (code == 224)
			code = _getch();

		if (code == 72 && level > 1)
			level--;
		if (code == 80 && level < 2)
			level++;
		if (code == 13 && level == 1)
		{
			do {
				system("cls");
				unsigned int var1;
				input_int(&var1);
				conv_int(var1);
				cout << endl << endl;
				cout << "Press F to change status of bits" << endl;
				cout << "Press ESC to return" << endl;
				code = _getch();
				if (code == 102) {
					do {
						change_intbits(var1);
						code = _getch();
					} while (code != 27);
				}
			} while (code != 27);

			code = 0;
			level = 1;


		}
		if (code == 13 && level == 2)
		{
			do {
				system("cls");
				MyDouble md;
				double var2;
				input_double(&var2);
				md.b = var2;
				conv_double(md);

				cout << "Press F to change status of bits" << endl;
				cout << "Press ESC to return" << endl;
				code = _getch();
				if (code == 102) {
					do {
						change_doublebits(md);
						code = _getch();
					} while (code != 27);

				}

			} while (code != 27);

			code = 0;
			level = 1;
		}
	} while (code != 27);
	return 0;

}