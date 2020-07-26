#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include"shell.h"

void callfork(char ** input_arguments,int count)
{
  long long int pid;
  pid=fork();
  if(pid==0)
  {
       redirectioncheck(input_arguments,count);
       exit(1);
  }
  else 
  {
    wait(NULL);
  }

   return ;
}