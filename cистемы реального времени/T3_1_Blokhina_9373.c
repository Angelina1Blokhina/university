/*
* Выполнил: Блохина Ангелина, группа № 9373
* Задание: <№ 3> <Поставщик-потребитель>
* Дата выполнения: 23.03.2023
* Версия: <№ 1>
*
* Скрипт для компиляции и запуска программы:
* gcc -o T3_1 T3_1_Blokhina_9373.c
*./T3_1
*/
// ------------------------------------------- //
/*
* Общее описание программы:
В данном примере используются мьютексы и семафоры для синхронизации доступа к общей переменной.
В функции Consumer реализован процесс считывания данных из буфера. В цикле функция ожидает, когда в буфере появятся данные, 
это осуществляется с помощью семафора sem_full. Затем функция блокирует семафор sem_mutex для того, чтобы предотвратить одновременную запись в переменную Buffer и считывание из нее. 
Далее происходит удаление данных из буфера, путем уменьшения значения переменной Buffer. Затем происходит разблокировка семафора sem_mutex и увеличение семафора sem_empty, 
чтобы производитель мог добавить данные в буфер. После этого функция засыпает на заданное время, определенное в константе TIME_1, после чего выводит на экран время, 
которое прошло с момента начала выполнения функции.
В функции Supplier реализован процесс добавления данных в буфер. В цикле функция ожидает, когда в буфере появится свободное место, это осуществляется с помощью семафора sem_empty. 
Затем функция блокирует семафор sem_mutex.Далее происходит добавление данных в буфер, путем увеличения значения переменной Buffer. 
Затем происходит разблокировка семафора sem_mutex и увеличение семафора sem_full, 
чтобы потребитель мог удалить данные из буфера. После этого функция засыпает на заданное время, определенное в константе TIME_2, после чего выводит на экран время, 
которое прошло с момента начала выполнения функции.
В функции main создаются два потока: thread_Cons и thread_Sup, которые выполняют функции Consumer и Supplier соответственно. 
Затем функция ожидает завершения выполнения этих потоков и удаляет созданные ранее семафоры.

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