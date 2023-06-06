/*
* Выполнил: Блохина Ангелина, группа № 9373
* Задание: <№ 2> <Вызов лифта>
* Дата выполнения: 25.02.2023
* Версия: <№ 1>
*
* Скрипт для компиляции и запуска программы:
* gcc -o T2 T2_Blokhina_9373.c
*./T2
*/
// ------------------------------------------- //
/*
* Общее описание программы:
Данная программа моделирует работу автомата управления лифтом при его вызове.
Функция main() инициализирует маску сигналов и создает поток для функции push_button. После завершения работы потока, программа завершается.
Функция push_button() является потоком, который ожидает ввода с клавиатуры. Когда пользователь нажимает клавишу, функция отправляет сигнал 
	с помощью функции kill на процесс, который обрабатывает сигналы.
Функция lift_control() обрабатывает сигналы, отправляемые функцией push_button. Она основывается на текущем состоянии лифта и сигнале, который 
	был отправлен. В зависимости от этого она изменяет состояние лифта и выполняет соответствующие действия.
Функция move() имитирует движение лифта.

*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

#define TOP 0
#define BOTTOM 1
#define THIS_FLOOR 2
#define    Up	      SIGUSR1  // Сигналы реального времени
#define    Down	      SIGUSR2

int state = THIS_FLOOR;

void move(int signo) {
    if (signo == Up) {
        int n = 3;
        for (int i = 1; i <= n; i++) {
            printf("*** Go UP\n");
            usleep(500000);
        }
        state = TOP;
        printf("state %d\n", state);
    } else if (signo == Down) {
        int n = 3;
        for (int i = 1; i <= n; i++) {
            printf("*** Go DOWN\n");
            usleep(500000);
        }
        state = BOTTOM;
        printf("state %d\n", state);
    }
}

void lift_control(int signo, siginfo_t* info, void* nk) {
    switch (state) {
        case THIS_FLOOR:
            if (signo == Up) {
                printf("This Floor, door is opened \n"); 
                sleep(1); 
                move(signo); 
            } else if (signo == Down) {
               
                printf("This Floor, door is opened \n"); 
                sleep(1); 
                move(signo);
            }
            break;
        case TOP:
            if (signo == Up){
            	move(Down); 
            	printf("This Floor, door is opened \n"); 
            	sleep(1); 
            	move(signo); 
            } else if (signo == Down) {
            	move(signo); 
            	printf("This Floor, door is opened \n"); 
            	sleep(1); 
            	move(signo); 
            }
            break;
        case BOTTOM:
            if (signo == Up) {
                move(signo); 
                printf("This Floor, door is opened \n"); 
                sleep(1); 
                move(signo); 
                
            } else if(signo == Down){
            	move(Up); 
            	printf("This Floor, door is opened \n"); 
            	sleep(1); 
            	move(signo); 
            }
            break;
    }
}

void* push_button(void* args) {
    char ch;
	// Здесь инициализируется структура sigaction
    struct sigaction act;
    act.sa_sigaction = lift_control;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO; //флаг SA_SIGINFO указывает, что третий аргумент функции lift_control будет указатель на структуру siginfo_t, содержащую дополнительную информацию о сигнале
    sigaction(Up, &act, NULL);
    sigaction(Down, &act, NULL);
    while (ch != 'q') {
        ch = getchar();
        switch (ch) {
            case 'u':
                kill(getpid(), Up);//функция kill() отвечает за посылку сигнала
                break;
            case 'd':
                kill(getpid(), Down);
                break;
            case 'q':
                break;
        }
    }
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    pthread_t t;
    printf("Start\n");
	//Инициализируется маска сигналов
	sigset_t set;
	sigfillset(&set); // Устанавливаем все сигналы
	sigdelset(&set, SIGUSR1); // Удаляем SIGUSR1 из маски
	sigdelset(&set, SIGUSR2); // Удаляем SIGUSR2 из маски
	sigprocmask(SIG_SETMASK, &set, NULL);

    pthread_create(&t, NULL, &push_button, NULL);
    pthread_join(t, NULL);
    printf("Finish\n");
    return EXIT_SUCCESS;
}
/*
Start
d
This Floor, door is opened
*** Go DOWN
*** Go DOWN
*** Go DOWN
state 1
d
*** Go UP
*** Go UP
*** Go UP
state 0
This Floor, door is opened
*** Go DOWN
*** Go DOWN
*** Go DOWN
state 1
u
*** Go UP
*** Go UP
*** Go UP
state 0
This Floor, door is opened
*** Go UP
*** Go UP
*** Go UP
state 0
u
*** Go DOWN
*** Go DOWN
*** Go DOWN
state 1
This Floor, door is opened
*** Go UP
*** Go UP
*** Go UP
state 0
q
Finish

*/
