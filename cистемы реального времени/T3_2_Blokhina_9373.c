/*
* ��������: ������� ��������, ������ � 9373
* �������: <� 3> <���������-�����������>
* ���� ����������: 23.03.2023
* ������: <� 1>
*
* ������ ��� ���������� � ������� ���������:
* gcc -o T3_2 T3_2_Blokhina_9373.c
*./T3_2
*/
// ------------------------------------------- //
/*
* ����� �������� ���������:
� ������ ������� ������������ �������� � �������� ���������� ��� ������������� ������� � ����� ����������.
� ������� Consumer ���������� ������� ������� �������� � �������� ������� �� ���������� � ������, ���� ����� ����. 
����� ��������� ������� ����������� ��������� �������� ���������� Buffer, ����������� ������� � ��������� ��������� ������. � ������ ������� ��� �������� � ������� ��������� �������.
� ������� Supplier ����� ���������� ������� ������� �������� � ���������� �������� ���������� Buffer. ����� ����� ��������� ���������� ������ ���������� ����������� � ����������� �������. ����� ��������� ����� ��������� ��������� ������, ������ � ������� ��������� �������.
������� main ������� ��� ������, ��������� �� � ���� �� ����������. � ������ ������� ������������ ������� ������� � �������� ����������, ����� ���������������� ������ � ����� ����������.

*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TIME_1 1
#define TIME_2 1
int Buffer = 0;
pthread_cond_t cond;
pthread_mutex_t mutex;

void* Consumer(void* args)
{
	while (1)
	{
		time_t start_time = time(NULL);  // ����� ������ ������ � ����������� ������
		pthread_mutex_lock(&mutex);	// �� ���� ��������
		while (Buffer == 0)              // �������� �������
			pthread_cond_wait(&cond, &mutex);   // �������� ������� �� ������� ������
		Buffer--;
		pthread_mutex_unlock(&mutex);    // ������������ ��������
		sleep(TIME_1);
		time_t end_time = time(NULL);       // ����� ��������� ������ � ����������� ������
		printf("Consumer: %ld sec\n", end_time - start_time);

	};
	return EXIT_SUCCESS;
}

void* Supplier(void* args)
{
	while (1)
	{
		time_t start_time = time(NULL);
		pthread_mutex_lock(&mutex);      // ������ ��������
		Buffer++;
		pthread_cond_signal(&cond);      // �������� ������� ���������� ������
		pthread_mutex_unlock(&mutex);    // ������������ ��������
		sleep(TIME_2);
		time_t end_time = time(NULL);
		printf("Supplier: %ld sec\n", end_time - start_time);

	};
	return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {
	pthread_t thread_Cons, thread_Sup;
	pthread_create(&thread_Cons, NULL, &Consumer, NULL);
	pthread_create(&thread_Sup, NULL, &Supplier, NULL);
	pthread_join(thread_Cons, NULL);
	pthread_join(thread_Sup, NULL);
	return EXIT_SUCCESS;
}

/*
Consumer: 1 sec
Supplier: 1 sec
Supplier: 1 sec
Consumer: 1 sec
Consumer: 1 sec
Supplier: 1 sec
Consumer: 1 sec
Supplier: 1 sec
Consumer: 1 sec*/