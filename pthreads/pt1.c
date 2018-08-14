#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long sum = 0;

//thread function to generate the sum from 0 to N
void* sum_runner(void* arg){
 long long *limit_ptr =(long long *)arg;
 long long limit = *limit_ptr;

 for(long long i=0;i<=limit;++i){
  sum+=i;
 }
 //the sum is global for other threads to access it.
 pthread_exit(0);  
}

int main(int argc, char** argv){
 if (argc<2){
  printf("Usage: %s <num>\n",argv[0]);
  exit(-1);
 }
 
 long long limit = atoll(argv[1]);

 //thread id
 pthread_t tid;

 //thread attributes
 pthread_attr_t attr;
 pthread_attr_init(&attr);

 pthread_create(&tid, &attr, sum_runner, &limit);

 //wait until the thread gets over
 pthread_join(tid,NULL);

 printf("the sum of numbers using thread is: %lld \n",sum);
 return 0;
}
