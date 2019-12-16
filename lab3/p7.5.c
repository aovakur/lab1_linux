/*
 * 5. Из родительского процесса послать в порожденный процесс сигнал (SIGUSR1). 
 * Посмотреть, какой статус будет передан в родительский процесс в этом случае. 
 * Сколько итераций выполнится в порожденном процессе?
 * 7. Повторить выполнение предыдущих пунктов задания, используя в порожденном процессе 
 * вместо вложенных циклов системный вызов pause. 
 * Что изменится? Как завершить процесс в случае выполнения с pause п. 4?
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
    if(pid>0){//родитель
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
    else{	//дочь
        printf("[C] Fork returned %d\n", pid);
        printf("[C] Дочерний процесс создан! PID = %d\n", getpid());
        for(int i = 0;i < 100;i++){
            pause();
            printf("%d ", i);
        }
    }
    return 0;
}
