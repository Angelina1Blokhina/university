/*include <iostream>
using namespace std;
#define N 50
int main()
{
	int i, m[N]; // Объявляем целочисленную переменную и один массив.
	for (i = 0; i < N; i++)
	{
		cin >> m[i]; // Вводим с клавиатуры значение ячейки массива
	}

	for (i = 0; i < N; i++)
	{
		cout << m[i] << " "; // На экран через пробелы выводятся все элементы массива
	}

	system("pause");
}*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[5]; // объявлен массив a из 5 элементов
	int i;
	// Ввод элементов массива
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]); // &a[i] - адрес i-го элемента массива
	}
	// Вывод элементов массива
	for (i = 0; i < 5; i++)
		printf("%d ", a[i]); // пробел в формате печати обязателен
	getchar(); getchar();
	return 0;
}