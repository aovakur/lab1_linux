#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
//#include <cstdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main ()
{
	//char buf[100]
	errno = 0;
	
	FILE * ptrfile = fopen("none", "rb");
	int error_num = errno;

	if (ptrfile == NULL )
	{
		char *errorbuf = strerror (error_num);

		//strcpy(buf,strerror(errno));
	    fprintf (stderr, "Your errno %s\n", errorbuf);
	//	printf("sys_errlist ",_strerror());
		perror("Using Perror");
		//exit (1);
	//	fclose(ptrfile);
	}	
	else
	{
	fclose (ptrfile);
	}	
return 0;
}
