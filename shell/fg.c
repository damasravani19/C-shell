#include<stdio.h>
#include"shell.h"
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
void execute_fg(long long int a,char * input_arguments[])
{
   long long int  pid;
   pid=fork();
   if(pid==0)
   {
     //sspid=pid;
     //strcpy(sspidname,input_arguments[0]);
     execvp(input_arguments[0],input_arguments); 
   }
   if(pid>0)
   {
       sspid=pid;
       strcpy(sspidname,input_arguments[0]);
       //wait(NULL);
       waitpid(-1,NULL,WUNTRACED);
   } 
}