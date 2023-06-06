// mnogochlen.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include<limits>
using namespace std;
void TRANS(char* mas, int number)// number - позиция последего элемента
{
	int j; char buf;
	j = number;
	for (int i = 0; j - i >= 1; i++)
	{
		buf = mas[i];
		mas[i] = mas[j];
		mas[j] = buf;
		j--;
	}
}
int COM_NN_D(char* a, char* b)
{
	const int maxsize = 100;
	int lena;  //создаём целочисленный массив чтобы преобразовать в нём числовые символы к чилсам
	lena = strlen(a);
	int x[maxsize] = { 0 };
	for (int i = 0; i < lena; i++)
		x[i] = int(a[i]) - 48;
	int m(0);

	int lenb;  //создаём целочисленный массив чтобы преобразовать в нём числовые символы к чилсам
	lenb = strlen(b);
	int y[maxsize] = { 0 };
	for (int i = 0; i < lenb; i++)
		y[i] = int(b[i]) - 48;


	if (lena > lenb)
		m = 2;
	if (lena < lenb)
		m = 1;
	if (lena == lenb)
	{
		int i(0);
		while (m == 0 && i <= lena)//проверяем, какое число больше при равной длине
		{
			if (x[i] > y[i])
			{
				m = 2;//первое число больше
				break;
			}
			if (x[i] < y[i])
			{
				m = 1;//второе число больше
				break;
			}
			if (x[i] == y[i])
				m = 0;//одинаковые
			i++;

		}
	}
	return m;

}
void ADD_NN_N(char* a, char* b, char* ans)
{
	const int maxsize = 100;
	int maxx = 0;


	int lena;  //создаём целочисленный массив чтобы преобразовать в нём числовые символы к чилсам
	lena = strlen(a);
	int x[maxsize] = { 0 };
	for (int i = 0; i < lena; i++)
		x[lena - i] = int(a[i]) - 48;

	int lenb;  //создаём целочисленный массив чтобы преобразовать в нём числовые символы к чилсам
	lenb = strlen(b); int c = 0;
	int y[maxsize] = { 0 };
	for (int i = 0; i < lenb; i++)
		y[lenb - i] = int(b[i]) - 48;
	if (lena > lenb)
		maxx = lena;
	else
		maxx = lenb;

	if (COM_NN_D(a, b) == 1) {  //если второе число больше первого, меняем их местами
		for (int i = 1; i <= maxx; ++i) {
			int k = x[i];
			x[i] = y[i];
			y[i] = k;
		}

	}

	int f(0), sch(1);

	for (int i = 1; i <= maxx; ++i)  //выполняем операцию сложения 
	{
		if (sch == 1)
		{
			f = f + x[i] + y[i];
			ans[i] = f % 10;
		}

		if (f <= 9)
			f = 0;
		else
		{
			f = f / 10;
			if (i == maxx && sch == 1)
			{
				ans[i + 1] = 1;
				maxx++;
				sch = 0;
			}

		}

	}


	while (ans[maxx] == 0 && maxx > 1)
		maxx--;
	TRANS(ans, maxx);
	for (int i = 0; i < maxx; i++) ans[i] += 48;
	ans[maxx] = '\0';


}
int amount(char* mas)
{
	int sum(0);
	while (mas[sum] != '\0')
	{
		sum++;
	}

	return sum;
}
void SUB_NN_N(char* a, char* b, char* res)//////вычитание из 1 массиво второго
{
	int size, size_ans(0), am_1, am_2;
	am_1 = amount(a);
	am_2 = amount(b);

	TRANS(a, am_1 - 1);
	TRANS(b, am_2 - 1);
	int first[45] = { 0 }, second[45] = { 0 };
	int resault[45] = { 0 };
	for (int i = 0; i < am_1; i++) first[i] = a[i] - 48;
	for (int i = 0; i < am_2; i++) second[i] = b[i] - 48;
	size = am_1;
	int i, buf;
	for (i = 0; i < size; i++)
	{
		buf = i;
		if (first[i] >= second[i])
		{
			resault[i] = first[i] - second[i];
		}

		else
		{
			if (first[i + 1] == 0)
			{
				first[i] = first[i] + 10;
				resault[i] = first[i] - second[i];
				i++;
				while (first[i] == 0)
				{
					first[i] = 9; i++;
				}
				first[i] = first[i] - 1;
				i = buf;
			}
			else
			{
				first[i] = first[i] + 10;
				resault[i] = first[i] - second[i];
				i++;
				first[i]--;
				i = buf;
			}
		}
	}

	TRANS(a, am_1 - 1);
	TRANS(b, am_2 - 1);
	while (resault[size - 1] == 0 && size > 1) size--;
	for (int i = 0; i < size; i++) res[i] = resault[i] + 48;
	TRANS(res, size - 1);
	res[size] = '\0';
}
void DIV_NN_N(char* mas_1, char* mas_2, char* mas_3)
{
	int com, am_1, am_2, am_a, am_b, am_c, am_e, am_d, i(0), cou(0);
	for (int i = 0; i < 45; i++) mas_3[i] = '0';
	am_1 = amount(mas_1);
	am_2 = amount(mas_2);
	com = COM_NN_D(mas_1, mas_2);
	TRANS(mas_1, am_1 - 1);
	TRANS(mas_2, am_2 - 1);
	if (com == 1) mas_3[i] = 0;
	else
	{
		char a[45], b[45], c[45], d[45], e[45];

		for (i = 0; i < 45; i++)
		{
			a[i] = '0';
			b[i] = '0';
			c[i] = '0';
			d[i] = '0';
			e[i] = '0';
		}
		int k_1, k_2;
		k_2 = am_1 - am_2; k_1 = am_1 - 1;
		for (i = am_2 - 1; i >= 0; i--)
		{
			b[i] = mas_2[i];
			a[i] = mas_1[k_1];
			k_1--;

		}
		am_b = am_2;
		am_a = am_1 - 1;
		a[am_2] = '\0';
		b[am_2] = '\0';

		int comp, index(0), prop(0);
		do
		{
			cou = 0;
			am_a = amount(a);
			TRANS(a, am_a - 1);
			TRANS(b, am_b - 1);
			comp = COM_NN_D(a, b);
			TRANS(a, am_a - 1);
			TRANS(b, am_b - 1);
			while (comp == 1)
			{
				int am_a = amount(a);
				if (am_a == 0) am_a = 1;
				if (k_2 == 0)
				{
					prop = 1; break;
				}

				for (i = am_a - 1; i >= 0; i--) a[i + 1] = a[i];
				a[am_a + 1] = '\0';
				if (a[am_a] == '0') a[am_a] = '\0';
				k_2--;
				a[0] = mas_1[k_2];
				cou++;
				am_a = amount(a);
				TRANS(a, am_a - 1);
				TRANS(b, am_b - 1);
				comp = COM_NN_D(a, b);
				TRANS(a, am_a - 1);
				TRANS(b, am_b - 1);
			}


			if (cou > 1) index = index + cou - 1;
			if (prop != 1)
			{
				int dig(0), k;
				c[am_b] = '\0';
				do
				{
					am_c = amount(c);
					am_b = amount(b);
					TRANS(c, am_c - 1);
					TRANS(b, am_b - 1);
					ADD_NN_N(c, b, e);
					am_e = amount(e);
					TRANS(e, am_e - 1);
					TRANS(b, am_b - 1);

					for (i = 0; i < am_e; i++)
					{
						c[i] = e[i]; e[i] = '0';
					}
					c[am_e] = '\0';
					dig++;
					am_a = amount(a);
					am_c = amount(c);
					TRANS(a, am_a - 1);
					TRANS(c, am_e - 1);
					k = COM_NN_D(a, c);
					TRANS(a, am_a - 1);
					TRANS(c, am_c - 1);

				} while (k != 1);
				dig--;
				am_c = amount(c);
				TRANS(c, am_c - 1);
				TRANS(b, am_b - 1);
				SUB_NN_N(c, b, e);

				TRANS(c, am_c - 1);
				TRANS(b, am_b - 1);
				mas_3[index] = dig + 48;
			}
			else mas_3[index] = '0';

			TRANS(a, am_a - 1);
			if (prop == 1) e[1] = '\0';
			SUB_NN_N(a, e, d);
			am_a = amount(a);
			am_d = amount(d);
			TRANS(a, am_a - 1);
			TRANS(e, am_e - 1);
			TRANS(d, am_d - 1);
			for (i = 0; i < am_a; i++) a[i] = '0';
			for (i = 0; i < am_d; i++) a[i] = d[i];
			am_a = am_d;
			a[am_a] = '\0';
			for (i = 0; i < 45; i++)
			{
				c[i] = '0'; e[i] = '0'; d[i] = '0';
			}
			index++;
		} while (k_2 != 0);

		mas_3[index] = '\0';
	}
	TRANS(mas_1, am_1 - 1);
	TRANS(mas_2, am_2 - 1);
}
int POZ_Z_D(bool b, char A[]) {

	int count_1 = 0, count_2(0);
	for (int i = 0; A[i] != '\0'; i++)
	{
		if (A[i] == '0') count_1++;
		count_2++;
	}
	if (count_1 == count_2)
	{
		return 0;
	}
	else if (b == 0) {
		return 2;
	}
	else {
		return 1;
	}
}
void DIV_ZZ_Z(char* mas_1, int sign_m1, char* mas_2, int sign_m2, char* mas_3, bool* sign_m3)
{
	DIV_NN_N(mas_1, mas_2, mas_3);
	if ((sign_m1 == 1 && sign_m2 == 1) || (sign_m1 != 1 && sign_m2 != 1)) *sign_m3 = false;
	else *sign_m3 = true;
}
void MUL_NN_N(char* a, char* b, char* ans)
{
	int mas_1[45] = { 0 }, mas_2[45] = { 0 };
	int mas_3[90] = { 0 };

	int cols_1 = amount(a);
	int cols_2 = amount(b);
	TRANS(a, cols_1 - 1);
	TRANS(b, cols_2 - 1);
	for (int i = 0; i < cols_1; i++) mas_1[i] = a[i] - 48;
	for (int i = 0; i < cols_2; i++) mas_2[i] = b[i] - 48;

	int size_ans(0), buf1, i, j, buf;
	for (i = 0; i < cols_2; i++)
	{
		size_ans = i;
		for (j = 0; j < cols_1; j++)
		{
			mas_3[size_ans] = mas_1[j] * mas_2[i] + mas_3[size_ans];
			if (mas_3[size_ans] >= 10)
			{
				buf1 = size_ans;
				while (mas_3[size_ans] >= 10)
				{
					buf = mas_3[size_ans] / 10;
					mas_3[size_ans] = mas_3[size_ans] - (buf * 10);
					size_ans++;
					mas_3[size_ans] = mas_3[size_ans] + buf;

				}
				size_ans = buf1; size_ans++;
			}
			else size_ans++;
		}
	}

	if (mas_3[cols_1 + cols_2 - 1] != 0) size_ans++;
	for (int i = 0; i < size_ans; i++) ans[i] = mas_3[i] + 48;

	ans[size_ans] = '\0';
	TRANS(ans, size_ans - 1);
	TRANS(a, cols_1 - 1);
	TRANS(b, cols_2 - 1);

}
int NZER_N_B(char* a)//в меню надо сделать выбор, какое число проверять на ноль 
{
	int k = 0;
	bool m;
	for (int i = 0; a[i] != '\0'; ++i)
	{
		if (a[i] - 48 != 0)
			k++;
	}
	if (k == 0) m = 0;
	else m = 1;
	return m;
}
void MOD_NN_N(char* mas_1, char* mas_2, char* answer)
{
	char mas_3[45];
	DIV_NN_N(mas_1, mas_2, mas_3);   //находим целое частное
	char ans[45];
	MUL_NN_N(mas_2, mas_3, ans);  //перемножаем делитель и целое частное
	SUB_NN_N(mas_1, ans, answer); //находим разность = остаток

}
///////////////////////////////////////////////////////Функция меняла значения двух чисел. Они не должны были зменяться. Поэтому так:
void GCF_NN_N(char* mas_1, char* mas_2, char* answer)
{
	int m;
	char mas1[45] = {}, mas2[45] = {};
	for (int i = 0; i < 45; i++)
	{
		mas1[i] = mas_1[i];
		mas2[i] = mas_2[i];
	}
	char res[45];
	while (NZER_N_B(res) == 1)         //делаем пока одно из чисел не станет 0
	{

		if (COM_NN_D(mas1, mas2) == 2)  //если первое число > второго
		{
			MOD_NN_N(mas1, mas2, res);
			for (int i = 0; i < sizeof(mas2) || i < sizeof(res); i++)
			{
				answer[i] = mas2[i];        //запоминаем значение делителя
				mas1[i] = res[i];           //первое число заменяем остатком от деления
			}
		}
		else {                                  // если первое число <= второго
			MOD_NN_N(mas2, mas1, res);
			for (int i = 0; i < sizeof(mas1) || i < sizeof(res); i++)
			{
				answer[i] = mas1[i];
				mas2[i] = res[i];
			}
		}
	}
}

