#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{

    pid_t fils ; 

    fils = fork();

    if (fils > 0)
    { 
        // code pere

        int status = 0;
        
        wait(&status);
   
        fprintf(stdout, "Valeur de retour du fils: %d \n", WEXITSTATUS(status));

        exit(EXIT_SUCCESS);
        
    }else if (0 == fils)
    {
        // code fils
        
        int toto = 0;

        while (++toto);

        return 33;
    }
    
  return 0;
}
