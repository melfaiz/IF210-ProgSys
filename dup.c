#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    int file = open("test.txt", O_RDWR);
 
    close(STDOUT_FILENO);
    dup(file);
    close(file);

    printf("Redirection\n");
 
    return 0;
}

// dup2 et dup3 garantient l'atomicite