void LCM_NN_N(char* mas_1, char* mas_2, char* answer)
{
	char res[45];
	char res1[45];
	MUL_NN_N(mas_1, mas_2, res);    //находим a*b
	GCF_NN_N(mas_1, mas_2, res1);    //НОД(a, b)
	DIV_NN_N(res, res1, answer);
}
void MUL_ZZ_Z(bool b1, char A1[], bool* bAns, char ans[], bool b2, char A2[]) {
	int poz1, poz2, biggest;
	poz1 = POZ_Z_D(b1, A1);
	poz2 = POZ_Z_D(b2, A2);
	char* ssa1, * ssa2, * ssans;
	ssa1 = &A1[0];
	ssa2 = &A2[0];
	ssans = &ans[0];
	biggest = COM_NN_D(A1, A2);
	MUL_NN_N(ssa1, ssa2, ssans);
	if ((poz1 == 1 && poz2 == 1) || (poz1 == 2 && poz2 == 2) || poz1 == 0 || poz2 == 0)
		*bAns = 0;
	else
		*bAns = 1;
}
void SUB_ZZ_Z(bool b1, char A1[], bool* bAns, char* ans, bool b2, char A2[]) {
	int poz1, poz2, biggest;
	poz1 = POZ_Z_D(b1, A1);
	poz2 = POZ_Z_D(b2, A2);
	biggest = COM_NN_D(A1, A2);
	if (poz2 == 0)
	{
		ADD_NN_N(A1, A2, ans);
		*bAns = b1;
	}
	else if (poz1 == 0) {
		ADD_NN_N(A1, A2, ans);
		if (poz2 == 0)
		{
			*bAns = 0;
		}
		else {
			*bAns = -b2;
		}
	}
	else if (poz1 == 2) {
		if (poz2 == 2) {
			if (biggest == 2 || biggest == 0) {
				SUB_NN_N(A1, A2, ans);
				*bAns = 0;
			}
			else {
				SUB_NN_N(A2, A1, ans);
				*bAns = 1;
			}
		}
		else {
			ADD_NN_N(A1, A2, ans);
			*bAns = 0;
		}
	}
	else if (poz1 == 1) {
		if (poz2 == 2) {
			ADD_NN_N(A1, A2, ans);
			*bAns = -1;
		}
		else {
			if (biggest == 2) {
				SUB_NN_N(A2, A1, ans);
				*bAns = 1;
			}
			else {
				SUB_NN_N(A1, A2, ans);
				*bAns = 0;
			}
		}
	}
}
void SUB_QQ_Q(bool sign_1, char* numerator_1, char* denominator_1, bool sign_2, char* numerator_2, char* denominator_2, bool& sign_a, char* numerator_a, char* denominator_a)
{
	const int SIZE = 45;
	char num1[SIZE], num2[SIZE], num3[SIZE], num4[SIZE];
	bool sign1 = 0, sign2 = 0, sign3 = 0, sign4 = 0, sign_D1 = 0, sign_D2 = 0;
	int sign_Da = 0;
	LCM_NN_N(denominator_1, denominator_2, denominator_a);
	DIV_ZZ_Z(denominator_a, sign_Da, denominator_1, sign_D1, num1, &sign1);
	DIV_ZZ_Z(denominator_a, sign_Da, denominator_2, sign_D2, num2, &sign2);
	MUL_ZZ_Z(sign_1, numerator_1, &sign3, num3, sign1, num1);
	MUL_ZZ_Z(sign_2, numerator_2, &sign4, num4, sign2, num2);
	SUB_ZZ_Z(sign3, num3, &sign_a, numerator_a, sign4, num4);
}

