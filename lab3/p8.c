/*
* 8. Включить в порожденный процесс системный вызов signal, 
* переопределяющий стандартную реакцию на сигнал 
* (для внешнего цикла установить в функции максимальное значение параметра цикла). 
* Что изменится?
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
        {
            perror("kill error");
        }
        if(wait(&code) == -1){
            perror("wait error");
        }
        printf("Exit status: %d\n", code);
    }
    else{
        signal(SIGUSR1, SIG_IGN);
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

