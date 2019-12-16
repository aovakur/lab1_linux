/*
* 10. Написать программу, иллюстрирующую способ блокирования
* дополнительных сигналов на время работы обработчика сигнала. 
* Что произойдет, если во время обработки некоторого сигнала в 
* процесс поступит несколько однотипных заблокированных сигналов.
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
void signal_handler(int);

int main(int argc, char * argv[]) {
     struct sigaction act, oact;
     sigset_t set, oset;

     act.sa_handler = signal_handler;
     if(sigaction(SIGUSR1, &act, &oact) == -1){
        perror("sigaction error");
     }
     if(sigaction(SIGUSR2, &act, &oact) == -1){
        perror("sigaction error");
     }
     if(sigaction(SIGALRM, &act, &oact) == -1){
        perror("sigaction error");
     }
     if(sigaction(SIGCONT, &act, &oact) == -1){
        perror("sigaction error");
     }
     if(sigaction(SIGINT, &act, &oact) == -1){
        perror("sigaction error");
     }
     if(sigfillset(&set) == -1){
        perror("sigemptyset error");
     }
     if(sigdelset(&set, SIGUSR1) == -1){
        perror("sigdelset error");
     }
     sigprocmask(SIG_SETMASK, &set, &oset);
     kill(getpid(), SIGUSR1);
     sigprocmask(SIG_SETMASK,&oset,0);
}

void signal_handler(int sig) {
    printf("Сигнал %d перехвачен!\n", sig);
    if(sig == SIGUSR1) {
        sleep(30);
    }
        printf("\n");

}
