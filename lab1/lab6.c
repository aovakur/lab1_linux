#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#define N 100

main () {
FILE *file;
char namel[50];
printf("Name");
scanf("%s",&namel);

int i=0;
int j=1000000;

cahr a;
file = fopen (namel, "w");
char arr[j];
fputc('1',file);
fseek(file,1000000000, SEEK_SET);
fputc('2',file);
fclose(file)
}
