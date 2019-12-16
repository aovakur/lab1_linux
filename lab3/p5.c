/*
 * 5. Из родительского процесса послать в порожденный процесс сигнал (SIGUSR1). 
 * Посмотреть, какой статус будет передан в родительский процесс в этом случае. 
 * Сколько итераций выполнится в порожденном процессе?
*/

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
        exit (1);
    }
    if(pid){
        printf("[P] Fork returned %d\n", pid);
        printf("[P] PID = %d\n", getpid());
        int code;
        if(kill(pid, SIGUSR1) == -1)
        //SIGUSR1 сигнал для завершения процесса, Номер 10
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
    }
    return 0;
}
