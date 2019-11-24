#include<stdio.h>
#include<stdlib.h>

int main()
{

	setenv("STRING1","STRING1",1); // does overwrite
	setenv("STRING2","STRING2",0); // does not overwrite

  char * env1= getenv("STRING1"); 
  char * env2= getenv("STRING2");
 
  if (env1 != NULL) 	
  {
  	printf("Parametr env 1 = %s\n", env1);
	
	}

  else 

  {
  	printf("Not found parametrs");
  	
  }


  
  if (env2!= NULL) 	
  {
  	printf("Parametr env 2 = %s\n", env2);
	
	}

  else 

  {
  	printf("Not found parametrs");
  
  }
  
  	return 0;
}


