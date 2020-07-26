#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"shell.h"

void execute_cronjob(char ** input_arguments,int count)
{
    printf("inn");
        long long int timeeach,totaltime;
        timeeach=0; 
        totaltime=0;
       for(int i=0;i<=count;i++)
       {
           if(strncmp(input_arguments[i],"-t",2)==0) 
           { timeeach=atoi(input_arguments[i+1]); input_arguments[i]=NULL; input_arguments[i+1]=NULL; }
           if(strncmp(input_arguments[i],"-p",2)==0)
           { totaltime=atoi(input_arguments[i+1]); input_arguments[i]=NULL; input_arguments[i+1]=NULL; }
       }
       printf("%d %d\n",timeeach,totaltime);
      int k=0;
      char ** args=(char **)malloc(10 * sizeof(char* ));
      for(int b=0;b<40;b++)  { args[b]=(char *)malloc(100);  } 
      for(int i=2;i<=count;i++)
      {
          if(input_arguments[i]!=NULL) { args[k]=input_arguments[i]; k++; } 
      }
      k--;
      for(int m=0;m<=k;m++) { printf("%s ",args[m]); }
     int iter;
     iter=timeeach/totaltime;
     for(int i=0;i<iter;i++)
     {
         execute_bg(k,args);
         sleep(timeeach);
     }
  return;
}