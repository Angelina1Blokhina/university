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
int amount(char* mas)
{
	int i(0), sum(0);
	while (mas[i] != '\0')
	{
		sum++; i++;
	}
	//sum--;
	return sum;
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
int NZER_N_B(char* a)//проверка на 0
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
void Show(char* mas)
{

	for (int i = 0; mas[i] != '\0'; i++)
		cout << mas[i];
}
void ShowZ(bool sign, char* mas)
{

	int count_1 = 0, count_2(0);
	for (int i = 0; mas[i] != '\0'; i++)
	{
		if (mas[i] == '0') count_1++;
		count_2++;
	}
	if (count_1 == count_2);
	else
	{
		if (sign == 0)cout << "+";
		else cout << "-";
	}
	for (int i = 0; mas[i] != '\0'; i++)
		cout << mas[i];
}
void ShowQ(bool sign, char* num, char* den)
{
	ShowZ(sign, num);
	cout << "/";
	Show(den);
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
void ADD_1N_N(char* mas_1, char* mas_ans)//+1 
{
	char one[45] = {};
	one[0] = 49;
	ADD_NN_N(mas_1, one, mas_ans);
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
void MUL_ND_N(char a[], char ans[], int lena, int D)
{


	for (int i = 0; i < lena; i++)
		ans[i] = a[i];
	ans[lena] = '\0';
	for (int i = 0; i < lena; i++)
		ans[i] = ans[i] - 48;


	TRANS(ans, lena - 1);

	int j;
	for (int i = 0; i < lena; i++) ans[i] *= D;

	for (j = 0; j < lena; j++)
	{
		ans[j + 1] += ans[j] / 10;
		ans[j] %= 10;
	}
	if (ans[lena] > 0)++lena;


	for (int i = 0; i < lena; i++)
		ans[i] = ans[i] + 48;
	TRANS(ans, lena - 1);
	ans[lena] = '\0';
}
void MUL_Nk_N(char a[], char answer[], int lena)// умножение на 10^k
{
	int k; int lenanswer = lena;
	cout << "Введите k: ";
	cin >> k;
	for (int i = 0; i < lena; i++) answer[i] = a[i];
	lenanswer += k;
	for (int i = lena; i < lenanswer; i++) answer[i] = '0';
	answer[lenanswer] = '\0';
}
void MUL_NN_N(char* a, char* b, char* ans)//умножение 
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
void SUB_NDN_N(char* a, char* b, char* answer, int lena, int lenb, int D)
{
	char ans[45];
	int lenanswer(0);
	int m = COM_NN_D(a, b);
	int m1;

	switch (m)
	{
	case 2:
		MUL_ND_N(b, ans, lenb, D);
		m1 = COM_NN_D(a, ans);
		if (m1 == 2) SUB_NN_N(a, ans, answer);
		else {
			cout << "Ошибка! Неположительный результат!\n";
		}
		break;

	case 1:

		MUL_ND_N(a, ans, lena, D);
		m1 = COM_NN_D(b, ans);
		if (m1 == 2) SUB_NN_N(b, ans, answer);
		else cout << "Ошибка! Неположительный результат!\n";

		break;
	case 0:
		cout << "Получить неотрицательный результат невозможно!";
		*answer = '\0';
		break;
	}
	if (m1 == 2)
	{
		cout << endl << "Результат действия: ";
		Show(answer);
		cout << endl;
	}
	system("pause");
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
void MOD_NN_N(char* mas_1, char* mas_2, char* answer)
{
	char mas_3[45];
	DIV_NN_N(mas_1, mas_2, mas_3);   //находим целое частное
	char ans[45];
	MUL_NN_N(mas_2, mas_3, ans);  //перемножаем делитель и целое частное
	SUB_NN_N(mas_1, ans, answer); //находим разность = остаток

}
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
void ABS_Z_N(char* mas) // Передаем только знак, чтобы превратить его в +;
{
	Show(mas);//Делаем число положительным;
	 //Возвращаем знак;
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
void MUL_ZM_Z(bool* b, char A[]) {
	int count_1 = 0, count_2(0);
	for (int i = 0; A[i] != '\0'; i++)
	{
		if (A[i] == '0') count_1++;
		count_2++;
	}
	if (count_1 == count_2);
	else
	{
		if (*b == 0) *b = 1;
		else *b = 0;
	}
}
void TRANS_N_Z(bool& b) // b - знак/
{
	b = 0; //Знак +;
}
void TRANS_Z_N(bool& b) // b - знак
{
	b = 0; // Делаем знак положительным
}
void ADD_ZZ_Z(bool b1, char A1[], bool* bAns, char ans[], bool b2, char A2[]) {
	int poz1, poz2, biggest;
	poz1 = POZ_Z_D(b1, A1);
	poz2 = POZ_Z_D(b2, A2);
	biggest = COM_NN_D(A1, A2);
	if ((poz1 == 2 || poz1 == 0) && (poz2 == 2 || poz2 == 0)) {
		ADD_NN_N(A1, A2, ans);
		*bAns = 0;
	}
	else if (poz1 == 1 && poz2 == 1) {
		ADD_NN_N(A1, A2, ans);
		*bAns = 1;
	}
	else if ((poz2 == 1 && poz1 == 0) || (poz1 == 1 && poz2 == 0))
	{
		ADD_NN_N(A1, A2, ans);
		*bAns = 1;
	}
	else if (poz1 == 2 && poz2 == 1) {
		if (biggest == 0 || biggest == 2)
		{
			SUB_NN_N(A1, A2, ans);
			*bAns = 0;
		}
		else {
			SUB_NN_N(A2, A1, ans);
			*bAns = 1;
		}
	}
	else if (poz1 == 1 && poz2 == 2) {
		if (biggest == 2)
		{
			SUB_NN_N(A1, A2, ans);
			*bAns = 1;
		}
		else {
			SUB_NN_N(A2, A1, ans);
			*bAns = 0;
		}
	}

}
void SUB_ZZ_Z(bool b1, char A1[], bool* bAns, char ans[], bool b2, char A2[]) {
	MUL_ZM_Z(&b2, A2);
	ADD_ZZ_Z(b1, A1, bAns, ans, b2, A2);
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
void DIV_ZZ_Z(char* mas_1, int sign_m1, char* mas_2, int sign_m2, char* mas_3, bool* sign_m3)
{
	DIV_NN_N(mas_1, mas_2, mas_3);
	if ((sign_m1 == 1 && sign_m2 == 1) || (sign_m1 != 1 && sign_m2 != 1)) *sign_m3 = false;
	else *sign_m3 = true;
}
void MOD_ZZ_Z(char* mas_1, char* mas_2, char* answer)
{
	MOD_NN_N(mas_1, mas_2, answer);
}
void RED_Q_Q(bool sign, char* numerator, char* denominator, bool& sign_a, char* numerator_a, char* denominator_a)
{
	const int SIZE = 45;
	char NOD[SIZE] = {};
	bool sign1 = sign;
	bool sign_NOD = 0, sign_D = 0;
	GCF_NN_N(numerator, denominator, NOD);
	DIV_ZZ_Z(numerator, sign, NOD, sign_NOD, numerator_a, &sign_a);
	DIV_ZZ_Z(denominator, sign_D, NOD, sign_NOD, denominator_a, &sign_D);
}
bool INT_Q_B(bool b, char* num, char* den) { // знак, старшая позиция числителя, с.п. знаменателя, сам числитель, сам знаменатель
	char answer[45];
	MOD_NN_N(num, den, answer); //остаток от деления числителя на знаменатель
	int k = 0, sum(0);
	sum = amount(answer);
	for (int i = 0; i < 45; i++) {
		if (answer[i] == '0') k++;
	}
	if (k == sum) {
		return 1; // да
	}
	else {
		return 0; // нет
	}
}
void TRANS_Z_Q(char* den)
{ //старшая позиция, новый пустой массив (знаменатель)
	den[0] = '1';
}
void TRANS_Q_Z(bool b, char* num, char* den, bool& sign_a, char* numerator_a, char* denominator_a)
{


	if (INT_Q_B(b, num, den) == 1) { //проверяем является ли число целым
		RED_Q_Q(b, num, den, sign_a, numerator_a, denominator_a); //сокращаем дробь, чтобы в знаменателе остался 1
	}
	else
		cout << "Число не может быть переведено в целое.";
}
void ADD_QQ_Q(bool sign_1, char* numerator_1, char* denominator_1, bool sign_2, char* numerator_2, char* denominator_2, bool& sign_a, char* numerator_a, char* denominator_a)
{
	const int SIZE = 45;
	char num1[SIZE], num2[SIZE], num3[SIZE], num4[SIZE], num_num[SIZE], num_den[SIZE];
	bool sign1 = 0, sign2 = 0, sign3 = 0, sign4 = 0, sign_D1 = 0, sign_D2 = 0, sign_num = 0, sign_den(0);
	int sign_Da = 0;
	LCM_NN_N(denominator_1, denominator_2, num_den);
	DIV_ZZ_Z(num_den, sign_den, denominator_1, sign_D1, num1, &sign1);
	DIV_ZZ_Z(num_den, sign_den, denominator_2, sign_D2, num2, &sign2);
	MUL_ZZ_Z(sign_1, numerator_1, &sign3, num3, sign1, num1);
	MUL_ZZ_Z(sign_2, numerator_2, &sign4, num4, sign2, num2);
	ADD_ZZ_Z(sign3, num3, &sign_num, num_num, sign4, num4);
	RED_Q_Q(sign_num, num_num, num_den, sign_a, numerator_a, denominator_a);
}
void DIV_NN_Dk(char* num_1, char* num_2, char* result)
{
	char ten[45] = { 0 }; // 10 в степени k
	int len_res(0);

	DIV_NN_N(num_1, num_2, result);

	len_res = amount(result);
	// получили (степень 10) + 1

	result[1] = '\0';

	ten[0] = '1';
	for (int i = 1; i < len_res; i++)
	{
		ten[i] = '0';
	}
	ten[len_res] = '\0';

	MUL_NN_N(result, &ten[0], result);
}
void SUB_QQ_Q(bool sign_1, char* numerator_1, char* denominator_1, bool sign_2, char* numerator_2, char* denominator_2, bool& sign_a, char* numerator_a, char* denominator_a)
{
	const int SIZE = 45;
	char num1[SIZE], num2[SIZE], num3[SIZE], num4[SIZE], num_num[SIZE], num_den[SIZE];
	bool sign1 = 0, sign2 = 0, sign3 = 0, sign4 = 0, sign_D1 = 0, sign_D2 = 0, sign_num = 0, sign_den(0);
	int sign_Da = 0;
	LCM_NN_N(denominator_1, denominator_2, num_den);
	DIV_ZZ_Z(num_den, sign_den, denominator_1, sign_D1, num1, &sign1);
	DIV_ZZ_Z(num_den, sign_den, denominator_2, sign_D2, num2, &sign2);
	MUL_ZZ_Z(sign_1, numerator_1, &sign3, num3, sign1, num1);
	MUL_ZZ_Z(sign_2, numerator_2, &sign4, num4, sign2, num2);
	SUB_ZZ_Z(sign3, num3, &sign_num, num_num, sign4, num4);
	RED_Q_Q(sign_num, num_num, num_den, sign_a, numerator_a, denominator_a);
}
void MUL_QQ_Q(bool sign_1, char* numerator_1, char* denominator_1, bool sign_2, char* numerator_2, char* denominator_2, bool& sign_a, char* numerator_a, char* denominator_a)
{
	const int SIZE = 45;
	bool sign_D1 = 0, sign_D2 = 0, sign_Da, sign_den(0), sign_num(0);
	char num[SIZE], den[SIZE];
	MUL_ZZ_Z(sign_1, numerator_1, &sign_num, num, sign_2, numerator_2);
	MUL_ZZ_Z(sign_D1, denominator_1, &sign_den, den, sign_D2, denominator_2);
	RED_Q_Q(sign_num, num, den, sign_a, numerator_a, denominator_a);
}
void DIV_QQ_Q(bool sign_1, char* numerator_1, char* denominator_1, bool sign_2, char* numerator_2, char* denominator_2, bool& sign_a, char* numerator_a, char* denominator_a)
{
	const int SIZE = 45;
	bool repeat(0);
	int i = 0;
	while (numerator_2[i] == 48) i++;
	if (numerator_2[i] == '\0') repeat = 1;
	else repeat = 0;
	if (!repeat)
	{
		bool sign_D1 = 0, sign_D2 = 0, sign_Da, sign_den(0), sign_num(0); char num[SIZE], den[SIZE];
		MUL_ZZ_Z(sign_1, numerator_1, &sign_num, num, sign_D2, denominator_2);
		MUL_ZZ_Z(sign_D1, denominator_1, &sign_den, den, sign_2, numerator_2);
		RED_Q_Q(sign_num, num, den, sign_a, numerator_a, denominator_a);
	}
}
int input_1(int* a, int* b, int* c) //ввод для первого многочлена
{
	int n;
	cout << "Введите степень первого мнгочлена " << endl;
	cin >> n;
	int m = n;

	while (n != -1)
	{
		cout << "Коэффициент для х^" << n << endl;
		cout << "Введите числитель: ";
		cin >> a[n];

		cout << "Введите знаменатель:";
		cin >> b[n];
		if (((a[n] < 0) && (b[n] < 0)) || (b[n] < 0))
		{
			a[n] = a[n] * (-1);
			b[n] = b[n] * (-1);
		}
		c[n] = n;
		cout << "________________________" << endl;
		n--;
	}

	return m;
}
int input_2(int* a1, int* b1, int* c1) //ввод для второго многочлена
{
	int n1;
	cout << "Введите степень второго многочлена " << endl;
	cin >> n1;
	int m = n1;

	while (n1 != -1)
	{
		cout << "Коэффициент для х^" << n1 << endl;
		cout << "Введите числитель: ";
		cin >> a1[n1];

		cout << "Введите знаменатель:";
		cin >> b1[n1];
		if (((a1[n1] < 0) && (b1[n1] < 0)) || (b1[n1] < 0))
		{
			a1[n1] = a1[n1] * (-1);
			b1[n1] = b1[n1] * (-1);
		}
		c1[n1] = n1;
		cout << "________________________" << endl;
		n1--;
	}
	return m;
}
void ShowP(int* a, int* b, int* c, int m) //вывод
{
	int s(1);
	for (int i = m; i >= 0; i--)
	{
		if (s == 1)
		{
			if (a[i] == 0) cout << "";
			else cout << a[i] << "/" << b[i] << "x^" << c[i];
		}
		else
		{
			if (a[i] > 0)
			{
				if (c[i] > 0)
					cout << "+" << a[i] << "/" << b[i] << "x^" << c[i];
				if (c[i] == 0)
					cout << "+" << a[i] << "/" << b[i];
			}
			else
			{
				if (a[i] == 0) cout << "";
				else
				{
					if (c[i] > 0)
						cout << a[i] << "/" << b[i] << "x^" << c[i];
					if (c[i] == 0)
						cout << a[i] << "/" << b[i];
				}
			}


		}
		s--;
	}
}
int ADD_PP_P(int* a, int* b, int* c, int* a1, int* b1, int* c1, int m, int m1, int aa[], int bb[], int cc[])
{
	char numerator1[45], denominator1[45], numerator2[45], denominator2[45];
	char numerator_a[45], denominator_a[45];
	int a_1[45], b_1[45], a_2[45], b_2[45];
	for (int i = 0; i < 45; i++)
	{
		a_1[i] = a[i];
		b_1[i] = b[i];
		a_2[i] = a1[i];
		b_2[i] = b1[i];
	}
	bool sign_a, sign1(1), sign2(1);
	int max, min, i(0);
	if (m > m1) {
		max = m;
		min = m1;

		while (m != m1)
		{
			cc[m] = c[m];
			aa[m] = a_1[m];
			bb[m] = b_1[m];
			m--;
		}
	}
	else {
		max = m1;
		min = m;
		while (m1 != m)
		{
			cc[m1] = c1[m1];
			aa[m1] = a_2[m1];
			bb[m1] = b_2[m1];
			m1--;
		}
	}
	for (int i = 0; i <= min; i++)
	{
		if (a_1[i] < 0) { sign1 = 0; a_1[i] *= (-1); }
		if (a_2[i] < 0) { sign2 = 0; a_2[i] *= (-1); }
		_itoa_s(a_1[i], numerator1, 10);
		_itoa_s(b_1[i], denominator1, 10);
		_itoa_s(a_2[i], numerator2, 10);
		_itoa_s(b_2[i], denominator2, 10);
		ADD_QQ_Q(sign1, numerator1, denominator1, sign2, numerator2, denominator2, sign_a, numerator_a, denominator_a);
		aa[i] = atoi(numerator_a);
		bb[i] = atoi(denominator_a);
		cc[i] = i;
		if (sign_a == 0) aa[i] *= (-1);
	}
	return max;

}
int SUB_PP_P(int* a, int* b, int* c, int* a1, int* b1, int* c1, int m, int m1, int aa[], int bb[], int cc[])
{
	char numerator1[45], denominator1[45], numerator2[45], denominator2[45];
	char numerator_a[45], denominator_a[45];
	bool sign_a, sign1(0), sign2(0);
	int a_1[45], b_1[45], a_2[45], b_2[45];
	for (int i = 0; i < 45; i++)
	{
		a_1[i] = a[i];
		b_1[i] = b[i];
		a_2[i] = a1[i];
		b_2[i] = b1[i];
	}
	int max, min, i(0);
	if (m > m1) {
		max = m;
		min = m1;

		while (m != m1)
		{
			cc[m] = c[m];
			aa[m] = a_1[m];
			bb[m] = b_1[m];
			m--;
		}
	}
	else {
		max = m1;
		min = m;
		while (m1 != m)
		{
			cc[m1] = c1[m1];
			aa[m1] = a_2[m1] * (-1);
			bb[m1] = b_2[m1];
			m1--;
		}
	}
	for (int i = 0; i <= min; i++)
	{
		if (a_1[i] < 0) { sign1 = 1; a_1[i] *= (-1); }
		if (a_2[i] < 0) { sign2 = 1; a_2[i] *= (-1); }
		_itoa_s(a_1[i], numerator1, 10);
		_itoa_s(b_1[i], denominator1, 10);
		_itoa_s(a_2[i], numerator2, 10);
		_itoa_s(b_2[i], denominator2, 10);
		SUB_QQ_Q(sign1, numerator1, denominator1, sign2, numerator2, denominator2, sign_a, numerator_a, denominator_a);
		aa[i] = atoi(numerator_a);
		bb[i] = atoi(denominator_a);
		cc[i] = i;
		if (sign_a == 1) aa[i] *= (-1);
	}
	return max;
}
void LED_P_Q(int* a, int* b, int* a1, int* b1, int m, int m1)
{
	if (a[m] % b[m] == 0)
		cout << a[m] / b[m] << endl;
	else
		cout << a[m] << "/" << b[m] << endl;
	if (a1[m] % b1[m] == 0)
		cout << a1[m] / b1[m] << endl;
	else
		cout << a1[m1] << "/" << b1[m1] << endl;
}
void DEG_P_N(int m, int m1)
{
	cout << "Степень первого многочлена:  " << m << endl;
	cout << "Степень второго многочлена: " << m1 << endl;
}
int input_xk()
{
	int k;
	cout << endl << "Введите cтепень x^" << endl;
	cin >> k;
	return k;
}

void MUL_Pxk_P(int* a, int* b, int* c, int k, int m, int* cc)
{
	for (int i = 0; i <= m; i++)
	{
		cc[i] = c[i] + k;
	}
}

void input_D(int& D_n, int& D_d)
{
	cout << endl << "Введите рациональное число" << endl;
	cout << "Введите числитель: ";
	cin >> D_n;
	cout << "Введите знаменатель:";
	cin >> D_d;

}
void MUL_PQ_P(int* a, int* b, int* c1, int a1, int b1, int m, int* aa, int* bb, int* cc) {
	char numerator_1[45], denominator_1[45], numerator_2[45], denominator_2[45];
	char numerator_a[45], denominator_a[45];
	bool sign_a, sign_1(0), sign_2(0);

	for (int i = 0; i <= m; i++) {
		if (a[i] < 0) { sign_1 = 1; a[i] *= (-1); }
		if (a1 < 0) { sign_2 = 1; a1 *= (-1); }
		_itoa_s(a[i], numerator_1, 10);
		_itoa_s(b[i], denominator_1, 10);
		_itoa_s(a1, numerator_2, 10);
		_itoa_s(b1, denominator_2, 10);
		MUL_QQ_Q(sign_1, numerator_1, denominator_1, sign_2, numerator_2, denominator_2, sign_a, numerator_a, denominator_a);
		aa[i] = atoi(numerator_a);
		bb[i] = atoi(denominator_a);
		cc[i] = i;
		if (sign_a == 1) aa[i] *= (-1);
	}
}

// нижний хедер
// краткая инструкция по клавишам
int lowHeader()
{
	cout << endl << endl;
	cout << "     " << char(30) << " - вверх";
	cout << endl;
	cout << "     " << char(31) << " - вниз";
	cout << endl;
	cout << "     " << char(17) << " - влево";
	cout << endl;
	cout << "     " << char(16) << " - вправо";
	cout << endl;
	cout << "   ESC - назад";
	cout << endl;
	cout << " ENTER - ввод";
	cout << endl;

	return 1;
}




int main() // МЕНЮ
{
	// основные переменные и переключатели
	setlocale(0, "");
	const int N = 45; // максимальное количество знаков в числе (при вводе)
	///////////////////////////////////////////////
	char arr_1[N] = {}; char arr_2[N] = {}; char arr_ans[N] = {};
	bool repeat_1(0), nez(0), repeat_2(0), sign_1(0), sign_2(0), sign_ans(0), sign_n1(0), sign_n2(0), sign_na(0);
	int compare(0), ch(0), digit(0), lenght_1(0), lenght_2(0), count_1(0), count_2(0);
	char numerator1[N] = {}, numerator2[N] = {}, denominator1[N] = {}, denominator2[N] = {}, numerator_a[N] = {}, denominator_a[N] = {};
	//////////////////////////////////////////////
	const int level_Max(10); // количество уровней (уменьшить до предела)
	int position[level_Max] = { 0 }; // позиции курсора (для каждого уровня)
	int level(0); // уровень погружения в меню

	for (int i = 0; i < level_Max; i++) // курсор по умолчанию находится на 1-ой позиции на каждом уровне
	{
		position[i] = 1;
	}

	char code(0); // код нажатой клавиши

	bool exit(0); // тумблер выхода из программы
	bool contin(0); // тумблер продолжения работы программы


					  //

					  // для целых
	bool repeat(0), repeat1(0);

	//

	do {
		system("cls");

		cout << " Г Л А В Н О Е  М Е Н Ю" << endl << endl;

		if (position[level] == 1)
			cout << "-->";
		cout << " Начать";
		cout << endl;

		if (position[level] == 2)
			cout << "-->";
		cout << " Справка";
		cout << endl;

		if (position[level] == 3)
			cout << "-->";
		cout << " Разработчики";
		cout << endl;

		if (position[level] == 4)
			cout << "-->";
		cout << " Выход";
		cout << endl;

		lowHeader();

		code = _getch();
		if (code == 224)
			code = _getch();

		if (code == 72 && position[level] > 1)
			position[level]--;
		if (code == 80 && position[level] < 4)
			position[level]++;

		// НАЧАТЬ
		if (code == 13 && position[level] == 1)
		{
			level++;
			do {
				system("cls");

				cout << "С чем Вы хотите работать?" << endl << endl;

				if (position[level] == 1)
					cout << "-->";
				cout << " Натуральные числа";
				cout << endl;

				if (position[level] == 2)
					cout << "-->";
				cout << " Целые числа";
				cout << endl;

				if (position[level] == 3)
					cout << "-->";
				cout << " Рациональные числа";
				cout << endl;

				if (position[level] == 4)
					cout << "-->";
				cout << " Многочлены";
				cout << endl;

				lowHeader();

				code = _getch();
				if (code == 224)
					code = _getch();

				if (code == 72 && position[level] > 1)
					position[level]--;
				if (code == 80 && position[level] < 4)
					position[level]++;

				// НАТУРАЛЬНЫЕ ЧИСЛА
				if (code == 13 && position[level] == 1)
				{
					level++;
					do
					{
						repeat_1 = 0;
						cout << endl << "Введите число, с которым хотите воспроизводить действия: ";
						cin.getline(arr_1, N);
						cin.clear();
						cout << endl << "Нажмите Enter ещё раз";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						for (int i = 0; arr_1[i] != '\0'; i++)
						{
							if (arr_1[i] < 48 || arr_1[i]>57)
							{
								repeat_1 = 1;
							}

						}
						if (repeat_1 == 1)
						{
							cout << endl << "Вы ввели недопустимые значения. Пожалуста, введите чиcло ещё раз";
						}
					} while (repeat_1 == 1);
					do
					{
						repeat_1 = 0;
						cout << endl << "Введите второе число, с которым хотите воспроизводить действия: ";
						cin.getline(arr_2, N);
						cin.clear();
						cout << endl << "Нажмите Enter ещё раз";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						for (int i = 0; arr_2[i] != '\0'; i++)
						{
							if (arr_2[i] < 48 || arr_2[i]>57)
							{
								repeat_1 = 1;
							}
						}
						if (repeat_1 == 1)
						{
							cout << endl << "Вы ввели недопустимые значения. Пожалуста, введите чиcло ещё раз";
						}
					} while (repeat_1 == 1);

					do {
						system("cls");

						cout << "Выберите действие:";
						cout << endl << endl;

						if (position[level] == 1)
							cout << "-->";
						cout << " Сравнение натуральных чисел";
						cout << endl;

						if (position[level] == 2)
							cout << "-->";
						cout << " Проверка на ноль";
						cout << endl;

						if (position[level] == 3)
							cout << "-->";
						cout << " Добавление 1 к натуральному числу";
						cout << endl;

						if (position[level] == 4)
							cout << "-->";
						cout << " Сложение натуральных чисел";
						cout << endl;

						if (position[level] == 5)
							cout << "-->";
						cout << " Вычитание из первого большего числа второго меньшего или равного";
						cout << endl;

						if (position[level] == 6)
							cout << "-->";
						cout << " Умножение числа на цифру";
						cout << endl;

						if (position[level] == 7)
							cout << "-->";
						cout << " Умножение числа на 10^k";
						cout << endl;

						if (position[level] == 8)
							cout << "-->";
						cout << " Умножение чисел";
						cout << endl;

						if (position[level] == 9)
							cout << "-->";
						cout << " Вычитание из числа другого числа";
						cout << endl;

						if (position[level] == 10)
							cout << "-->";
						cout << " Вычисление первой цифры деления большего на меньшее";
						cout << endl;

						if (position[level] == 11)
							cout << "-->";
						cout << " Частное от деления большего числа на меньшее или равное с остатком";
						cout << endl;

						if (position[level] == 12)
							cout << "-->";
						cout << " Остаток от деления большего на меньшее или равное натуральное с остатком";
						cout << endl;

						if (position[level] == 13)
							cout << "-->";
						cout << " НОД чисел";
						cout << endl;

						if (position[level] == 14)
							cout << "-->";
						cout << " НОК чисел";
						cout << endl;

						cout << "Ваши числа: ";
						cout << endl;
						Show(arr_1);
						cout << endl;
						Show(arr_2);

						lowHeader();

						code = _getch();
						if (code == 224)
							code = _getch();

						if (code == 72 && position[level] > 1)
							position[level]--;
						if (code == 80 && position[level] < 14)
							position[level]++;
						if (code == 13)
						{
							system("cls");
							////////////////////////////Выбор функции
							switch (position[level])
							{
							case 1:
								compare = COM_NN_D(arr_1, arr_2);
								switch (compare)
								{
								case 0:cout << endl << "Числа равны"; break;
								case 1:cout << endl << "Второе число больше первого"; break;
								case 2: cout << endl << "Первое число больше второго"; break;

								}
								cout << endl;
								system("pause");
								break;
							case 2:
								cout << endl << "Какое число вы хотите проверить на 0?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);
								if (ch == 49)
								{
									nez = NZER_N_B(arr_1);
									if (!nez)
									{
										cout << endl << "Число равно нулю";
									}
									else
									{
										cout << endl << "Число не равно нулю";
									}
								}
								else
								{
									nez = NZER_N_B(arr_1);
									if (!nez)
									{
										cout << endl << "Число равно нулю";
									}
									else
									{
										cout << endl << "Число не равно нулю";
									}
								}
								cout << endl;
								system("pause");
								break;
							case 3:
								cout << endl << "К какому числу вы хотите прибавить 1?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);
								if (ch == 49)
								{
									ADD_1N_N(arr_1, arr_ans);

								}
								else
								{
									ADD_1N_N(arr_2, arr_ans);
								}
								cout << endl;
								Show(arr_ans);
								cout << endl;
								system("pause");
								break;
							case 4:
								ADD_NN_N(arr_1, arr_2, arr_ans);
								cout << endl << "Результат сложения: ";
								cout << endl;
								Show(arr_ans);
								cout << endl;
								system("pause");
								break;
							case 5:
								compare = COM_NN_D(arr_1, arr_2);
								if (compare == 2)
								{
									SUB_NN_N(arr_1, arr_2, arr_ans);
									cout << endl << "Результат вычитания: ";
									cout << endl;
									Show(arr_ans);
									cout << endl;
									system("pause");
								}
								else
								{
									cout << endl << "Первое чило должно быть больше второго";
									cout << endl;
									system("pause");
								}
								break;
							case 6:
								cout << endl << "Введите цифру, на которую будете умножать на свои числа: ";
								cin >> digit;
								cout << endl << "На какое из ваших чисел вы хотите умножить натуральное?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);
								if (ch == 49)
								{
									lenght_1 = amount(arr_1);
									MUL_ND_N(arr_1, arr_ans, lenght_1, digit);
								}
								else
								{
									lenght_2 = amount(arr_2);
									MUL_ND_N(arr_2, arr_ans, lenght_2, digit);
								}
								cout << endl << "Результат умножения: ";
								cout << endl;
								Show(arr_ans);
								cout << endl;
								system("pause");
								break;
							case 7:

								cout << endl << "На какое из ваших чисел вы хотите умножить 10^k?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);
								if (ch == 49)
								{
									lenght_1 = amount(arr_1);
									MUL_Nk_N(arr_1, arr_ans, lenght_1);

								}
								else
								{
									lenght_2 = amount(arr_2);
									MUL_Nk_N(arr_2, arr_ans, lenght_2);
								}
								cout << endl << "Результат умножения: ";
								cout << endl;
								Show(arr_ans);
								cout << endl;
								system("pause");
								break;
							case 8:
								MUL_NN_N(arr_1, arr_2, arr_ans);
								cout << endl << "Результат умножения: ";
								cout << endl;
								Show(arr_ans);
								cout << endl;
								system("pause");
								break;
							case 9:
								cout << endl << "Введите число, которое будете умножать на свои числа: ";
								cin >> digit;
								lenght_1 = amount(arr_1);
								lenght_2 = amount(arr_2);
								SUB_NDN_N(arr_1, arr_2, arr_ans, lenght_1, lenght_2, digit);
								cout << endl;
								Show(arr_ans);
								cout << endl;
								system("pause");
								break;
							case 10:
								count_1 = 0;
								for (int i = 0; arr_2[i] != '\0'; i++)
								{
									if (arr_2[i] == '0') count_1++;
									count_2++;
								}
								if (count_1 == count_2)
								{
									cout << endl << "Делитель не может быть равен 0!";
								}
								else
								{
									compare = COM_NN_D(arr_1, arr_2);
									if (compare == 2 || compare == 0)
									{
										DIV_NN_Dk(arr_1, arr_2, arr_ans);
									}
									else
									{
										DIV_NN_Dk(arr_2, arr_1, arr_ans);
									}
									cout << endl << "Результат деления: ";
									cout << endl;
									Show(arr_ans);

								}
								cout << endl;
								system("pause");
								break;

								break;
							case 11:
								count_1 = 0;
								for (int i = 0; arr_2[i] != '\0'; i++)
								{
									if (arr_2[i] == '0') count_1++;
									count_2++;
								}
								if (count_1 == count_2)
								{
									cout << endl << "Делитель не может быть равен 0!";
								}
								else
								{
									compare = COM_NN_D(arr_1, arr_2);
									if (compare == 2 || compare == 0)
									{
										DIV_NN_N(arr_1, arr_2, arr_ans);
										cout << endl << "Результат деления: ";
										cout << endl;
										Show(arr_ans);
										MOD_NN_N(arr_1, arr_2, arr_ans);
										cout << endl << "Остаток: ";
										cout << endl;
										Show(arr_ans);

									}
									else
									{
										DIV_NN_N(arr_2, arr_1, arr_ans);
										cout << endl << "Результат деления: ";
										cout << endl;
										Show(arr_ans);
										MOD_NN_N(arr_2, arr_1, arr_ans);
										cout << endl << "Остаток: ";
										cout << endl;
										Show(arr_ans);
									}


								}
								cout << endl;
								system("pause");
								break;
							case 12:
								count_1 = 0;
								for (int i = 0; arr_2[i] != '\0'; i++)
								{
									if (arr_2[i] == '0') count_1++;
									count_2++;
								}
								if (count_1 == count_2)
								{
									cout << endl << "Делитель не может быть равен 0!";
								}
								else
								{
									compare = COM_NN_D(arr_1, arr_2);
									if (compare == 2 || compare == 0)
									{
										MOD_NN_N(arr_1, arr_2, arr_ans);
									}
									else
									{
										MOD_NN_N(arr_2, arr_1, arr_ans);
									}
									cout << endl << "Остаток: ";
									cout << endl;
									Show(arr_ans);

								}
								cout << endl;
								system("pause");
								break;
							case 13:
								GCF_NN_N(arr_1, arr_2, arr_ans);
								cout << endl << "НОД: ";
								cout << endl;
								Show(arr_ans);
								cout << endl;
								system("pause");
								break;
							case 14:
								LCM_NN_N(arr_1, arr_2, arr_ans);
								cout << endl << "НОК: ";
								cout << endl;
								Show(arr_ans);
								cout << endl;
								system("pause");
								break;
							}


						}


					} while (code != 27);
					code = 0;
					position[level] = 1;
					level--;
				}

				// ЦЕЛЫЕ ЧИСЛА
				if (code == 13 && position[level] == 2)
				{
					level++;
					printf("Введите первое число: ");
					cin.getline(arr_1, N); cout << "Пожалуйста, нажмите Enter ещё раз";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					repeat_1 = 0, repeat_2 = 0;
					do
					{
						int i = 0;
						while (arr_1[i] != '\0')
						{
							if (arr_1[i] == 45) { i++; continue; }
							if (arr_1[i] > 57 || arr_1[i] < 48)
							{
								repeat = 1;
								break;
							}
							else repeat = 0;
							i++;
						}
						if (repeat == 1)
						{
							system("cls");
							printf("Вводить нужно только цифры: от 0 до 9. Попробуйте снова!\n");
							printf("Введите первое число: ");
							cin.getline(arr_1, N); cout << "Пожалуйста, нажмите Enter ещё раз";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

						}
					} while (repeat == 1);

					printf("Введите второе число: ");
					cin.getline(arr_2, N); cout << "Пожалуйста, нажмите Enter ещё раз";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					repeat_2 = 0;
					do
					{
						int i = 0;
						while (arr_2[i] != '\0')
						{
							if (arr_2[i] == 45) { i++; continue; }
							if (arr_2[i] > 57 || arr_2[i] < 48)
							{
								repeat_2 = 1;
								break;
							}
							else repeat_2 = 0;
							i++;
						}
						if (repeat_2 == 1)
						{
							system("cls");
							printf("Вводить нужно только цифры: от 0 до 9. Попробуйте снова!\n");
							printf("Введите второе число: ");
							cin.getline(arr_2, N);
							cout << "Пожалуйста, нажмите Enter ещё раз";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (repeat_2 == 1);

					if (arr_1[0] == 45)
					{
						sign_1 = 1;
						for (int i = 0; arr_1[i] != '\0'; i++)
						{
							arr_1[i] = arr_1[i + 1];
						}
					}
					else sign_1 = 0;

					if (arr_2[0] == 45)
					{
						sign_2 = 1;
						for (int i = 0; arr_2[i] != '\0'; i++)
						{
							arr_2[i] = arr_2[i + 1];
						}
					}
					else sign_2 = 0;
					do {
						system("cls");

						cout << "Выберите действие:";
						cout << endl << endl;

						if (position[level] == 1)
							cout << "-->";
						cout << " Абсолютная величина числа";
						cout << endl;

						if (position[level] == 2)
							cout << "-->";
						cout << " Определение положительности числа";
						cout << endl;

						if (position[level] == 3)
							cout << "-->";
						cout << " Умножение на (-1)";
						cout << endl;

						if (position[level] == 4)
							cout << "-->";
						cout << " Преобразование натурального в целое";
						cout << endl;

						if (position[level] == 5)
							cout << "-->";
						cout << " Преобразование целого неотрицательного в натуальное";
						cout << endl;

						if (position[level] == 6)
							cout << "-->";
						cout << " Сложение";
						cout << endl;

						if (position[level] == 7)
							cout << "-->";
						cout << " Вычитание";
						cout << endl;

						if (position[level] == 8)
							cout << "-->";
						cout << " Умножение";
						cout << endl;

						if (position[level] == 9)
							cout << "-->";
						cout << " Деление";
						cout << endl;

						if (position[level] == 10)
							cout << "-->";
						cout << " Остаток";
						cout << endl;
						cout << "Ваши числа: " << endl;
						ShowZ(sign_1, arr_1);
						cout << endl;
						ShowZ(sign_2, arr_2);
						lowHeader();

						code = _getch();
						if (code == 224)
							code = _getch();

						if (code == 72 && position[level] > 1)
							position[level]--;
						if (code == 80 && position[level] < 10)
							position[level]++;

						if (code == 13)
						{
							system("cls");
							switch (position[level])
							{
							case 1:
								cout << endl << "С каким числом будете производить действие?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);
								if (ch == 49)
								{
									ABS_Z_N(arr_1);

								}
								else
								{
									ABS_Z_N(arr_2);
								}
								cout << endl;
								system("pause");
								break;
							case 2:
								cout << endl << "С каким числом будете производить действие?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);
								if (ch == 49)
								{
									count_1 = POZ_Z_D(sign_1, arr_1);
									switch (count_1)
									{
									case 0:cout << endl << "Число равно 0"; break;
									case 1:cout << endl << "Число отрицательно"; break;
									case 2:cout << endl << "Число положительно"; break;
									}
								}
								else
								{
									count_2 = POZ_Z_D(sign_2, arr_2);
									switch (count_2)
									{
									case 0:cout << endl << "Число равно 0"; break;
									case 1:cout << endl << "Число отрицательно"; break;
									case 2:cout << endl << "Число положительно"; break;
									};
								}
								cout << endl;
								system("pause");
								break;
							case 3:
								cout << endl << "С каким числом будете производить действие?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);
								if (ch == 49)
								{
									sign_ans = sign_1;
									MUL_ZM_Z(&sign_ans, arr_1);
									cout << endl;
									ShowZ(sign_ans, arr_1);
								}
								else
								{
									sign_ans = sign_2;
									MUL_ZM_Z(&sign_ans, arr_2);
									cout << endl;
									ShowZ(sign_ans, arr_2);
								}
								cout << endl;
								system("pause");
								break;
							case 4:
								cout << endl << "С каким числом будете производить действие?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);


								if (ch == 49)
								{
									count_1 = 0, count_2 = 0;
									for (int i = 0; arr_1[i] != '\0'; i++)
									{
										if (arr_1[i] == '0') count_1++;
										count_2++;
									}
									if (sign_1 == 1 || count_1 == count_2)cout << endl << "Число не является натуральным";
									else
									{
										TRANS_N_Z(sign_ans);
										cout << endl;
										ShowZ(sign_ans, arr_1);
									}
								}
								else
								{
									count_1 = 0, count_2 = 0;
									for (int i = 0; arr_2[i] != '\0'; i++)
									{
										if (arr_2[i] == '0') count_1++;
										count_2++;
									}
									if (sign_2 == 1 || count_1 == count_2)cout << endl << "Число не является натуральным";
									else
									{
										TRANS_N_Z(sign_ans);
										cout << endl;
										ShowZ(sign_ans, arr_2);
									}
								}
								cout << endl;
								system("pause");
								break;
							case 5:
								cout << endl << "С каким числом будете производить действие?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);


								if (ch == 49)
								{
									int count_1 = 0, count_2(0);
									for (int i = 0; arr_1[i] != '\0'; i++)
									{
										if (arr_1[i] == '0') count_1++;
										count_2++;
									}
									if (count_1 == count_2)
									{
										cout << endl << "Преобразование невозможно";
									}
									else
									{
										TRANS_Z_N(sign_ans);
										cout << endl;
										Show(arr_1);
									}
								}
								else
								{
									int count_1 = 0, count_2(0);
									for (int i = 0; arr_1[i] != '\0'; i++)
									{
										if (arr_1[i] == '0') count_1++;
										count_2++;
									}
									if (count_1 == count_2)
									{
										cout << endl << "Преобразование невозможно";
									}
									else
									{
										TRANS_Z_N(sign_ans);
										cout << endl;
										Show(arr_2);
									}
								}
								cout << endl;
								system("pause");
								break;
							case 6:
								ADD_ZZ_Z(sign_1, arr_1, &sign_ans, arr_ans, sign_2, arr_2);
								cout << endl;
								ShowZ(sign_ans, arr_ans);
								cout << endl;
								system("pause");
								break;
							case 7:
								SUB_ZZ_Z(sign_1, arr_1, &sign_ans, arr_ans, sign_2, arr_2);
								cout << endl;
								ShowZ(sign_ans, arr_ans);
								cout << endl;
								system("pause");
								break;
							case 8:
								MUL_ZZ_Z(sign_1, arr_1, &sign_ans, arr_ans, sign_2, arr_2);
								cout << endl;
								ShowZ(sign_ans, arr_ans);
								cout << endl;
								system("pause");
								break;
							case 9:
								compare = COM_NN_D(arr_1, arr_2);
								if (compare == 1)
								{
									count_1 = 0; count_2 = 0;
									for (int i = 0; arr_1[i] != '\0'; i++)
									{
										if (arr_1[i] == '0') count_1++;
										count_2++;
									}
									if (count_1 == count_2)
									{
										cout << endl << "Делитель не может быть 0";
									}
									else
									{
										DIV_ZZ_Z(arr_2, sign_2, arr_1, sign_1, arr_ans, &sign_ans);
										cout << endl << "Результат деления большего числа на меньшее: ";
										cout << endl;
										ShowZ(sign_ans, arr_ans);
										cout << endl;
										MOD_ZZ_Z(arr_2, arr_1, arr_ans);
										cout << endl << "Остаток: ";
										cout << endl;
										Show(arr_ans);
										cout << endl;
										system("pause");
									}
								}
								else
								{
									count_1 = 0, count_2 = 0;
									for (int i = 0; arr_2[i] != '\0'; i++)
									{
										if (arr_2[i] == '0') count_1++;
										count_2++;
									}
									if (count_1 == count_2)
									{
										cout << endl << "Делитель не может быть 0";
									}
									else
									{
										DIV_ZZ_Z(arr_1, sign_1, arr_2, sign_2, arr_ans, &sign_ans);
										cout << endl << "Результат деления большего числа на меньшее: ";
										cout << endl;
										ShowZ(sign_ans, arr_ans);
										cout << endl;
										MOD_ZZ_Z(arr_1, arr_2, arr_ans);
										cout << endl << "Остаток: ";
										cout << endl;
										Show(arr_ans);
										cout << endl;
										system("pause");
									}
								}
								break;
							case 10:
								compare = COM_NN_D(arr_1, arr_2);
								if (compare == 1)
								{
									count_1 = 0; count_2 = 0;
									for (int i = 0; arr_1[i] != '\0'; i++)
									{
										if (arr_1[i] == '0') count_1++;
										count_2++;
									}
									if (count_1 == count_2)
									{
										cout << endl << "Делитель не может быть 0";
									}
									else
									{
										MOD_ZZ_Z(arr_2, arr_1, arr_ans);
										cout << endl << "Остаток: ";
										cout << endl;
										Show(arr_ans);
										cout << endl;
										system("pause");
									}
								}
								else
								{
									count_1 = 0, count_2 = 0;
									for (int i = 0; arr_2[i] != '\0'; i++)
									{
										if (arr_2[i] == '0') count_1++;
										count_2++;
									}
									if (count_1 == count_2)
									{
										cout << endl << "Делитель не может быть 0";
									}
									else
									{
										MOD_ZZ_Z(arr_1, arr_2, arr_ans);
										cout << endl << "Остаток: ";
										cout << endl;
										Show(arr_ans);
										cout << endl;
										system("pause");
									}
								}
								break;
							}
						}

					} while (code != 27);
					code = 0;
					position[level] = 1;
					level--;
				}

				// РАЦИОНАЛЬНЫЕ ЧИСЛА
				if (code == 13 && position[level] == 3)
				{
					//////////////////////////ВВОД
					printf("Введите числитель первой дроби: ");
					cin.getline(numerator1, N); cout << endl << "Пожалуйста, нажмите Enter ещё раз ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					repeat_1 = 0, repeat_2 = 0;
					do
					{
						int i = 0;
						sign_n1 = 0;
						while (numerator1[i] != '\0')
						{
							if (numerator1[0] == 45)
							{
								repeat_1 = 0;
								sign_n1 = 1;
								i++;
								continue;
							}
							if (numerator1[i] > 57 || numerator1[i] < 48)
							{
								repeat_1 = 1;
								break;
							}
							else repeat_1 = 0;
							i++;
						}
						if (repeat_1 == 1)
						{
							system("cls");
							printf("Вводить нужно только цифры: от 0 до 9. Попробуйте снова!\n");
							printf("Введите числитель первой дроби: ");
							cin.getline(numerator1, N); cout << endl << "Пожалуйста, нажмите Enter ещё раз ";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (repeat_1 == 1);

					repeat_1 = 0, repeat_2 = 0;
					printf("Введите знаменатель первой дроби: ");
					cin.getline(denominator1, N); cout << endl << "Пожалуйста, нажмите Enter ещё раз ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					do
					{
						int i = 0;
						while (denominator1[i] != '\0')
						{
							if (denominator1[i] > 57 || denominator1[i] < 48)
							{
								repeat_1 = 1;
								break;
							}
							else repeat_1 = 0;
							i++;
						}
						i = 0;
						while (denominator1[i] == 48) i++;
						if (denominator1[i] == '\0') repeat_2 = 1;
						else repeat_2 = 0;
						if (repeat_1 == 1 || repeat_2 == 1 || denominator1[0] == 45)
						{
							system("cls");
							printf("Вводить нужно только цифры: от 0 до 9. Попробуйте снова!\n");
							printf("Введите знаменатель первой дроби: ");
							cin.getline(denominator1, N); cout << endl << "Пожалуйста, нажмите Enter ещё раз ";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (repeat_1 == 1 || repeat_2 == 1 || denominator1[0] == 45);

					repeat_1 = 0;
					printf("Введите числитель второй дроби: ");
					cin.getline(numerator2, N); cout << endl << "Пожалуйста, нажмите Enter ещё раз ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					do
					{
						int i = 0; sign_n2 = 0;
						while (numerator2[i] != '\0')
						{
							if (numerator1[0] == 45)
							{
								repeat_1 = 0;
								sign_n2 = 1;
								i++;
								continue;
							}
							if (numerator2[i] > 57 || numerator2[i] < 48)
							{
								repeat_1 = 1;
								break;
							}
							else repeat_1 = 0;
							i++;
						}
						if (repeat_1 == 1)
						{
							system("cls");
							printf("Вводить нужно только цифры: от 0 до 9. Попробуйте снова!\n");
							printf("Введите числитель второй дроби: ");
							cin.getline(numerator2, N); cout << endl << "Пожалуйста, нажмите Enter ещё раз ";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (repeat_1 == 1);

					repeat_1 = 0, repeat_2 = 0;
					printf("Введите знаменатель второй дроби: ");
					cin.getline(denominator2, N); cout << endl << "Пожалуйста, нажмите Enter ещё раз ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					do
					{
						int i = 0;
						while (denominator2[i] != '\0')
						{
							if (denominator2[i] > 57 || denominator2[i] < 48)
							{
								repeat = 1;
								break;
							}
							else repeat = 0;
							i++;
						}
						i = 0;
						while (denominator2[i] == 48) i++;
						if (denominator2[i] == '\0') repeat_2 = 1;
						else repeat_2 = 0;
						if (repeat_1 == 1 || repeat_2 == 1 || denominator2[0] == 45)
						{
							system("cls");
							printf("Вводить нужно только цифры: от 0 до 9. Попробуйте снова!\n");
							printf("Введите знаменатель второй дроби: ");
							cin.getline(denominator2, N); cout << endl << "Пожалуйста, нажмите Enter ещё раз ";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (repeat_1 == 1 || repeat_2 == 1 || denominator2[0] == 45);



					if (numerator1[0] == 45)
					{
						sign_n1 = 1;
						for (int i = 0; numerator1[i] != '\0'; i++)
						{
							numerator1[i] = numerator1[i + 1];
						}
					}
					else sign_n1 = 0;

					if (numerator2[0] == 45)
					{
						sign_n2 = 1;
						for (int i = 0; numerator2[i] != '\0'; i++)
						{
							numerator2[i] = numerator2[i + 1];
						}
					}
					else sign_n2 = 0;
					/////////////////////////////////
					level++;
					do {
						system("cls");

						cout << "Выберите действие:";
						cout << endl << endl;

						if (position[level] == 1)
							cout << "-->";
						cout << " Сокращение дроби";
						cout << endl;

						if (position[level] == 2)
							cout << "-->";
						cout << " Проверка на целое";
						cout << endl;

						if (position[level] == 3)
							cout << "-->";
						cout << " Преобразование целого в дробное";
						cout << endl;

						if (position[level] == 4)
							cout << "-->";
						cout << " Преобразование дробного в целое";
						cout << endl;

						if (position[level] == 5)
							cout << "-->";
						cout << " Сложение дробей";
						cout << endl;

						if (position[level] == 6)
							cout << "-->";
						cout << " Вычитание дробей";
						cout << endl;

						if (position[level] == 7)
							cout << "-->";
						cout << " Умножение дробей";
						cout << endl;

						if (position[level] == 8)
							cout << "-->";
						cout << " Деление дробей";
						cout << endl;
						cout << "Ваши числа: ";
						cout << endl;
						ShowQ(sign_n1, numerator1, denominator1);
						cout << endl;
						ShowQ(sign_n2, numerator2, denominator2);
						lowHeader();

						code = _getch();
						if (code == 224)
							code = _getch();

						if (code == 72 && position[level] > 1)
							position[level]--;
						if (code == 80 && position[level] < 8)
							position[level]++;

						if (code == 13)
						{
							system("cls");
							switch (position[level])
							{
							case 1:
								cout << endl << "С какой дробью будете производить действия?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);
								if (ch == 49)
								{
									RED_Q_Q(sign_n1, numerator1, denominator1, sign_na, numerator_a, denominator_a);
								}
								else
								{
									RED_Q_Q(sign_n2, numerator2, denominator2, sign_na, numerator_a, denominator_a);
								}
								cout << "Результат сокращения: ";
								ShowQ(sign_na, numerator_a, denominator_a);
								cout << endl;
								system("pause");
								break;
							case 2:
								cout << endl << "С какой дробью будете производить действия?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);
								if (ch == 49)
								{
									nez = INT_Q_B(sign_n1, numerator1, denominator1);
								}
								else
								{
									nez = INT_Q_B(sign_n1, numerator2, denominator2);
								}
								if (nez)cout << endl << "Число является целым";
								else cout << endl << "Число не является целым";
								cout << endl;
								system("pause");
								break;
							case 3:
								cout << endl << "С какой дробью будете производить действия?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);
								if (ch == 49)
								{
									cout << "Ваше целое: " << endl;
									ShowZ(sign_n1, numerator1);
									cout << endl << "Тогда ваша дробь: " << endl;
									ShowZ(sign_n1, numerator1); cout << "/1";
								}
								else
								{
									cout << "Ваше целое: " << endl;
									ShowZ(sign_n2, numerator2);
									cout << endl << "Тогда ваша дробь: " << endl;
									ShowZ(sign_n2, numerator2); cout << "/1";
								}

								cout << endl;
								system("pause");
								break;
							case 4:
								cout << endl << "С какой дробью будете производить действия?" << endl;
								do
								{
									repeat_1 = 0;
									ch = _getch();
									if (ch < 49 || ch>50)
									{
										repeat_1 = 1; cout << endl << "Нажмите на 1 или 2 для выбора";
									}
								} while (repeat_1 == 1);
								if (ch == 49)
								{
									TRANS_Q_Z(sign_n1, numerator1, denominator1, sign_na, numerator_a, denominator_a);
									if (INT_Q_B(sign_n1, numerator1, denominator1))
									{
										cout << endl;
										ShowZ(sign_na, numerator_a);
									}
								}
								else
								{
									TRANS_Q_Z(sign_n2, numerator2, denominator2, sign_na, numerator_a, denominator_a);
									if (INT_Q_B(sign_n2, numerator2, denominator2))
									{
										cout << endl;
										ShowZ(sign_na, numerator_a);
									}
								}
								cout << endl;
								system("pause");
								break;
							case 5:
								ADD_QQ_Q(sign_n1, numerator1, denominator1, sign_n2, numerator2, denominator2, sign_na, numerator_a, denominator_a);
								cout << "Результат сложения: ";
								ShowQ(sign_na, numerator_a, denominator_a);
								cout << endl;
								system("pause");
								break;
							case 6:
								SUB_QQ_Q(sign_n1, numerator1, denominator1, sign_n2, numerator2, denominator2, sign_na, numerator_a, denominator_a);
								cout << "Результат вычитания: ";
								ShowQ(sign_na, numerator_a, denominator_a);
								cout << endl;
								system("pause");
								break;
							case 7:
								MUL_QQ_Q(sign_n1, numerator1, denominator1, sign_n2, numerator2, denominator2, sign_na, numerator_a, denominator_a);
								cout << "Результат умножения: ";
								ShowQ(sign_na, numerator_a, denominator_a);
								cout << endl;
								system("pause");
								break;
							case 8:
								DIV_QQ_Q(sign_n1, numerator1, denominator1, sign_n2, numerator2, denominator2, sign_na, numerator_a, denominator_a);
								cout << "Результат деления: ";
								ShowQ(sign_na, numerator_a, denominator_a);
								cout << endl;
								system("pause");
								break;
							}
						}
					} while (code != 27);
					code = 0;
					position[level] = 1;
					level--;
				}

				// МНОГОЧЛЕНЫ

				if (code == 13 && position[level] == 4)
				{
					int num_1[120], num_2[120], den_1[120], den_2[120], deg_1[120], deg_2[120], num_ans[120], den_ans[120], deg_ans[120];
					int count_p1(0), count_p2(0), count_ans(0);
					count_p1 = input_1(num_1, den_1, deg_1);
					count_p2 = input_2(num_2, den_2, deg_2);
					int k, k1;
					int D_n(0), D_d(0);
					int deg_ans2[45], num_ans2[45], den_ans2[45];
					level++;
					do {
						system("cls");

						cout << "Выберите действие:";
						cout << endl << endl;

						if (position[level] == 1)
							cout << "-->";
						cout << " Сложение многочленов";
						cout << endl;

						if (position[level] == 2)
							cout << "-->";
						cout << " Вычитание многочленов";
						cout << endl;

						if (position[level] == 3)
							cout << "-->";
						cout << " Умножение на рациональное число";
						cout << endl;

						if (position[level] == 4)
							cout << "-->";
						cout << " Умножение многочлена на x^k";
						cout << endl;

						if (position[level] == 5)
							cout << "-->";
						cout << " Старший коэффициент многочлена";
						cout << endl;

						if (position[level] == 6)
							cout << "-->";
						cout << " Степень многочлена";
						cout << endl;

						if (position[level] == 7)
							cout << "-->";
						cout << " Вынесение из многочлена НОК знаменателей коэфф-в и НОД числителей";
						cout << endl;

						if (position[level] == 8)
							cout << "-->";
						cout << " Умножение многочленов";
						cout << endl;

						if (position[level] == 9)
							cout << "-->";
						cout << " Частное от деления многочлена на многочленпри делении с остатком";
						cout << endl;

						if (position[level] == 10)
							cout << "-->";
						cout << " Остаток от деления многочлена на многочлен при делении с остатком";
						cout << endl;

						if (position[level] == 11)
							cout << "-->";
						cout << " НОД многочленов";
						cout << endl;

						if (position[level] == 12)
							cout << "-->";
						cout << " Производная многочлена";
						cout << endl;

						if (position[level] == 13)
							cout << "-->";
						cout << " Преобразование многочлена - кратные корни в простые";
						cout << endl;
						cout << "Ваши многочлены: " << endl;
						ShowP(num_1, den_1, deg_1, count_p1);
						cout << endl;
						ShowP(num_2, den_2, deg_2, count_p2);
						lowHeader();

						code = _getch();
						if (code == 224)
							code = _getch();

						if (code == 72 && position[level] > 1)
							position[level]--;
						if (code == 80 && position[level] < 13)
							position[level]++;
						if (code == 13)
						{
							switch (position[level])
							{
							case 1: count_ans = ADD_PP_P(num_1, den_1, deg_1, num_2, den_2, deg_2, count_p1, count_p2, num_ans, den_ans, deg_ans);
								cout << "Результат: ";
								ShowP(num_ans, den_ans, deg_ans, count_ans); system("pause"); break;
							case 2: count_ans = SUB_PP_P(num_1, den_1, deg_1, num_2, den_2, deg_2, count_p1, count_p2, num_ans, den_ans, deg_ans);
								cout << "Результат: ";
								ShowP(num_ans, den_ans, deg_ans, count_ans); system("pause"); break;
							case 3:
								input_D(D_n, D_d);
								MUL_PQ_P(num_1, den_1, deg_1, D_n, D_d, count_p1, num_ans, den_ans, deg_ans);
								MUL_PQ_P(num_2, den_2, deg_2, D_n, D_d, count_p2, num_ans2, den_ans2, deg_ans2);
								cout << "Результат умножения 1 многочлена: " << endl;
								ShowP(num_ans, den_ans, deg_ans, count_p1);
								cout << endl;
								cout << "Результат умножения 2 многочлена: " << endl;
								ShowP(num_ans2, den_ans2, deg_ans2, count_p2);
								cout << endl;
								system("pause");
								break;
							case 4:  k = input_xk();
								MUL_Pxk_P(num_1, den_1, deg_1, k, count_p1, deg_ans);

								MUL_Pxk_P(num_2, den_2, deg_2, k, count_p1, deg_ans2);
								cout << "Результат умножения 1 многочлена: " << endl;
								ShowP(num_1, den_1, deg_ans, count_p1);
								cout << endl;
								cout << "Результат умножения 2 многочлена: " << endl;
								ShowP(num_2, den_2, deg_ans2, count_p2); system("pause");
								cout << endl<<endl;


								break;
							case 5:LED_P_Q(num_1, den_1, num_2, den_2, count_p1, count_p2); system("pause");
								break;
							case 6:
								DEG_P_N(count_p1, count_p2); system("pause");
								break;
							case 7:break;
							}
						}

					} while (code != 27);
					code = 0;
					position[level] = 1;
					level--;
				}

			} while (code != 27);
			position[level] = 1;
			code = 0;
			level--;
		}

		// СПРАВКА
		if (code == 13 && position[level] == 2)
		{
			level++;
			do {
				system("cls");
				cout << "<INSTRUCTION>";
				cout << endl << "Вас приветствует система компьютерной алгебры!";
				cout << endl << "При введении натуральных чисел нужно вводить ТОЛЬКО положительные значения.";
				cout << endl << "При введении любых чисел следует дважды нажать Enter.";
				cout << endl << "Числа НЕ могут начинаться с 0, только если это не 0 по сути.";
				cout << endl << "Число ноль должно представлять из себя 1 цифру 0.";
				cout << endl << "Стоит помнить, что дробь является отношением ЦЕЛОГО на НАТУРАЛЬНОЕ.";
				cout << endl << "За знак дроби отвечает знак числителя.";
				cout << endl << "ВНИМАНИЕ!!! БЛОК МНОГОЧЛЕНОВ НЕ РАБОТАЕТ!!!";
				cout << endl << endl;

				cout << "Нажмите ESC, чтобы вернуться";

				code = _getch();
			} while (code != 27);
			code = 0;
			position[level] = 1;
			level--;
		}

		// РАЗРАБОТЧИКИ
		if (code == 13 && position[level] == 3)
		{
			level++;
			do {
				system("cls");

				cout << "<Анастасия Жангурова 9373"
					<< "\n(DIV_NN_Dk, TRANS_N_Z, ABS_Z_N)"
					<< "\nАнгелина Блохина 9373"
					<< "\n(COM_NN_D, NZER_N_B, ADD_1N_N, ADD_NN_N, ADD_PP_P, SUB_PP_P)"
					<< "\nЕкатерина Гольдина 9373"
					<< "\n(MOD_NN_N, GCF_NN_N, LCM_NN_N, MUL_PQ_P, MUL_Pxk_P, LED_P_Q)"
					<< "\nАнастасия Лестенькова 9373"
					<< "\nАлександра Орлова 9373"
					<< "\n(SUB_NN_N, MUL_ND_N, MUL_Nk_N, SUB_NDN_N, DIV_NN_N, MUL_NN_N)"
					<< "\nЕлизавета Романова 9373"
					<< "\nГалия Фаттахова 9373"
					<< "\n(INT_Q_B, TRANS_Z_Q, TRANS_Q_Z)"
					<< "\nАлексей Еременко 9373"
					<< "\n(MUL_ZM_Z, POZ_Z_D, TRANS_Z_N, ADD_ZZ_Z, SUB_ZZ_Z, MUL_ZZ_Z)"
					<< "\nСофья Петрова 9373(RED_Q_Q, ADD_QQ_Q, )"
					<< "\nМаксим Заболотников 9373"
					<< "\n(ADD_PP_P, SUB_PP_P, SUB_QQ_Q, MUL_QQ_Q, DIV_QQ_Q)"
					<< "\nЕгор Бахарев 9373"
					<< "(\nFAC_P_Q)>";
				cout << endl << endl;
				cout << "Нажмите ESC, чтобы вернуться";

				code = _getch();
			} while (code != 27);
			code = 0;
			position[level] = 1;
			level--;
		}

		// ВЫХОД
		if (code == 13 && position[level] == 4)
		{
			level++;
			do {
				system("cls");

				cout << " В Ы  У В Е Р Е Н Ы ,  Ч Т О  Х О Т И Т Е  В Ы Й Т И ?" << endl << endl;

				if (position[level] == 1)
					cout << "-->";
				cout << " НЕТ";
				cout << endl;

				if (position[level] == 2)
					cout << "-->";
				cout << " ДА";
				cout << endl;

				lowHeader();

				code = _getch();
				if (code == 224)
					code = _getch();

				if (code == 72 && position[level] > 1)
					position[level]--;
				if (code == 80 && position[level] < 2)
					position[level]++;

				if (code == 13 && position[level] == 1)
					contin = 1;
				if (code == 13 && position[level] == 2)
					exit = 1;

			} while (code != 27 && exit == 0 && contin == 0);
			contin = 0;
			position[level] = 1;
			code = 0;
			level--;
		}
	} while (code != 27 && exit == 0);
	code = 0;

	system("cls");
}