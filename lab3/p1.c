/*
 * 1. Изменить реакцию процесса на некоторый сигнал при помощи signal. 
 * В функции обработчике переустановить реакцию на сигнал на значение по умолчанию. 
 * Запустить программу и объяснить наблюдаемый результат.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int); 

int main (int argc, char* argv[]) {
	signal(SIGINT, sighandler);//системный вызов
/*
 * первый аргумент определяет сигнал, диспозицию которого нужно изменить
 * второй аргумент определяет новую диспозицию сигнала
*/
	while(1) {
		printf("Ожидание 1 сек...\n");
		sleep(1);
	}
	return(0);
}

void sighandler(int signum) {
	signal(SIGINT, SIG_DFL); //устанавливаем SIGINT действие по уолчанию (завершение процесса)
	printf("Пойман сигнал %d, выход из обработчика...\n", signum);
}
