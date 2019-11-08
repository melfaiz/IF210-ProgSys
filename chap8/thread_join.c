#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


 
int main (void)
{
   int i = 0;
   int ret = 0;
 
 

 
   /* Attente de la fin des threads. */
   i = 0;
   for (i = 0; i < NB_CLIENTS; i++)
   {
      pthread_join (store.thread_clients [i], NULL);
   }
   pthread_join (store.thread_store, NULL);
 
 
   return EXIT_SUCCESS;
}