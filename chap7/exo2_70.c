#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void traitant(int signum){
    fprintf(stdout,"coucou \n");
}

int main(int argc, char const *argv[])
{
    

    struct sigaction act;

    memset(&act,0,sizeof(struct sigaction));
    
    act.sa_handler = traitant;

    sigaction(SIGUSR1,&act,NULL); // changement de comportement du pocessus

    while (1);    
    

    return 0;
}
