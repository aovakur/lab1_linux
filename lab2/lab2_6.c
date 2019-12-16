#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	pid_t pid = fork();
	
	if (pid == 0) //дочерний
	{
		printf("son pid: %d\n", getpid());
		printf("son ppid: %d\n", getppid());
		printf("son grp: %d\n", getpgid());
		pause();		
	}
	else //родительский
	{
		printf("father pid: %d\n", getpid());
		printf("father ppid: %d\n", getppid());
		printf("father grp: %d\n", getpgid());
		pause();
	}
	return 0;
}

