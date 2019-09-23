#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

   
    pid_t fils = fork();

    if (fils == 0)
    {
        printf("Le programme fils : \n");

        char** arg = malloc(3* sizeof(char*));

        arg[0] = "./recouv3";
        arg[1] = "arument 1 du fils";
        arg[2] = NULL;

        execv(arg[0] , arg );

    }else{

        printf("Le programme père : \n");

        *argv++;
        while(*argv++)
        {
            printf("Argument : %s \n", *argv);
            
        }

        return 0;
    }

    return 0;

}
