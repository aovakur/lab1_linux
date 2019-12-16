/*
 * 6. Повторить выполнение п. 5 задания, изменив сигнал, 
 * посылаемый в порожденный процесс. Что изменится?
*/
//поменялся exit status
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char * argv[]) {
    int pid;
    if((pid = fork()) == -1) {
        perror("fork error");
        exit(1);
    }
    if(pid){
        printf("[P] Fork returned %d\n", pid);
        printf("[P] PID = %d\n", getpid());
        int code;
        if(kill(pid, SIGINT) == -1)
        {
            perror("kill error");
        }
        if(wait(&code) == -1){
            perror("wait error");
        }
        printf("Exit status: %d\n", code);
    }
    else{

        printf("[C] Fork returned %d\n", pid);
        printf("[C] Дочерний процесс создан! PID = %d\n", getpid());
        for(int i = 0;i < 100;i++){
            for(int j = 0; j < 10000 ; j++);
            printf("%d ", i);
        }
        printf("[C] Процесс завершен! \n");
    }
    return 0;
}

