#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char * argv[], char * envp[]){
    printf("[SUB] Program started!\n");
    int i;
    printf("\n[ARG] Arguments:\n");
    for(i = 0; i < argc; i++){
        printf("[ARG] Argument %d = %s\n", i, *(argv+i));
    }
    printf("\n[ENV] Environment:\n");
	char *str = *envp;
	for (i = 1; str != NULL; ++i){
		printf("[ENV]%s\n", str);
		str = *(envp + i);
    }
    printf("Exit from program!\n");
    exit(0);
}
