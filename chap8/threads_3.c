#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *f_thread(void* i)
{

    printf("Je suis le thread n° : %i.\n", *(int*)i) ;

}

int main(void)
{
  
    int i;

    void* tab[10];

    for (i = 0; i < 10; ++i)
    {
        pthread_t thread;
        if(pthread_create(&tab[i], NULL, f_thread,(void*) &i ) == -1) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }
  
   /* Attente de la fin des threads. */
   i = 0;
   for (i = 0; i < 10; i++)
   {
      pthread_join (tab[i], NULL);
   }
   

    
    return EXIT_SUCCESS;
}
