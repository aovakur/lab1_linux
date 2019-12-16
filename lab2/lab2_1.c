#include <stdio.h>

int printenv()
{
	extern char **environ;
	int count = 0;
	while(environ[count] != NULL)
	{
		printf("%s\n", environ[count]);
		count++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	printenv();
	int i;
	for(i = 1; i < argc; i++)
	{
		if (putenv(argv[i]) != 0)
		{
			char *buf;
			sprintf("Can't putenv: %s\n", argv[i]);
			perror(buf);
		}
	}
	printf("\n**********\n\n");
	printenv();
	
	return 0;
}

