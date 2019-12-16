//1. Написать программу, которая добавляет новые строки в среду процесса.
#include <stdlib.h>
#include <stdio.h>
extern char **environ; //глобальная переменная environ
int main(int argc, char * argv[]){
    if(argc < 3) { 
        printf("Enter: %s <name> <value>\n", argv[0]);
    }
    else{
        int ret;
        if((ret = setenv(argv[1], argv[2], 1)) == -1){ //флаг - перезапись. Функция setenv() добавляет в переменную окружению имя со значением, если имя не существует. Если имя уже существует в окружении, то ее значение изменяется на значение, если флаг overwrite не равен нулю, а если overwrite равен нулю, то значение имя не изменяется. 
            perror("SETENV error");
        }
        else{
				printf("\nMy environment variables list after putenv():\n"); 
				char *str = *environ; //задаём указатель на начало списка указателей на переменные окружения
				int i;
				for (i = 1; str != NULL; ++i){ //вывод окружения программы в цикле пока environ не достигнет NULL
					printf("%s\n", str);
					str = *(environ + i);
				}
            }
        }
    return 0;
}
