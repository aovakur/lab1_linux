#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int pid = fork();
	
	if (pid == 0)
	{
		fprintf(stderr,"%d", 0);			
	}
	else
	{
		fprintf(stderr,"%d", 1);
	}
	return 0;
}

