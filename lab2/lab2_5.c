#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	pid_t pid = fork();
	
	if (pid == 0) //дочерний
	{
		printf("%d\n", getpid());
		return 0;
	}
	else
	{
		for(;;);
	}
	return 0;
}

