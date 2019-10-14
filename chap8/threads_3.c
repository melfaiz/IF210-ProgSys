#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *f_thread(void* i)
{
    printf("Je suis le thread n° : %i.\n", *(int*)i);

}

int main(void)
{
  
    int i;
    for (i = 0; i < 10; ++i)
    {
        pthread_t thread;
        if(pthread_create(&thread, NULL, f_thread,(void*) &i) == -1) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }
    

 
    int t=0;
    while (++t);
    
    return EXIT_SUCCESS;
}
