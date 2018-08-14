#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int i = 0;
void doSomework(char *str){
 const int NUM_TIMES = 5;
  for(;i<=NUM_TIMES;++i){
   sleep(rand() % 4);
   printf("Done pass %d by %s\n",i,str);
 }
}

int main(void){
 printf("i am process %d \n",(int)getpid());
 //sleep(7);
 pid_t pid = fork();
 srand((int)pid);
 if(pid < 0)
 {
  perror("fork failed");
 }
 if (pid == 0)
 {
 printf("I am the  child with pid = %d \n",(int)getpid());
// sleep(5);
 doSomework("child");
// printf("Child exitiing.. \n");
 exit(42);
 }

 //we must be the parents after all
 printf("I am the parent, waiting for child to end  \n");
 doSomework("Parent");
 int status = 0;
 pid_t childpid = wait(&status);
 printf("parent knows child %d has finished with status %d.\n",(int)childpid,status);
 int childReturnStatus = WEXITSTATUS(status);
 printf("   Return value is %d \n",childReturnStatus);
 //printf("fork returned : %d \n", (int)pid);
 //printf("I am : %d \n",(int)getpid());
 return 0;
}