int SUB_PP_P(char** polinomio_factors_1_N, char** polinomio_factors_1_D,
	char** polinomio_factors_2_N, char** polinomio_factors_2_D,
	char** polinomio_factors_ans_N, char** polinomio_factors_ans_D,int degree_P1, int degree_P2)
{
	int degree_ans;
	bool sign_1, sign_2, sign_ans;
	degree_P1 > degree_P2 ? degree_ans = degree_P1 : degree_ans = degree_P2;
	if (degree_P1 == degree_P2) degree_ans = degree_P1;

	for (int i = 0; i < degree_ans; i++)
	{
		if (polinomio_factors_1_N[i][0] == 45) sign_1 = 1; else sign_1 = 0;
		if (polinomio_factors_2_N[i][0] == 45) sign_2 = 1; else sign_2 = 0;
		sign_ans = 0;
		if (polinomio_factors_1_N[i] == NULL && polinomio_factors_2_N[i] == NULL) break;
		if (polinomio_factors_1_N[i] == NULL && polinomio_factors_2_N[i] != NULL)
		{
			polinomio_factors_ans_N[i] = polinomio_factors_2_N[i];
			polinomio_factors_ans_D[i] = polinomio_factors_2_D[i];
		}
		if (polinomio_factors_1_N[i] != NULL && polinomio_factors_2_N[i] == NULL)
		{
			polinomio_factors_ans_N[i] = polinomio_factors_1_N[i];
			polinomio_factors_ans_D[i] = polinomio_factors_1_D[i];
		}
		if (polinomio_factors_1_N[i] != NULL && polinomio_factors_2_N[i] != NULL)
		{
			SUB_QQ_Q(sign_1, polinomio_factors_1_N[i], polinomio_factors_1_D[i],
				sign_2, polinomio_factors_2_N[i], polinomio_factors_2_D[i],
				sign_ans, polinomio_factors_ans_N[i], polinomio_factors_ans_D[i]);
		}
		for (int i = 0; polinomio_factors_ans_N != NULL; i++)
		{
			if (polinomio_factors_ans_N[i][0] == 48) degree_ans -= 1;
			else break;
		}
	}
	return degree_ans;
}



