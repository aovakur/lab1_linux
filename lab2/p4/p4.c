/*
 * 4. Изменить программу п. 3 так, чтобы родительский процесс завершился раньше порожденного. 
 * Какой процесс становится родительским для порожденного после того, как исходный родительский процесс завершился?
 
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
    int pid;
    if((pid = fork()) == -1){

        perror("[P] fork error");
        exit(0);
    }

    if(pid>0){ //родитель
        printf("[P] Это сообщение выведено из родительского процесса\n");
        printf("[P] fork returned (дочерний) = %d\n", pid); //уникальный идентификатор 
        printf("[P] Process group = %d\n",getpgrp()); 
        printf("[P] PID = %d\n", getpid());
        printf("[P] PPID = %d\n",getppid());
    }
    else{ //дочерний

        printf("\n\tОжидание...\n");
        sleep(5);
        printf("[C] Это сообщение выведено из дочернего процесса\n");
        printf("[C] fork returned = %d\n", pid);
        printf("[C] Process group = %d\n", getpgrp());
        printf("[C] PID = %d\n", getpid());
        printf("[C] PPID = %d\n", getppid()); // получил ppid init

    }
	
	return 0;
}








/*
 * fork выделяет новый pid для процесса но оставляет старыми значения стека, сегмента кода, данных...
 * ./n3 prog
*/
