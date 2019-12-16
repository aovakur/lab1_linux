/*
 * 3.Написать программу, исключающую появление зомби для завершающихся порожденных процессов.
*/
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char * argv[]){
    int pid;
    
    struct sigaction act;
    act.sa_handler = SIG_DFL;
    act.sa_flags = SA_NOCLDWAIT;
    
    if (sigaction(SIGCHLD, &act, NULL) == -1){
        perror("sigaction error");
    }

    if((pid=fork()) == -1){
        perror("[P] fork error");
        exit(0);
    }

    if(pid){//родитель
        printf("[P] Это сообщение выведено из родительского процесса\n");
        printf("[P] fork returned = %d\n", pid);
        printf("[P] Process group = %d\n",getpgrp());
        printf("[P] PID = %d\n",getpid());
        printf("[P] PPID = %d\n",getppid());
        printf("[P] Ожидаем завершения дочернего процесса\n");
        while(1){
        }
    }
    else{  //дочерний процесс
        printf("[C] Это сообщение выведено из дочернего процесса\n");
        printf("[C] fork returned = %d\n", pid);
        printf("[C] Process group = %d\n",getpgrp());
        printf("[C] PID = %d\n",getpid());
        printf("[C] PPID = %d\n",getppid());
    }
    return 0;
}
