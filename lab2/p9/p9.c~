/* 9. Выполнить п. 8 при условии,
*  что общий файл для чтения открывается в каждом из порожденных процессов.
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

	int pid = fork();
	int from_fd = open(argv[1], O_RDONLY);
	if (pid == -1){
		perror("Error: ");
		return -1;
	}

	// Child
	if (pid == 0){
		//int from_fd = open(argv[1], O_RDONLY);
		if(from_fd < 0){
			printf("\tError: %s\n", strerror(errno));
			return -1;
		}

		int to_fd = creat("child.txt", 0644);
		if(to_fd < 0){
			printf("\tError: %s\n", strerror(errno));
			return -1;
		}

		copy(from_fd, to_fd);

		if (close(to_fd) < 0){
			printf("\tError: %s\n", strerror(errno));
			return 1;
		}

		from_fd = open("child.txt", O_RDONLY);
		if(from_fd < 0){
			printf("\tError: %s\n", strerror(errno));
			return -1;
		}

		printf(".....::::: Child process :::::.....\n");
		printf(".....::::::: S T A R T :::::::.....\n");
		copy(from_fd, 1);
		printf("\n.....::::::::: E N D :::::::::.....\n\n");

		exit(0);
	}
	else{ // Parent
		//int from_fd = open(argv[1], O_RDONLY);
		if(from_fd < 0){
			printf("\tError: %s\n", strerror(errno));
			return -1;
		}
		
		int to_fd = creat("parent.txt", 0644);
		if(to_fd < 0){
			printf("\tError: %s\n", strerror(errno));
			return -1;
		}

		copy(from_fd, to_fd);

		if (close(to_fd) < 0){
			printf("\tError: %s\n", strerror(errno));
			return 1;
		}

		int status;
		pid = wait(&status);
		if (pid == -1){
			perror("Error: ");
			return -1;
		}

		from_fd = open("parent.txt", O_RDONLY);
		if(from_fd < 0){
			printf("\tError: %s\n", strerror(errno));
			return -1;
		}

		printf(".....:::: Parent process :::::.....\n");
		printf(".....::::::: S T A R T :::::::.....\n");
		copy(from_fd, 1);
		printf("\n.....::::::::: E N D :::::::::.....\n\n");
	}

	return 0;
}

int copy(int from_fd, int to_fd)
{
    char* buffer[1024];
    int r_count = 0;
    int w_count = 0;

    do {
        r_count = read(from_fd, buffer, 1024);
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
