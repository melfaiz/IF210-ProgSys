#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    char *phrase = "une phrase ecrite";
    char *phrase2;
    ssize_t nb_ecrit;
    ssize_t nb_lu;
    int pipefd[2];
    int pipe_err = pipe(pipefd);
    if (pipe_err == -1)
    {
        printf("Erreur lors de la création du pipe\n");
    }

    pid_t pid;
    pid = fork();

    if (pid != 0)
    {
        close(pipefd[0]);
        nb_ecrit = write(pipefd[1], &phrase, 1024);
    } 
    else
    {
        close(pipefd[1]);
        nb_lu = read(pipefd[0], &phrase2, 1024);
        printf("chaine recue : %s\n", phrase2);
    }

    int *status;
    wait(status);
    return 0;
}
