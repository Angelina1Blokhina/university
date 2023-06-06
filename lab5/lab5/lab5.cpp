// lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

using namespace std;



#include <iostream>
int function1(int *a, int &b)
{
	return (*a+b);
}
int function2(int & a, int b)
{
	return (a * b);
}
int fun3(int a, int *b)
{
	return(a-*b);
}
int fun4(int* a, int* b)
{
	return(*a + *b);
}
int main()
{
	int a(12),b(3), d, l, m, o;
	int* z;
	int* c;
	z = &a;
	c = &b;
	m= function1(&a,b);
	d = function2(*z, *c);
	l = fun3(a, &b);
	o = fun4(z, c);
	cout << m << endl;
	cout << d << endl;
	cout << l << endl;
	cout << o << endl;
}
