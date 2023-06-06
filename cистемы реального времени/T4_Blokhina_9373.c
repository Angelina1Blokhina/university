/*
* Выполнил: Блохина Ангелина, группа № 9373
* Задание: <№ 4> <Модель циклической системы управления>
* Дата выполнения: 30.03.2023
* Версия: <№ 1>
*
* Скрипт для компиляции и запуска программы:
* gcc -o T4 T4_Blokhina_9373.c
*./T4
*/
// ------------------------------------------- //
/*
* Общее описание программы:
В данном коде реализованы три периодических программных таймера, каждый с заданным периодом вызова управляющей процедуры. 
Управляющие процедуры для каждого таймера выводят в консоль информацию о моменте вызова, прошедшем времени с предыдущего вызова и константном периоде вызова.
Функция createTimer создает таймер, используя функцию timer_create с сигналом SIGEV_SIGNAL, что означает использование сигнала в качестве схемы уведомления. 
Функция signal назначает функции управления таймером для каждого сигнала.
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#define TIMER_SIG1 SIGUSR1
#define TIMER_SIG2 SIGUSR2
#define TIMER_SIG3 SIGALRM

timer_t timer1_id, timer2_id, timer3_id;


void doControl_1(int signal_n) {
	static struct timespec prev_time = { 0 };
	struct timespec current_time;
	clock_gettime(CLOCK_MONOTONIC, &current_time);
	double elapsed_time = (current_time.tv_sec - prev_time.tv_sec) * 1000.0 +
		(current_time.tv_nsec - prev_time.tv_nsec) / 1000000.0;
	prev_time = current_time;
	printf("Procedure #1 callmoment: [%ld.%ld] ---- period %f ms, const  period %d ms\n",
		current_time.tv_sec, current_time.tv_nsec, elapsed_time, 500);
}

void doControl_2(int signal_n) {
	static struct timespec prev_time = { 0 };
	struct timespec current_time;
	clock_gettime(CLOCK_MONOTONIC, &current_time);
	double elapsed_time = (current_time.tv_sec - prev_time.tv_sec) * 1000.0 +
		(current_time.tv_nsec - prev_time.tv_nsec) / 1000000.0;
	prev_time = current_time;
	printf("Procedure #2 callmoment: [%ld.%ld] ---- period %f ms, const  period %d ms\n",
		current_time.tv_sec, current_time.tv_nsec, elapsed_time, 750);
}

void doControl_3(int signal_n) {
	static struct timespec prev_time = { 0 };
	struct timespec current_time;
	clock_gettime(CLOCK_MONOTONIC, &current_time);
	double elapsed_time = (current_time.tv_sec - prev_time.tv_sec) * 1000.0 +
		(current_time.tv_nsec - prev_time.tv_nsec) / 1000000.0;
	prev_time = current_time;
	printf("Procedure #3 callmoment: [%ld.%ld] ---- period %f ms, const  period %d ms\n",
		current_time.tv_sec, current_time.tv_nsec, elapsed_time, 1000);
}

void createTimer(timer_t* timer_id, int period_ms, int signal) {
	struct sigevent sev;
	sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = signal;
	sev.sigev_value.sival_ptr = timer_id;
	timer_create(CLOCK_REALTIME, &sev, timer_id);

	struct itimerspec its;
	its.it_value.tv_sec = period_ms / 1000;
	its.it_value.tv_nsec = (period_ms % 1000) * 1000000;
	its.it_interval.tv_sec = its.it_value.tv_sec;
	its.it_interval.tv_nsec = its.it_value.tv_nsec;

	timer_settime(*timer_id, 0, &its, NULL);
}

int main() {
	signal(TIMER_SIG1, doControl_1);
	signal(TIMER_SIG2, doControl_2);
	signal(TIMER_SIG3, doControl_3);

	createTimer(&timer1_id, 500, TIMER_SIG1);
	createTimer(&timer2_id, 750, TIMER_SIG2);
	createTimer(&timer3_id, 1000, TIMER_SIG3);

	while (1);

	return 0;
}
/*
Procedure #1 callmoment: [110333.629277285] ---- period 110333629.277285 ms, const  period 500 ms
Procedure #2 callmoment: [110333.879363289] ---- period 110333879.363289 ms, const  period 750 ms
Procedure #3 callmoment: [110334.130166720] ---- period 110334130.166720 ms, const  period 1000 ms
Procedure #1 callmoment: [110334.130211459] ---- period 500.934174 ms, const  period 500 ms
Procedure #1 callmoment: [110334.629426859] ---- period 499.215400 ms, const  period 500 ms
Procedure #2 callmoment: [110334.629549796] ---- period 750.186507 ms, const  period 750 ms
Procedure #3 callmoment: [110335.129402766] ---- period 999.236046 ms, const  period 1000 ms
Procedure #1 callmoment: [110335.129461101] ---- period 500.034242 ms, const  period 500 ms
Procedure #2 callmoment: [110335.379421579] ---- period 749.871783 ms, const  period 750 ms
Procedure #1 callmoment: [110335.629261182] ---- period 499.800081 ms, const  period 500 ms
Procedure #3 callmoment: [110336.129310053] ---- period 999.907287 ms, const  period 1000 ms
Procedure #2 callmoment: [110336.129374554] ---- period 749.952975 ms, const  period 750 ms
Procedure #1 callmoment: [110336.129379601] ---- period 500.118419 ms, const  period 500 ms
Procedure #1 callmoment: [110336.629490726] ---- period 500.111125 ms, const  period 500 ms
Procedure #2 callmoment: [110336.879404461] ---- period 750.029907 ms, const  period 750 ms
Procedure #3 callmoment: [110337.129248269] ---- period 999.938216 ms, const  period 1000 ms
Procedure #1 callmoment: [110337.129296758] ---- period 499.806032 ms, const  period 500 ms
Procedure #2 callmoment: [110337.629412206] ---- period 750.007745 ms, const  period 750 ms
Procedure #1 callmoment: [110337.629488630] ---- period 500.191872 ms, const  period 500 ms
Procedure #3 callmoment: [110338.129294778] ---- period 1000.046509 ms, const  period 1000 ms
Procedure #1 callmoment: [110338.129346067] ---- period 499.857437 ms, const  period 500 ms
Procedure #2 callmoment: [110338.379584745] ---- period 750.172539 ms, const  period 750 ms
Procedure #1 callmoment: [110338.629352403] ---- period 500.006336 ms, const  period 500 ms
Procedure #3 callmoment: [110339.129246719] ---- period 999.951941 ms, const  period 1000 ms

*/