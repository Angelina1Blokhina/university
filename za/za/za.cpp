#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;/*
void UU(int *m, int n)
{
	for (int i = 0; i < n; ++i)
		cin >> m[i];

}
void WW(int R[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << R[i] << "";
	cout << endl;
}
int main()
{
	const int n = 3;
	int A[n];
	UU(A, n);
	WW(A, n);
	return 0;

}*/
/*void R(int& n, int&k )
{
	FILE* u;
	FILE* ter;
	fopen_s(&u, "wot.txt", "r");
	if (fopen_s(&u, "wot.txt", "r")!=NULL)
		printf("Oops");
	else
	{
		fscanf_s(u, "%d", &k);
		k = k + n;
		printf_s("%d", k);
	}
	fclose(u);

	fopen_s(&ter, "lol.txt", "w");
	if (fopen_s(&ter, "lol.txt", "w") == NULL)
		printf("Oops");
	else
	{
		fwrite(&k, sizeof(k),1, ter);

	}
	fclose(ter);
	


int main()
{
	int a;
	int b[10];
	//scanf_s("%d",&a);
	//R(a, b);
	FILE* rr;
	fopen_s(&rr, "lol.txt", "w");
	if (fopen_s(&rr, "lol.txt", "w") == NULL)
		printf("Oops");
	else
		fwrite(&b, sizeof(b), 1, rr);
	fclose(rr);
	printf_s("%d", b);
	return 0;
*/
int main()
{
	setlocale(LC_ALL, "rus");
	FILE * ter;
	int b[10];
	for (int i = 0; i < 10; i++)
	{
		b[i] = 5;
	}
	
	fopen_s(&ter, "lol.txt", "wt");
	if (!ter) cout << "ошибка";
	else 
	{
		cout << "открыт\n";
		fwrite(b, sizeof(int)*10, 6, ter);
	}
	fclose(ter);
	fopen_s(&ter, "lol.txt", "rt");
	int a = fread(b, sizeof(int)*10, 3, ter);
	cout << a;
	for (int i = 0; i < 10; i++)
	{
		cout << b[i];

	}
	fclose(ter);
	return 0;

}
	