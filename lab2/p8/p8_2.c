/* 8. Открыть файл (достаточно большого размера), доступный для чтения. 
*  Имя файла передается из командной строки.
*  После открытия файла создать параллельный процесс с помощью только fork. 
*  В обоих процессах создать свои файлы для записи, читать информацию из общего файла и копировать ее в собственные выходные файлы (не на экран).
*  Вывести на экран содержимое полученных файлов из порожденного процесса по окончании записи в файл и из родительского процесса, 
*  дождавшись завершения порожденного процесса. Посмотреть, что изменится, если читаемую процессами информацию сразу выводить на экран.
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int copy(int, int);

int main(int argc, char* argv[])
{
	if (argc != 2){
		printf("Program takes exactly 1 argument, but %d was/were transferred.\n", argc - 1);
		return -1;
	}

	int from_fd = open(argv[1], O_RDONLY);
	if(from_fd < 0){
		printf("\tError: %s\n", strerror(errno));
		return -1;
	}

	int pid = fork();
	if (pid == -1){
		perror("Error: ");
		return -1;
	}

	// Child
	if (pid == 0){
		copy(from_fd, 1);
		exit(0);
	}
	else{ // Parent
		copy(from_fd, 1);
	}

	return 0;
}

int copy(int from_fd, int to_fd)
{
    char* buffer[1024];
    int r_count = 0;
    int w_count = 0;

    do {
        r_count = read(from_fd, buffer, 1);
        if (r_count < 0){
                printf("\tError: %s\n", strerror(errno));
                return -1;
        }
        w_count = write(to_fd, buffer, r_count);
        if (w_count < 0){
                printf("\tError: %s\n", strerror(errno));
                return -1;
        }

    } while(r_count != 0);

    return 0;
} 
