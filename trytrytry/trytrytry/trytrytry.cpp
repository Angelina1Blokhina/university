#include <thread>
#include <chrono>
#include <iostream>
using namespace std;




void DoWork(int &a) 
{
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "========\t" << "DW STARTED\t======" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	a = a * 2;
	//this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "ID потока = " << this_thread::get_id() << endl;
	cout << "========\t" << "DW STOPPED\t======" << endl;
	
}

/*void sum(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "========\t" << "sl STARTED\t======" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "a+b= " << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "========\t" << "sl STOPPED\t======" << endl;

}*/



int main()
{
	setlocale(LC_ALL, "ru");
	//DoWork();
	/*thread th(DoWork);
	thread th6(DoWork);
	th.detach();
	th6.detach();*/

	int s(5);


	thread th(DoWork,std::ref(s));
	
	
	//sl(2, 3);
	for (int i = 0; i<5; i++)
	{
		cout << "ID потока " << this_thread::get_id() << "   main"<<i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	th.join();

	cout << s << endl;




	cout << "STAR MAIN" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));


	cout << this_thread::get_id() << endl;

	return 0;
}

