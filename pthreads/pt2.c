#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct sum_runner_struct{
 long long limit;
 long long answer;
};

//thread function to generate the sum from 0 to N
void* sum_runner(void* arg){
 struct sum_runner_struct *arg_struct = (struct sum_runner_struct*)arg;

 long long sum = 0;
 for(long long i=0;i<=arg_struct->limit;++i){
  sum+=i;
 }
 arg_struct->answer = sum;
 pthread_exit(0);
}

int main(int argc, char** argv){
 if (argc<2){
  printf("Usage: %s <num> <num1> <num2> ... <num_n>\n",argv[0]);
  exit(-1);
 }

 //long long limit = atoll(argv[1]);
 int num_args = argc - 1;
 //thread id
 pthread_t tids[num_args];

 struct sum_runner_struct arg[num_args];
 for(int i=0;i<num_args;++i){
  arg[i].limit = atoll(argv[i+1]);
  //thread attributes
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  pthread_create(&tids[i], &attr, sum_runner, &arg[i]);
 }

 //wait until the thread gets over
 for(int i=0;i<num_args;++i){
 pthread_join(tids[i],NULL);

 printf("the sum of numbers using thread is: %lld \n",arg[i].answer);
 }
 return 0;
}
