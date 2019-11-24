#include <stdio.h>
//#include <stdin.h>
#include <string.h>
#include <fcntl.h>
#define N 100

main () {
FILE *file;
FILE *filenew;

char name1[50];
char name2[50];
printf("from  ");
scanf("%s",&name1);

//fgets(name1);
printf ("to  ");
scanf("%s",&name2);
//fgets(name2);

char arr[N];
file = fopen (name1,"r");
filenew = fopen (name2, "w");

while (fgets(arr,N,file)!=NULL)
{
	fwrite(arr,1,sizeof(arr), filenew);
}
fclose (file);
fclose (filenew);

}
