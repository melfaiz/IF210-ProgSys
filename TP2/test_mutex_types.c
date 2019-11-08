#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#define _GNU_SOURCE
#include <pthread.h>


#define NUM_THREADS 2

pthread_mutex_t mutex;
pthread_mutexattr_t attr;

void *function1(void *arg){

  int ret;
  
  pthread_mutex_lock(&mutex);
  fprintf(stdout,"Function 1\n");

  ret = pthread_mutex_lock(&mutex); // pthread lock

  if(ret != 0)
    fprintf(stdout,"Deadlock in function 1\n");

  fprintf(stdout,"Function 1... again\n");

  pthread_exit(NULL);
}

void *function2(void *arg){

  int ret;
  
  ret = pthread_mutex_unlock(&mutex); // pthread unlock

  if(ret != 0)
    fprintf(stdout,"unlock error in Function 2\n");
  
  fprintf(stdout,"Function 2\n");

  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t tid[NUM_THREADS];
  void *(*(f_ptr[NUM_THREADS]))(void *) = {function1, function2};  
  int ret = 0;
  int idx;

  /* test 1 */
  pthread_mutexattr_init(&attr);
  ret = pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_ERRORCHECK); // verrou avec verification d'erreur
  assert(!ret);
  pthread_mutex_init(&mutex,&attr);
  
  for(idx = 0 ; idx < NUM_THREADS ; idx++){
    pthread_create(&tid[idx],NULL,f_ptr[idx],NULL);
  }
  
  for(idx = 0 ; idx < NUM_THREADS ; idx++){
    pthread_join(tid[idx],NULL);
  }

  sleep(5);
  fprintf(stdout,"====================================\n");
  
  /* test 2 */
  pthread_mutexattr_init(&attr);
  ret = pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE); // le thread peut faire un deadlock mais pas un unlock si il n'est pas proprio
  assert(!ret);
  pthread_mutex_init(&mutex,&attr);
  
  for(idx = 0 ; idx < NUM_THREADS ; idx++){
    pthread_create(&tid[idx],NULL,f_ptr[idx],NULL);
  }
  
  for(idx = 0 ; idx < NUM_THREADS ; idx++){
    pthread_join(tid[idx],NULL);
  }

  sleep(5);
  fprintf(stdout,"====================================\n");
  
  /* test 3 */
  pthread_mutexattr_init(&attr);
  ret = pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_DEFAULT); // ni recursive ni errorcheck.
  assert(!ret);
  pthread_mutex_init(&mutex,&attr);
  
  for(idx = 0 ; idx < NUM_THREADS ; idx++){
    pthread_create(&tid[idx],NULL,f_ptr[idx],NULL);
  }
  
  for(idx = 0 ; idx < NUM_THREADS ; idx++){
    pthread_join(tid[idx],NULL);
  }



  
  return 0;
}
