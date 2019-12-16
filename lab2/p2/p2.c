//2. Кто выполняется первым после fork: отец или сын? Написать программу, которую можно использовать для проверки данной ситуации.
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char * argv[]){
    int pid;
    printf("Привет, я  ");    
	
	pid = fork();
	if (pid == -1){
		perror("fork");
		exit(1);
	}
	if (pid == 0){
		printf("Потомок\n");
	}
	else{
		printf("Родитель\n");
	}
    return 0;
}

