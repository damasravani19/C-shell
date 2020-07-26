#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include"shell.h"

void execute_bbgrbg(char ** input_arguments,int count)
{
    long long int pid;
    int x;
    x=(int)(*(input_arguments[1]));
        x=x-1-48;
    pid=processes[x].jpid;
    kill(pid,19);
}
