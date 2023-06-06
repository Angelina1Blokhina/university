#include <iostream>
#include <stdio.h>

struct q
{
	int zn;
	q* next;
	q* last;
};

q* f = NULL;
q* last = new(q);

void push(int a)
{
	q* p = new(q);
	p->zn = a;
	p->next = NULL;
	if (f == NULL)
		f = p;
	else
		last->next = p;
	last = p;
}

bool pop(int& a)
{
	q* p;
	if (f == NULL)
		return false;
	else
	{
		a = f->zn;
		p = f;
		f = f->next;
		delete p;
		return true;
	}
}

int main()
{
	int a;
	for (int i = 1; i < 10; i++)
		push(i);
	while (pop(a) == true)
		std::cout << a << " ";
}