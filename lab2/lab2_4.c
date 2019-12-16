#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	pid_t pid = fork();
	
	if (pid == 0) //дочерний
	{
		pid_t ppid = getppid();
		printf("son ppid before father's death: %d\n", ppid);
		sleep(2);
		ppid = getppid();
		printf("son ppid after father's death: %d\n", ppid);
	}
	else
	{
		sleep(1);
	}
	return 0;
}

