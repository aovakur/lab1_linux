/*
* 10. Создать (с помощью связки fork - exec) параллельный процесс. 
* Имя исполняемого файла для exec передается с помощью аргумента командной строки. 
* Передать в порожденный процесс некоторую информацию через список параметров (список аргументов в функции main). 
* Каждый процесс (и родительский, и порожденный) должен вывести на экран список переданных ему аргументов и свое окружение.
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char * argv[], char * envp[]){
    if(argc < 2){
        printf("Usage: %s filename \n", argv[0]);
    }
    else{
        int code = fork();
        if(code == -1){
            perror("fork error");
            exit(1);
        }
        if(code>0){ //родитель
            printf("[P] Parent PID = %d\n", getpid());
			printf("----------------------------------");
			int i;
			printf("\n[ARG] Arguments:\n");
			for(i = 1; i < argc; i++){
				printf("[ARG] Argument %d = %s\n", i, *(argv+i));
			}
			printf("\n[ENV] Environment:\n");
			char *str = *envp;
			for (i = 1; str != NULL; ++i){
				printf("[ENV]%s\n", str);
				str = *(envp + i);
			}
			printf("----------------------------------");
            printf("[P] Child process created! \n");
            exit(0);
        }
        else{		//сын выполняет execve
            printf("[C] Child PID = %d\n", getpid());
            execve(argv[1], (argv+2),envp); 
            /*
             * выполняет программу, заданную параметром argv[1]
             * (argv+1) список параметров
            */
        }
    }
	return 0;
}
