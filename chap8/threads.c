#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread(void *arg)
{
    printf("Je suis le %s.\n", (char*)arg);

}

int main(void)
{
    pthread_t thread1, thread2;

    char* arg1 = "PREMIER THREAD";
    char* arg2 = "DEUXIEME THREAD";

    printf("Avant la création du thread.\n");

    if(pthread_create(&thread1, NULL, thread, arg1) == -1) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    printf("Après la création du thread 1 .\n");

    if(pthread_create(&thread2, NULL, thread, arg2) == -1) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    printf("Après la création du thread 2 .\n");

    int i=0;
    while (++i);
    
    return EXIT_SUCCESS;
}