int DER_P_P(int *a, int* b, int* c, int* a1, int* b1, int* c1, int *m, int *m1)
{
	int aa[45],cc[45];
	int j =0;
	for (int i = *m-1; i >= 0; i--)
	{
		aa[j] = a[i];
		cc[j] = c[i];
		j++;
	}
	for (int i = 0; i != *m; i++)
	{
		aa[i] = cc[i] * aa[i];
		cc[i]--;
	}


	int aa1[45], cc1[45];
	j = 0;
	for (int i = *m1 - 1; i >= 0; i--)
	{
		aa1[j] = a1[i];
		cc1[j] = c1[i];
		j++;
	}
	for (int i = 0; i != *m1; i++)
	{
		aa1[i] = cc1[i] * aa1[i];
		cc1[i]--;
	}


	int s(1);
	j=*m - 1;
	cout <<endl<< "Производная первого многочлена" << endl;
	for (int i = 0; i <=*m; i++)
	{
		if (s == 1)
		{
			cout << aa[i] << "/" << b[j] << "x^" << cc[i];
		}
		else
		{ 
			if (aa[i] > 0 & b[j] > 0)
			{
				if (cc[i] > 0)
					cout << "+" << aa[i] << "/" << b[i] << "x^" << cc[i];
				if (cc[i] == 0)
					cout << "+" << aa[i] << "/" << b[i];

			}
		else
		{ 
			if (cc[i] > 0)
				cout << aa[i] << "/" << b[j] << "x^" << cc[i];
			if(cc[i]==0)
				cout << aa[i] << "/" << b[j];
		}
		}
		j--;
		s--;
	}



	s=1;
	j = *m1 - 1;
	cout << endl << "Производная второго многочлена" << endl;
	for (int i = 0; i <= *m1; i++)
	{
		if (s == 1)
		{
			cout << aa1[i] << "/" << b1[j] << "x^" << cc1[i];
		}
		else
		{
			if (aa1[i] > 0 & b1[j] > 0)
			{
				if (cc1[i] > 0)
					cout << "+" << aa1[i] << "/" << b1[i] << "x^" << cc1[i];
				if (cc1[i] == 0)
					cout << "+" << aa1[i] << "/" << b1[i];

			}
			else
			{
				if (cc1[i] > 0)
					cout << aa1[i] << "/" << b1[j] << "x^" << cc1[i];
				if (cc1[i] == 0)
					cout << aa1[i] << "/" << b1[j];
			}
		}
		j--;
		s--;
	}
	return 1
}


