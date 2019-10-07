#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    char* arg[] = {"recouv","argument 1","argument 2",NULL};

    execv("./recouv" , arg );
    
    return 0;
}


