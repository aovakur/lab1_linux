/*
* Изменить программу п. 3 так, чтобы родительский процесс выполнялся, не ожидая завершения порожденного процесса. 
* Что произойдет с порожденным процессом, когда он завершится? Как убить зомби?
 */
#include <stdlib.h>
#include <stdio.h>	
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
    int pid;

    if((pid=fork()) == -1){
        perror("[P] fork error");
        exit(0);
    }

    if(pid>0){//родитель
        printf("[P] Это сообщение выведено из родительского процесса\n");
        printf("[P] fork returned = %d\n", pid);
        printf("[P] Process group = %d\n",getpgrp());
        printf("[P] PID = %d\n",getpid());
        printf("[P] PPID = %d\n",getppid());
        printf("[P] Ожидаем завершения дочернего процесса\n");
        sleep(20);//задержка выполнения программы
		exit(0);
    }
    else{//дочерний
        printf("[C] Это сообщение выведено из дочернего процесса\n");
        printf("[C] fork returned = %d\n", pid);
        printf("[C] Process group = %d\n",getpgrp());
        printf("[C] PID = %d\n",getpid());
        printf("[C] PPID = %d\n",getppid());
        exit(0);
    }
    return 0;
}

