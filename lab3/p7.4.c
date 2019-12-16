/*
 * 4. Создать длительный параллельный процесс 
 * (в порожденном процессе выполнять вложенные циклы, каждый на 100 или больше итераций, 
 * и выводить на экран номер итерации для внешнего цикла). 
 * Дождаться нормального завершения порожденного процесса. 
 * Посмотреть, какой статус будет передан в родительский процесс.
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
       
        for(int i = 0;i < 100;i++){
            pause();
            printf("%d ",i);
        }
    }
    return 0;
}


