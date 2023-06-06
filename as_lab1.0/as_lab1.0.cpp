using namespace std;
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>


struct Che
{
	char a;
	Che* next;
};


void push_2(Che*** head, char** newel)
{
	Che* b1 = **head;
	Che* k;
	k = new(Che);

	Che* j = **head;
	bool z(1);
	switch (**newel)
	{
	case '*':
		if (b1->a != '/')
		{
			k->a = **newel;
			k->next = **head;
			**head = k;
		}

		else
		{
			while (b1->a == '/')
			{
				if (z == 1) z = 0;
				else j = j->next;
				b1 = b1->next;
			}
			k->a = **newel;
			j->next = k;
			k->next = b1;

		}

		break;

	case '/':
		if (b1->a != '*')
		{
			k->a = **newel;
			k->next = **head;
			**head = k;
		}

		else
		{
			while (b1->a == '*')
			{
				if (z == 1) z = 0;
				else j = j->next;
				b1 = b1->next;
			}
			k->a = **newel;
			j->next = k;
			k->next = b1;
			/*if (k->a != '*')
			{
				b1->next = **head;
				b1 = **head;
			}
			else
			{
				j = j->next;
				while (j->a == '*')
				{
					k = k->next;
					j = j->next;
				}
				k->next = b1;
				b1->next = j;
			}*/

			break;
	default:
		while (b1->next != NULL)
			b1 = b1->next;
		b1->next = new (Che);
		b1 = b1->next;
		b1->a = **newel;
		b1->next = NULL;
		break;

		}
	}
}
void push_1(Che** *head, char **newel) 
{ 
	Che* b1; 
	b1= new Che(); 
	Che *b = **head;
	
	b1->a = **newel; 
	**head = b1; 
	b1->next = NULL;
	
}
void por(Che** head)
{
	
	Che* b1 = *head;
	/*if (b1->a == '(')
	{
		*head = b1->next;
		//b1->next = *head;
		delete b1;
		b1 = *head;
	}*/
	Che* k = *head;
	Che* j = *head;

	
	//while (b1 != NULL)
	//{
		switch (b1->a)
		{
		case '*':
			if (k->a != '/' and k->a!='(')
			{
				b1->next = *head;
				b1 = *head;
			}
			
			else
			{
				j = j->next;
				while (j->a == '/' or j->a=='(')
				{
					k = k->next;
					j = j->next;
				}
				k->next = b1;
				b1->next = j;
			}

			break;
		
	case '/':
		if (k->a != '*')
		{
			b1->next = *head;
			b1 = *head;
		}
		else
		{
			j = j->next;
			while (j->a == '*')
			{
				k = k->next;
				j = j->next;
			}
			k->next = b1;
			b1->next = j;
		}

		break;

	}
	b1 = b1->next;
	//}
	
	


};


void delete_s(Che** head, int *i2, char*skob)
{
	Che* prev=0;
	Che* b1 = *head;
	bool u = 1;
	int o;

	for (int i = 0; i < *i2; i++)
	{
		/*while ((b1->next != NULL) )
		{
			if (u != 0)
			{
				prev = *head;
				u = 0;
			}
			else
				prev=prev->next;
			b1 = b1->next;
		}*/
		if (b1 != NULL)
		{

		
			* head = b1->next;
		if (b1->a != '(')
		{
			cout<<b1->a;
			delete b1;
			
		}
		else
			delete b1;
		/*o = *i2 - 1 - i;
		switch (o)
		{
		
		case 0:
			prev = NULL;
			break;
		default:
			prev->next = NULL;
			break;
		}*/
			
		}
		u = 1;
		b1 = *head;
	}
	
	
	
}
void st(Che** head, char *av)
{
	if (*head == NULL)
		push_1(&head, &av);
	else
		push_2(&head, &av); 
}
		


int main()
{
	setlocale(LC_ALL, "Russian");
	Che* head = NULL;
	bool tt(1);
	char newel;
	string av;
	cout << "Введите инфиксную форму алгебраической записи  " << endl;
	cin >> av;
	int i1=av.length();
	int i2(0); 
	char skob='%';
	cout << endl << "Постфиксная форма алгебраической записи  " << endl;
	for (int i = 0; i < i1; i++)
	{
		switch (av[i])
		{
		
		case '+':
			cout << " ";
			if (av[i + 1] == '(') skob = '+';
			else
			{
				st(&head, &av[i]); i2++;
			}
			break;
		case '-':
			cout << " ";
			if (av[i + 1] == '(') skob = '-';
			else {
				st(&head, &av[i]); i2++;
			}
			break;
		case '*':
			cout << " ";
			if (av[i + 1] == '(') skob = '*';
			else
			{
				st(&head, &av[i]); i2++;
			}
			break;
		case '/':
			cout << " ";
			if (av[i + 1] == '(') skob = '/';
			else {

				st(&head, &av[i]); i2++;
			}
			break;
		case '(':
			cout << " ";
			if (tt == 0) delete_s(&head, &i2, &skob);
			else tt = 0;
			st(&head, &av[i]); i2++;
			break;
		case ')':
			cout << " ";
			
			delete_s(&head, &i2, &skob);
			if (skob != '%') cout << skob;
			break;
		default:
			cout << av[i];
			break;


		}
		
		
	}
	delete_s(&head, &i2, &skob);

	return 0;
}