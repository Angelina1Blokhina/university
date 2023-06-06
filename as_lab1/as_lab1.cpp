using namespace std;
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>


int main()

{
		setlocale(LC_ALL, "Russian");
		int n;
		cout << "Введите количечество элементов" << endl;
		cin >> n;
		int l;
		cout << "Введите элементы " << endl;
		int* p_darr = new int[n]; // Выделение памяти для массива
		for (int i = 0; i < n; i++)// Заполнение массива и вывод значений его элементов
		{
			cin >> l;
			p_darr[i] = l;
			
		}

		cout << endl << "Массив" << endl;
		for(int i = 0; i < n; i++)
			cout << p_darr[i]<<' ';
		delete[] p_darr; // очистка памяти
		
		
}





