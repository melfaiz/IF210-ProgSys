#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int fd[2];
    pid_t pid;
    pipe(fd); //pipe avant fork
    pid = fork;
    if (pid > 0)
    {
        close(fd[1]);
        close(STDIN_FILENO);
        dup(fd[0]);
        close(fd[0]);
        execlp("wc", "wc", "-l", NULL);
    }
    else if (pid == 0)
    {
        int fd2[2];
        pid_t pid2;
        //close(fd[0]);//close commun au deux fils avant fork
        pid2 = fork();
        if (pid2 > 0)
        {
            close(fd[0]);
            close(fd2[1]);
            close(STDOUT_FILENO);
            dup(fd[1]);
            close(fd[1]);
            close(STDIN_FILENO);
            dup(fd2[0]);
            close(fd2[0]);
            execlp("wc", "wc", "-l", NULL);
        }
        else if (pid2 == 0)
        {
            close(fd[0]);
            close(fd2[0]);
            close(STDOUT_FILENO);
            dup(fd2[1]);
            close(fd2[1]);
            execlp("cat", "cat", "toto.txt", NULL);
        }
    }
}