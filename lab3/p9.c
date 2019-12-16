/*
	*9. Включить в порожденный процесс вместо системного вызова kill 
	* системный вызов alarm с перехватом и без перехвата сигнала. Что изменится?
*/


#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void signal_handler(int);
int main (int argc, char * argv[]) {
    int pid;
    if((pid = fork()) == -1) {
        perror("fork error");
        exit (1);
    }
    if(pid){
        printf("[P] Fork returned %d\n", pid);
        printf("[P] PID = %d\n", getpid());
        int code;
        if(wait(&code) == -1){
            perror("wait error");
        }
        else{
            printf("Exit status: %d\n", code);
        }
    }
    else{

        printf("[C] Fork returned %d\n", pid);
        printf("[C] Дочерний процесс создан! PID = %d\n", getpid());
       
		struct sigaction act;
		act.sa_handler = signal_handler;
		if (sigaction(SIGALRM, &act, NULL) == -1){
			perror("sigaction error");
		}
		alarm(1);
        for(int i = 0;i < 100;i++){
            
            for (int j = 0; j < 10000; ++j){
				for (int k = 0; k < 1000; ++k){}
			}
            printf("%d ",i);
        }
    }
    return 0;
}

void signal_handler(int sigid){
    printf("signal catched by handler!\n");
}
