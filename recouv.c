#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    printf("Premier programme: \n");

    while(*argv++)
    {
        printf(" Argument : %s \n", *argv);
    }
    
    

    return 0;
}
