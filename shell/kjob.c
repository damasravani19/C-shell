#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include"shell.h"

void execute_kjob(char ** input_arguments,int count)
{
    //printf("%s %d",input_arguments[0],count);
    //printf("ywe\n");
    if(count<2)
    {
        printf("too few argumemts");
    }
    if(count>2)
    {
        printf("too many arguments");
    }
    else 
    {
        //printf("right arguments");
        int x,y,pid;
        x=atoi(input_arguments[1]);
        x=x-1;
        pid=processes[x].jpid;
        y=atoi(input_arguments[2]);
        printf("%d %d\n",x,y);
        kill(pid,y);
        if(y==9) { printf("%s with pid %d exited normally\n",processes[x].jname,pid); 

        for(int k=x+1;k<sizeofbg;k++)
        {
            processes[k-1]=processes[k];
        }
        sizeofbg--;
        }
    }
    
}