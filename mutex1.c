#include <stdio.h>
#include <pthread.h>
//#define NUM_LOOPS 500000000
#define NUM_LOOPS 20000000

long long sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;



void *counting_function(void *arg){
  int offset = *(int *)arg;
  for(int i=0;i<NUM_LOOPS;++i){
   //start critical section
   pthread_mutex_lock(&mutex);
   sum+=offset;

   pthread_mutex_unlock(&mutex);
    //end critical section
   }
  pthread_exit(NULL);
  }

int main(void){
  //counting_function(1);
  //counting_function(-1);

  //spawn threads
  pthread_t id1;
  int offset1 = 1;
  pthread_create(&id1,NULL,counting_function,&offset1);

  

  pthread_t id2;
  int offset2 = -1;
  pthread_create(&id2,NULL,counting_function,&offset2);

  //waiting for threads to finish
  pthread_join(id1,NULL);
  pthread_join(id2,NULL);

  printf("sum = %lld\n",sum);
  return 0;
 }

