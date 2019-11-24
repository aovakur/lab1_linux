#include <stdio.h>
#include <string.h>
#include <fcntl.h>



#define N 100
#define L 100
main(void)
{
		
		char const *str ="string 1 \n";
		char *fname;
		fname="file99.txt";
	
	unsigned int mode;
	unsigned int flag;
		flag =O_CREAT | O_RDWR;
		
		int file;
		mode = S_IRUSR;
		file = open (fname,flag,mode);


		if (file == -1 )
			{	
		perror ("ERR");
			}
		else 
			{
				write (file , str , strlen(str));
		//write (file, str2, strlen(str2));
				printf("succed");
				
		close (file);
			}
return 0;			
}

