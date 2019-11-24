#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

main ()
{
	char *date ;
	int ret;
	struct stat buf;
	printf("name");
	char name[50];
	scanf("%s",&name);
	if((ret=stat(name,&buf))!=0)
	{
		fprintf(stderr,"stat failure error %d", ret);
		abort();
	}
date = asctime (localtime(&buf.st_ctime));
printf ("\n", date);
printf("\n %d mode \n", buf.st_mode);
printf("\n %id \n", buf.st_size);
}