int MUL_Pxk_P(int* a, int* b, int* c, int* a1, int* b1, int* c1, int* m, int* m1)
{
	int cc[45];
	int j = 0;
	int k;
	cout << endl << "Введите степень k: ";
	cin >> k;
	for (int i = *m - 1; i >= 0; i--)
	{
		cc[j] = c[i]*k;
		j++;
	}
	

	/*for (int i = 0; i != *m; i++)
	{
		cc[i] = cc[i] * k;
	}*/
	int s = 1;
	j = *m - 1;
	cout << endl << "Результат " << endl;
	for (int i = 0; i <= *m1; i++)
	{
		if (s == 1)
		{
			cout << a[j] << "/" << b[j] << "x^" << cc[i];
		}
		else
		{
			if (a[j] > 0 & b[j] > 0)
			{
				if (cc[i] > 0)
					cout << "+" << a[j] << "/" << b[j] << "x^" << cc[i];
				if (cc[i] == 0)
					cout << "+" << a[j] << "/" << b[j];

			}
			else
			{
				if (cc[i] > 0)
					cout << a[j] << "/" << b[j] << "x^" << cc[i];
				if (cc[i] == 0)
					cout << a[j] << "/" << b[j];
			}
		}
		j--;
		s--;
	}
	return 1;


}
void ADD_PP_P(int* a, int* b, int* c, int* a1, int* b1, int* c1, int* m, int* m1)
{
	int aa[50], bb[50];
	int n,k;
	if (*m > * m1)
	{ 
		n = *m-1;
		//k = *m1-1;
	}
	else
	{
		n = *m1-1;
		//k = *m-1;
	}
	for (int i = n; i >= 0; i--)
	{
		if (c[i]==c[k])
	}
}

