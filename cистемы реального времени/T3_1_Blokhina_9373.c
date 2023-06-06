/*
* ��������: ������� ��������, ������ � 9373
* �������: <� 3> <���������-�����������>
* ���� ����������: 23.03.2023
* ������: <� 1>
*
* ������ ��� ���������� � ������� ���������:
* gcc -o T3_1 T3_1_Blokhina_9373.c
*./T3_1
*/
// ------------------------------------------- //
/*
* ����� �������� ���������:
� ������ ������� ������������ �������� � �������� ��� ������������� ������� � ����� ����������.
� ������� Consumer ���������� ������� ���������� ������ �� ������. � ����� ������� �������, ����� � ������ �������� ������, 
��� �������������� � ������� �������� sem_full. ����� ������� ��������� ������� sem_mutex ��� ����, ����� ������������� ������������� ������ � ���������� Buffer � ���������� �� ���. 
����� ���������� �������� ������ �� ������, ����� ���������� �������� ���������� Buffer. ����� ���������� ������������� �������� sem_mutex � ���������� �������� sem_empty, 
����� ������������� ��� �������� ������ � �����. ����� ����� ������� �������� �� �������� �����, ������������ � ��������� TIME_1, ����� ���� ������� �� ����� �����, 
������� ������ � ������� ������ ���������� �������.
� ������� Supplier ���������� ������� ���������� ������ � �����. � ����� ������� �������, ����� � ������ �������� ��������� �����, ��� �������������� � ������� �������� sem_empty. 
����� ������� ��������� ������� sem_mutex.����� ���������� ���������� ������ � �����, ����� ���������� �������� ���������� Buffer. 
����� ���������� ������������� �������� sem_mutex � ���������� �������� sem_full, 
����� ����������� ��� ������� ������ �� ������. ����� ����� ������� �������� �� �������� �����, ������������ � ��������� TIME_2, ����� ���� ������� �� ����� �����, 
������� ������ � ������� ������ ���������� �������.
� ������� main ��������� ��� ������: thread_Cons � thread_Sup, ������� ��������� ������� Consumer � Supplier ��������������. 
����� ������� ������� ���������� ���������� ���� ������� � ������� ��������� ����� ��������.

*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 10
#define TIME_1 1
#define TIME_2 1

int Buffer = 0;
sem_t sem_empty, sem_full, sem_mutex;

void* Consumer(void* args)
{
	while (1)
	{
		time_t start_time = time(NULL);
		if (sem_wait(&sem_full) != 0) {
			perror("sem_wait");
			exit(EXIT_FAILURE);
		}
		if (sem_wait(&sem_mutex) != 0) {
			perror("sem_wait");
			exit(EXIT_FAILURE);
		}

		Buffer--;

		if (sem_post(&sem_mutex) != 0) {
			perror("sem_post");
			exit(EXIT_FAILURE);
		}
		if (sem_post(&sem_empty) != 0) {
			perror("sem_post");
			exit(EXIT_FAILURE);
		}
		sleep(TIME_1);
		time_t end_time = time(NULL);
		printf("Consumer: %ld sec\n", end_time - start_time);
	};
	return EXIT_SUCCESS;
}

void* Supplier(void* args)
{
	while (1)
	{
		time_t start_time = time(NULL);
		if (sem_wait(&sem_empty) != 0) {
			perror("sem_wait");
			exit(EXIT_FAILURE);
		}
		if (sem_wait(&sem_mutex) != 0) {
			perror("sem_wait");
			exit(EXIT_FAILURE);
		}

		Buffer++;

		if (sem_post(&sem_mutex) != 0) {
			perror("sem_post");
			exit(EXIT_FAILURE);
		}
		if (sem_post(&sem_full) != 0) {
			perror("sem_post");
			exit(EXIT_FAILURE);
		}
		sleep(TIME_2);
		time_t end_time = time(NULL);
		printf("Supplier: %ld sec\n", end_time - start_time);
	};
	return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
	pthread_t thread_Cons, thread_Sup;
	sem_init(&sem_empty, 0, BUFFER_SIZE);
	sem_init(&sem_full, 0, 0);
	sem_init(&sem_mutex, 0, 1);
	pthread_create(&thread_Cons, NULL, Consumer, NULL);
	pthread_create(&thread_Sup, NULL, Supplier, NULL);
	pthread_join(thread_Cons, NULL);
	pthread_join(thread_Sup, NULL);
	sem_destroy(&sem_empty);
	sem_destroy(&sem_full);
	sem_destroy(&sem_mutex);
	return 0;
}

/*Consumer: 1 sec
Supplier: 1 sec
Supplier: 1 sec
Consumer: 1 sec
Consumer: 1 sec
Supplier: 1 sec
Supplier: 1 sec
Consumer: 1 sec
Supplier: 1 sec
Consumer: 1 sec
Consumer: 1 sec
Supplier: 1 sec
Consumer: 1 sec
Supplier: 1 sec
Consumer: 1 sec
Supplier: 1 sec

*/