#include <stdio.h> 
#include <stdlib.h>
#include <signal.h> 
#include <sys/types.h>
#include <unistd.h>
  
int main(int argc, char const *argv[])
{


    printf("Le PID du programme %s est : %i \n", argv[0] , getpid() ) ;

    while (1);
  
    
    return 0; 
} 