#include<stdio.h>
#include<string.h>
#include"shell.h"
#include<unistd.h>
#include<signal.h>
void execute_bg(long long int count,char * input_arguments[])
{
   long long int  pid;
   pid=fork();
   if(pid==0)
   {
       //signal(SIGCHLD, execute_exithandler);
       input_arguments[count] = NULL;
       execvp(input_arguments[0],input_arguments);  
   }
   else if(pid>0)
   {
         setpgid(pid,pid);
         signal(SIGCHLD, execute_exithandler);
         //bg[sizeofbg] = pid;
         //printf("%d  ",sizeofbg);
         processes[sizeofbg].jpid = pid;
         //printf("%d  ",processes[sizeofbg].jpid);
         strcpy(processes[sizeofbg].jname,input_arguments[0]);
         //printf("%s  ",processes[sizeofbg].jname);
         //processes[sizeofbg].status = 2;
         //printf("%d  ",processes[sizeofbg].status);
         sizeofbg++;
   } 
}