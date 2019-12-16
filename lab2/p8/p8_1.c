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

	int from_fd = open(argv[1], O_RDONLY); //открываем файл для чтения
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
		int to_fd = creat("child.txt", 0644); //создание файла в дочерней ветке
		if(to_fd < 0){
			printf("\tError: %s\n", strerror(errno));
			return -1;
		}

		copy(from_fd, to_fd); //копируем из файла №1 в дочерний файл

		if (close(to_fd) < 0){
			printf("\tError: %s\n", strerror(errno));
			return 1;
		}

		int chld = open("child.txt", O_RDONLY);
		if(chld < 0){
			printf("\tError: %s\n", strerror(errno));
			return -1;
		}

		printf("[C].....::::: Child process :::::.....\n"); //открываем дочерний файл и выводим на экран
		printf("[C].....::::::: S T A R T :::::::.....\n");
		copy(chld, 1);
		printf("\n[C].....::::::::: E N D :::::::::.....\n\n");

		exit(0);
	}
	else{ // Parent
		int to_fd = creat("parent.txt", 0644); //создание родительского файла
		if(to_fd < 0){
			printf("\tError: %s\n", strerror(errno));
			return -1;
		}

		copy(from_fd, to_fd); //копирование из файла №1 в родительский файл

		if (close(to_fd) < 0){
			printf("\tError: %s\n", strerror(errno));
			return 1;
		}

		int status; 		 //статус завершения дочернего 
		pid = wait(&status); //ждём пока дочерний не закончится
		if (pid == -1){
			perror("Error: ");
			return -1;
		}

		int par = open("parent.txt", O_RDONLY); //открываем родительский файл
		if(par < 0){
			printf("\tError: %s\n", strerror(errno));
			return -1;
		}

		printf("[P].....:::: Parent process :::::.....\n");
		printf("[P].....::::::: S T A R T :::::::.....\n");
		copy(par, 1);									//выводим на экран родительский файл
		printf("\n[P].....::::::::: E N D :::::::::.....\n\n");
	}

	return 0;
}

int copy(int from_fd, int to_fd) //функция копирования 
{
    char* buffer[1024];
    int r_count;
    int w_count;

    do {
        r_count = read(from_fd, buffer, 1); // r_count = кол-во считанных байтов из файла №1
        if (r_count < 0){
                printf("\tError: %s\n", strerror(errno));
                return -1;
        }
        w_count = write(to_fd, buffer, r_count); // w_count = код возврата write, записали в файл№2
        if (w_count < 0){
                printf("\tError: %s\n", strerror(errno));
                return -1;
        }

    } while(r_count != 0);

    return 0;
} 
//Мы открыли файл, а затем сделали форк: дескриптор файла стал общим для обоих процессов.
//Так как сначала выполняется родительский процесс (см. п.2), то файл был прочитан и записан в выходной файл, созданный родительским процессом.
//Выходной файл, созданный дочерним процессом был создан и оставлен пустым, так как при выполнении дочернего процесса файловый дескриптор уже был в конце.
//Если выводить на экран читаемую из файлов информацию, то файл будет выведен единожды родительским процессом, после чего дочернему процессу
//снова достанется дескриптор файла,находящийся в конце.
