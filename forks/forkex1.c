#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char*argv[] ){
 pid_t pid = fork();
 if(pid<0){
  perror("fork process failed");
  exit(1);}
  if (pid == 0){
    printf("
