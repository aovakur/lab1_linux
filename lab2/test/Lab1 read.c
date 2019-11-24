#include<stdio.h>
#include<stdlib.h>

int main()
{
  char * langPtr = getenv("LANG"); 
 
  if (langPtr != NULL) 	
  {
  	printf("Not found parametrs");
	return 0;
	}
  else 

  {
  	printf("Not found parametrs");
  	return 0;
  }
  
}


