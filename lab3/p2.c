/*2. Модифицировать программу п.1 так, чтобы вместо signal использовать sigaction.
*/
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
void sighandler(int);

int main(int argc, char * argv[]) {
    struct sigaction act; //объявляем стрктуру act
    
    act.sa_handler = sighandler; //обработчик сигнала
    act.sa_flags = 0;
    
    sigaction(SIGINT, &act, NULL);
    /*
     * 1- сигнал, диспозицию которого мы меняем
     * 2- чем меняем
     * 3- что было до замены
     */
    while(1){
        printf("Ожидание 1 сек...\n");
		sleep(1);
    }
    return 0;
}

void sighandler(int signal_id){
	struct sigaction act2;
	act2.sa_handler = SIG_DFL; //обработчик сигнала
    act2.sa_flags = 0;
    sigaction(SIGINT, &act2, NULL);
	printf("Пойман сигнал %d, выход из обработчика..\n", signal_id);
}
