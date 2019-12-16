/*
* 7. Модифицировать программу, включив в нее setpgrp в порожденный процесс до того, как он будет выполнять pause. 
* Повлияет ли на порожденный процесс нажатие клавиши прерывания в тот момент, когда родительский процесс "спит"? 
* Будет ли показан порожденный процесс в выводе команды ps?
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
        if(pause() == -1){
            perror("");
        }
        exit(0);
    }
    else{    //дочерний
        printf("[C] Это сообщение выведено из дочернего процесса\n");
        printf("[C] fork returned = %d\n", pid);
        printf("[C] Process group = %d\n",getpgrp());
        printf("[C] PID = %d\n",getpid());
        printf("[C] PPID = %d\n",getppid());
        //   https://www.opennet.ru/man.shtml?topic=setpgrp&category=2&russian=0
        if(setpgrp() == -1){
            perror("setpgrp error");
        }
        else{
            printf("[C] Process group set to %d\n", getpgrp());
        }
        if(pause() == -1){
            perror("pause error");
        }
        exit(0);
    }
}
