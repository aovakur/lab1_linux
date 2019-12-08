#include <signal.h>

#include <stdio.h>
#include <stdlib.h>
 
int status ;


void listener2(int sig)
{
	  fprintf(stdout, "listner2 \n");
	  status = 1;
	 	exit(1);

}

void listener(int sig) {
    fprintf(stdout, "listner1 \n");
    status = 0;
    signal(SIGINT,listener2);
}




 
int main() {

	signal(SIGINT, listener);
	raise(SIGINT);
	raise(SIGINT);

	//if (status == 0)
 	//{
		
	//	exit(1);
	//}
//
	//if (status == 1)
 	////fprintf (stdout, "exit");
	//	exit(1);
	//}

}

