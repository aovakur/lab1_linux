#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#define N 100
#define L 100
main(void)
{
		
		char const *str ="string 1 \n";
		char msg[]="String 2";
		char *fname;
		char ch;
		fname="lab44.txt";	
		unsigned int mode;
		unsigned int flag;
		flag =O_CREAT | O_RDWR;
		
		int file;
		mode = S_IRWXU;
		file = open (fname,flag,mode);
		long position;
		int handle;
		if (file == -1 )
			{	
		perror ("ERR");
			}
		else 
			{
				write (file , str , strlen(str));
				lseek(file,0L,SEEK_SET);
				do 
				{
					read(file,&ch,1) ;
					printf("%c",ch);
				} while (read!=0);
				
				printf("succed");
				
		close (file);
			}
return 0;			
}

