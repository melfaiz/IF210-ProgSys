#include <stdio.h> 
#include <stdlib.h>
#include <signal.h> 
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{


        int pid = getpid();

        unsigned char rand1 = rand();
        unsigned char rand2 = rand();

        unsigned int entier = 0;

        union sigval value;

        char* fifo1 = malloc(sizeof(char));

        char* fifo2 = malloc(sizeof(char));

        sprintf(fifo1 , "tmp/PIPE_<%d>_%d.fifo", pid , rand1);

        sprintf(fifo2 , "tmp/PIPE_<%d>_%d.fifo", pid , rand2);

        if (mkfifo(fifo1, S_IRWXU ))
        {
            perror( " MKFIFO1 ");
        }
        if (mkfifo(fifo2, S_IRWXU ))
        {
            perror( " MKFIFO2 ");
        }
        
        
        
        value.sival_int = ((entier | rand1 ) << 16 | rand2) ;

        if(sigqueue(pid, SIGUSR1, value) == 0) {
                printf("signal sent successfully!!\n");
        } else {
                perror("SIGSENT-ERROR:");
        }
        return 0;
}