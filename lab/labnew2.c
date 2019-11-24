#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#define N 100
#define L 100
void  WriteFunction;

int main()
{
		WriteFunction();
		ReadFunction();
}

void  WriteFunction ()
{
	char *fname;
	fname="file99.txt";
	char const *str= "string 1 \n";	
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
				printf("succed");
				
		close (file);
			}
return 1;			
}

//int ReadFunction (void)
//{
	//	FILE *file1;
	//	char arr[L];
	//	unsigned int flag1;
  //		char *fname1;	
//		flag1 = O_RDONLY;
//		fname1="file99.txt";
//		file1 = open (fname1,flag1);
//		if (file1==NULL) perror ("error read");
//		else
//		{
//		 if (fgets(arr,N,file1)!=NULL)
//			puts( arr);
//			fclose (file1);
//		}
//return 0;
//}
