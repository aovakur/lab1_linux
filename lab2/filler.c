#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int fd = creat("file", 0777);
	int i;
	int max = argc == 2 ? atoi(argv[1]) : 10000;
	for (i = 0; i < max; i++)
	{
		char buf[10000];
		sprintf(buf, "_%d_", i);
		int bytes = 2;
		int j = i;
		while(j != 0)
		{
			j /= 10;
			bytes++;
		}
		write(fd, buf, bytes);
	}
	return 0;
}

