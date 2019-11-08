#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>


struct Element {
    int a;
    char b;
    int* ptr;
};


void *thread(void *arg)
{
    struct Element* elem = (struct Element*)arg;
    int a = elem->a;
    char b = elem-> b;
    int* ptr = elem->ptr;

    printf("==========\n On est dans la fonction\n");
    printf(" a: %i, b: %c , ptr: %i\n",a,b,*ptr);
    printf("==========\n");


}

int main(int argc, char const *argv[])
{
    pthread_t thread1;

    struct Element* elem = malloc(sizeof(struct Element*));
    elem->a = atoi(argv[1]);
    
    elem-> b = argv[2][0];    

    int c = atoi(argv[3]);    

    elem->ptr = &c ;


    printf("Avant la création du thread.\n");

    if(pthread_create(&thread1, NULL, thread, (void*)elem) == -1) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    printf("Après la création du thread .\n");


    int i=0;
    while (++i);
    
    return EXIT_SUCCESS;
}

