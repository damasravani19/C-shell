#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include"shell.h"

void execute_ioredirection(char ** input_arguments,int count,int position1,int position2)
{
   long long int pid;
   //pid=fork();
   //if(pid==0)
   // {
       char *checklist_commands[] = {"ls", "cd", "echo", "pwd", "pinfo"};
       int fd1=open(input_arguments[position1+1],O_RDONLY,0);
         input_arguments[position1]=NULL;
         input_arguments[position1+1]=NULL;
         dup2(fd1,0);
         close(fd1);
     int fd2=open(input_arguments[position2+1],O_WRONLY| O_TRUNC | O_CREAT,0644);
         input_arguments[position2]=NULL;
         input_arguments[position2+1]=NULL;
         dup2(fd2,1);
         close(fd2);
         char ** arguments = (char **)malloc(1000 * sizeof(char *));
         int k=0;
         for(int i=0;i<=count;i++)
         {
               if(input_arguments[i]!=NULL) { arguments[k]=input_arguments[i]; k++; }
         }
         //for(int i=0;i<k;i++) { printf("%s ",arguments[i]); }
         int flag=0;
         for (int i = 0; i < 5; i++)
         {
             if (arguments[0] == checklist_commands[i])   
             {
                if (strncmp(arguments[0], "echo", 4) == 0)
                {   flag=1; execute_echo(k+1, arguments); return; }
                else if (strncmp(arguments[0], "ls", 2) == 0)
                {   flag=1; execute_ls(k+1,arguments);  return; }
                else if (strncmp(arguments[0], "pwd", 3) == 0)
                {  flag=1; execute_pwd(k+1, arguments); return;  }
                else if (strncmp(arguments[0], "pinfo", 5) == 0)
                {  flag=1; execute_pinfo(k+1, arguments);  return;  }
             }
        }

        if(flag==0) { execvp(arguments[0],arguments); return;}
    //}
   //if(pid>0) { wait(NULL); }     
   return ;
}