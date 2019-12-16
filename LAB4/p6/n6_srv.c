#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "pcheck.h"
struct packet{
    int id;
    int value;
};

int main(int argc, char * argv[], char * argp[]){
    //unlink("channel");
    int rfd = pcheck(open("channel", O_RDONLY), "open error");
    struct packet rx;
    int i = 0;
    int n;
    printf("[RX] Server started...\n");
    while(i < 15){
        n = pcheck(read(rfd, &rx, sizeof(struct packet)), "read error");
        if(n < sizeof(struct packet)){
            printf("[RX] Ошибка при получении пакета! (%d bytes) \n", n);
        }
        else{
            printf("[RX] Пакет получен! (%d ; %d) (%d bytes)\n", rx.id, rx.value, n);
        }
        sleep(1);
    }
    //pcheck(unlink("channel"), "unlink error");
}
