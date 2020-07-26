#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>
#include"shell.h"

void execute_fgbg(char ** input_arguments,int count)
{
    signal(SIGINT, sigintHandler);
    long long int pid;
    int status;
    int x;
    x=atoi(input_arguments[0]);
    x=x-1;
    pid=processes[x].jpid;
    for(int i=x;i<sizeofbg;i++)
    {
           processes[i-1]=processes[i];
    }
    sizeofbg--;
    kill(pid, SIGCONT); 
    waitpid(pid, &status, WUNTRACED);
 //   return;
   
} 
