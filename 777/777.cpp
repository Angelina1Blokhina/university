// 777.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;


int main()
{
	char c[10][15];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			
			c[i - 1][0] = '0';
			cout << c[i - 1][0] << endl;
			c[i - 1][0] = '4';
			cout << c[i - 1][0] << endl;
				

		}
	}
	
}