/*
* Выполнил: Блохина Ангелина, группа № 9373
* Задание: <№ 3> <Поставщик-потребитель>
* Дата выполнения: 23.03.2023
* Версия: <№ 1>
*
* Скрипт для компиляции и запуска программы:
* gcc -o T3_2 T3_2_Blokhina_9373.c
*./T3_2
*/
// ------------------------------------------- //
/*
* Общее описание программы:
В данном примере используются мьютексы и условные переменные для синхронизации доступа к общей переменной.
В функции Consumer происходит попытка захвата мьютекса и ожидание сигнала от поставщика в случае, если буфер пуст. 
После получения сигнала потребитель уменьшает значение переменной Buffer, освобождает мьютекс и выполняет некоторую работу. В данном примере это ожидание в течение заданного времени.
В функции Supplier также происходит попытка захвата мьютекса и увеличение значения переменной Buffer. После этого поставщик отправляет сигнал ожидающему потребителю и освобождает мьютекс. Затем поставщик также выполняет некоторую работу, ожидая в течение заданного времени.
Функция main создает два потока, запускает их и ждет их завершения. В данном примере используется обычный мьютекс и условная переменная, чтобы синхронизировать доступ к общей переменной.

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
		time_t start_time = time(NULL);  // время начала работы в критической секции
		pthread_mutex_lock(&mutex);	// за хват мьютекса
		while (Buffer == 0)              // проверка условия
			pthread_cond_wait(&cond, &mutex);   // ожидание сигнала от другого потока
		Buffer--;
		pthread_mutex_unlock(&mutex);    // освобождение мьютекса
		sleep(TIME_1);
		time_t end_time = time(NULL);       // время окончания работы в критической секции
		printf("Consumer: %ld sec\n", end_time - start_time);

	};
	return EXIT_SUCCESS;
}

void* Supplier(void* args)
{
	while (1)
	{
		time_t start_time = time(NULL);
		pthread_mutex_lock(&mutex);      // захват мьютекса
		Buffer++;
		pthread_cond_signal(&cond);      // отправка сигнала ожидающему потоку
		pthread_mutex_unlock(&mutex);    // освобождение мьютекса
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