int main()
{
	int n, n1;//количество коэффициентов
	setlocale(0, "");
	cout << "Введите количество коэффициентов " << endl;
	cin >> n;
	int m = n;
	int a[45], b[45], c[45];
	n--;
	while (n != -1)
	{
		cout << "Введите числитель: ";
		cin >> a[n];

		cout << "Введите знаменатель:";
		cin >> b[n];

		cout << "Введите степень:";
		cin >> c[n];

		n--;
	}

	 //второй многочлен
	cout << "Введите количество коэффициентов " << endl;
	cin >>n1;
	int m1 = n1;
	int a1[45], b1[45], c1[45];
	n1--;
	while (n1 != -1)
	{
		cout << "Введите числитель: ";
		cin >> a1[n1];
		
		cout << "Введите знаменатель:";
		cin >> b1[n1];
	
		cout << "Введите степень:";
		cin >> c1[n1];
		
		n1--;
	}
	int s(1);
	cout << "Первый многочлен:" << endl;
	for (int i = (m-1); i >= 0; i--)
	{
		if (s == 1)
		{
			cout << a[i] << "/" << b[i] << "x^" << c[i];
		}
		else
		{ 
			if (a[i] > 0 & b[i] > 0)
			{
				if (c[i] > 0)
					cout << "+" << a[i] << "/" << b[i] << "x^" << c[i];
				if (c[i] == 0)
					cout << "+" << a[i] << "/" << b[i];
			}
			else
			{
				if (c[i] > 0)
					cout << a[i] << "/" << b[i] << "x^" << c[i];
				if (c[i] == 0)
					cout << a[i] << "/" << b[i];
			}


		}
		s--;
	}
	s = 1;
	cout << endl << "Второй многочлен:" << endl;
	for (int i = (m1 - 1); i >= 0; i--)
	{
		if (s == 1)
		{
			cout << a1[i] << "/" << b1[i] << "x^" << c1[i];
		}
		else
		{
			if (a1[i] > 0 & b1[i] > 0)
			{
				if (c1[i] > 0)
					cout << "+" << a1[i] << "/" << b1[i] << "x^" << c1[i];
				if (c1[i] == 0)
					cout << "+" << a1[i] << "/" << b1[i];
			}
			else
			{
				if (c1[i] > 0)
					cout << a1[i] << "/" << b1[i] << "x^" << c1[i];
				if (c1[i] == 0)
					cout << a1[i] << "/" << b1[i];
			}


		}
		s--;
	}
//		DER_P_P(a, b, c, a1, b1, c1, &m, &m1);

	//MUL_Pxk_P(a, b, c, a1, b1, c1, &m, &m1);

	
}

