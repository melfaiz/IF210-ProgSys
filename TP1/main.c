#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    
    if(argc<2)
    {
        printf("USE : %s PID \n", argv[0]);
    }else
    {
        kill(atoi(argv[1]), SIGUSR1);
        printf("KILLED %i \n", atoi(argv[1]));
    }
    
    

    return 0;

}