#include  <stdio.h>
#define N 100
int main()
{

	char arr[N];
	FILE *file =fopen("file99.txt","r");
	
	if (file!=NULL)
	
	{
		printf ("file exist\n");
		while(fgets(arr,N,file)!=NULL)
		{
			printf ("%s",arr);
			printf ("\n");
		}
	
	fclose(file);
	}

	else 
	{
		printf("error");	
	}

return 0;
}


