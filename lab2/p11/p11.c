/* 11. Выполнить из программы на Си какую-либо команду Shell (cp или ls):
*  с помощью вызовов fork-exec, с помощью библиотечной функции system.
*  Необходимые для команды данные передать через аргументы командной строки.
*/

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <locale.h>

int main(int argc, char **argv) {

	char *c=argv[1];
	pid_t pid = fork();
	if (pid == -1) {
	perror("fork failed");
	exit(EXIT_FAILURE);
	}

	if (pid > 0) {
		printf("(dad) waiting\n");
		wait(NULL);
		printf("(dad) finished\n");
	} else {
		printf("before system\n");
		execv(argv[1],&argv[1]);
	}
exit(EXIT_SUCCESS);//В качестве параметра функции указывается статус EXIT_SUCCESS, так как завершение работы штатное. 
}
 
