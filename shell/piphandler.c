#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include"shell.h"

void execute_pip(char * buffer)
{ 
  int fildes[2];
  int no_of_pipes;
  no_of_pipes=0;
  char ** pip_sep_commands=(char **)malloc(40 * sizeof(char* ));
  for(int i=0;i<40;i++)  { pip_sep_commands[i]=(char *)malloc(1000);  }
  if (pip_sep_commands == NULL)
  {
 		printf("Allocation Error\n");
         return;

  }  
    char* token = strtok(buffer, "|");
	while (token != NULL)
	{
		pip_sep_commands[no_of_pipes++] = token;
		token = strtok(NULL, "|");
		
	}
   // printf("%d\n",no_of_pipes);
    pip_sep_commands[no_of_pipes] = NULL;
    no_of_pipes--;
    
    int check,position;
    check=0; // if only pipes are there then check=0;
   for(int i=0;i<=no_of_pipes;i++)
   {
     for(int j=0;j<15;j++)
     {
      if(i!=no_of_pipes) { if(pip_sep_commands[i][j]=='>' || pip_sep_commands[i][j]=='<') { check=2; }  }
      else 
       {
         if(pip_sep_commands[i][j]=='>') { check=1; position=j;}
         else if(pip_sep_commands[i][j]=='<') { check=2;}
       }
     }  
   }
     int fd=1;
    if(check==0) { fd=1; }
    else if(check==1) {  }
    else if(check==2) { perror("wrong input"); return;}

    int p[2*no_of_pipes];
	for(int i=0;i<no_of_pipes;i++)
    {
		if(pipe(p+i*2)<0)
		{
			exit(1);
		}
	}
  int j=0;
  int status;
  for(int i=0;i<=no_of_pipes;i++)
  {
    //printf("%d\n",i);
    
    int pid;
    pid=fork();
    if(pid==0)
    {
      int fd;
     printf("%d..\n",check);
     char ** args=(char **)malloc(10 * sizeof(char* ));
     for(int b=0;b<40;b++)  { args[b]=(char *)malloc(100);  } 
     //    ***calling a function to seperate all these into individual parts in each pipe and take them as argumets for each pipei<
     //printf("%s",pip_sep_commands[i]);
     args=split_eachpipe(pip_sep_commands[i]);
     //printf("out\n");
     //   ***pass these arguments and execute execvp 
     //for(int m=0;args[m]!=NULL;m++) { printf("a%se \n",args[m]); }
     if(i==no_of_pipes && check==1)
     {
       for(j=0;args[j]!=NULL;j++) { if(args[j][0]=='>'){ break;}}
        printf("%s\n",args[j+1]);
        fd=open(args[j+1],O_WRONLY | O_CREAT,0664);
        args[j]=NULL;
        args[j+1]=NULL;
     }

              if(i!=0)
		        	 {			if(dup2(p[(j-1)*2],0)<0)	{ exit(0);}  }
			        if(i!=no_of_pipes)
               {   if(dup2(p[2*j+1],1)<0){ exit; } }
              if(i==no_of_pipes && check==1) { printf("%d",i); dup2(fd,1); }
               for(int z=0;z<2*no_of_pipes;z++)
			         {
				            close(p[z]);
			         }
			         if(execvp(args[0],args)<0)
			         {
				            perror(" ERROR: exec failed\n");
                        	exit(1);
			         }
			        exit(1);
    }
    else if(pid<0) {
            perror("Error in forking the process\n");
			exit(0);
       } 
    j++;
  }
      for(int i=0;i<2*no_of_pipes;i++)
	     {		close(p[i]);   }
	   for(int i=0;i<no_of_pipes+1;i++)
	    {  wait(&status); }

  return ;
}  