/*
* ��������: ������� ��������, ������ � 9373
* �������: <� 2> <����� �����>
* ���� ����������: 25.02.2023
* ������: <� 1>
*
* ������ ��� ���������� � ������� ���������:
* gcc -o T2 T2_Blokhina_9373.c
*./T2
*/
// ------------------------------------------- //
/*
* ����� �������� ���������:
������ ��������� ���������� ������ �������� ���������� ������ ��� ��� ������.
������� main() �������������� ����� �������� � ������� ����� ��� ������� push_button. ����� ���������� ������ ������, ��������� �����������.
������� push_button() �������� �������, ������� ������� ����� � ����������. ����� ������������ �������� �������, ������� ���������� ������ 
	� ������� ������� kill �� �������, ������� ������������ �������.
������� lift_control() ������������ �������, ������������ �������� push_button. ��� ������������ �� ������� ��������� ����� � �������, ������� 
	��� ���������. � ����������� �� ����� ��� �������� ��������� ����� � ��������� ��������������� ��������.
������� move() ��������� �������� �����.

*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

#define TOP 0
#define BOTTOM 1
#define THIS_FLOOR 2
#define    Up	      SIGUSR1  // ������� ��������� �������
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
	// ����� ���������������� ��������� sigaction
    struct sigaction act;
    act.sa_sigaction = lift_control;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO; //���� SA_SIGINFO ���������, ��� ������ �������� ������� lift_control ����� ��������� �� ��������� siginfo_t, ���������� �������������� ���������� � �������
    sigaction(Up, &act, NULL);
    sigaction(Down, &act, NULL);
    while (ch != 'q') {
        ch = getchar();
        switch (ch) {
            case 'u':
                kill(getpid(), Up);//������� kill() �������� �� ������� �������
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
	//���������������� ����� ��������
	sigset_t set;
	sigfillset(&set); // ������������� ��� �������
	sigdelset(&set, SIGUSR1); // ������� SIGUSR1 �� �����
	sigdelset(&set, SIGUSR2); // ������� SIGUSR2 �� �����
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
