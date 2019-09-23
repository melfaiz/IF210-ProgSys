#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{

    pid_t fils ; 

    fils = fork();
    
    if ( fils > 0)
    {
        return 0;

    }else if ( fils == 0)
    {
        int timer = 0;

        while (++timer);

        printf("Valeur de PID du pere: %d \n",getppid());

        return 0;
    }else{
        return EXIT_FAILURE;
    }
    
}

