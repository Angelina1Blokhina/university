/*
* Выполнил: <Блохина Ангелина> <9373>
* Задание: <1> <Обеспечение таймаута>
* Дата выполнения: <18.02.2023>
* Версия: <№ 1>
*
* Скрипт для компиляции и запуска программы:
* $ cc Т1_Блохина_9373.c -o Т1_Блохина_9373.c
* ./Т1_Блохина_9373
*/
// ------------------------------------------- //
/*
* Общее описание программы:
*В данной программе использовались функции: signal() - обработка сигналов (библиотека <signal.h>) в функцию alarmHandler передается сигнал SIGALRM, в функцию deadlineHandler - сигнал SIGRTMIN;
время начала и окончания работы функции реализовано с помощью функции clock_gettime() (библиотека time.h)

*/
// ------------------------------------------- //



#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>

#define SOFT_DT 4 
#define MIN_TIME (500000 - (500000 * SOFT_DT / 100))
#define MAX_TIME (500000 + (500000 * SOFT_DT / 100))

void doControl(int x) {
	int time;
	int dt;

	srand(::time(NULL));
	dt = MIN_TIME + (rand() % (MAX_TIME - MIN_TIME + 1));//генерация dt
	time = 500000 + dt;

	printf("########## %d \n", time);

	if (x == 0) while (1);
	usleep(time);
}

void alarmHandler(int signum) {
	printf(" «#####-- Restart requered! --#####»");
	raise(SIGUSR1);

}

void deadlineHandler(int signum)
{
	printf(" ####   Deadline exceeded   ####");
}

int main() {
	const int hard_deadline = 1;
	struct timespec start, end;
	int x = 1;
	signal(SIGALRM, alarmHandler);
	signal(SIGRTMIN, deadlineHandler);

	while (true) {
		alarm(0);
		alarm(hard_deadline);
		clock_gettime(CLOCK_REALTIME, &start);
		doControl(x);
		clock_gettime(CLOCK_REALTIME, &end);

		double execution_time = 1000000000 * (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec);//расчет время работы функции в наносекундах
		// проверяем время работы функции 
		if (execution_time > 0.52 * 1000000000)
		{
			raise(SIGRTMIN);
		}
		else {
			sleep(3);
		}
		x = rand() % 2;// Генерация рандомного значения x

	}

	return 0;
}

/*
########## 985671
 ####   Deadline exceeded   ############## 985232
 ####   Deadline exceeded   ############## 989101
 ####   Deadline exceeded   ############## 998042
 ####   Deadline exceeded   ############## 980782
User defined signal 1

	*/
