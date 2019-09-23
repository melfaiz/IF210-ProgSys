#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main () {

    pid_t pid = getpid();
    printf("Le pid de ce processus est: %d \n",pid);
    return(0);
}