
#include <iostream>
using namespace std;
void uu1(int y[7])
{
	for (int i = 0; i < 7; i++)
	{
		cout << y[i];
	}
}
void uu(int*A)
{
	const int h = 7;
	int B[h];
	for (int i = 0; i < 7; i++)
	{
		B[i]=A[i];
	}
	
	uu1(B);
}
int main()
{
	const int n = 7;
	cout << "Star";
	int A[n];
	for (int i = 0; i < 7; i++)
	{
		 cin>>A[i];
	}
	uu(&A[0]);

	return 0;
}
