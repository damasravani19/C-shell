#include <stdio.h>
#include <sys/wait.h>
#include "shell.h"

void execute_exithandler(int sig)
{

    long long int i,index;
    int status;
    
        i=waitpid(-1, &status, WNOHANG);
       // for(int j=0;j<100;j++)  { if(bg[j]==i) {index=i; break;} }
       if(WIFEXITED(status))
       { 
           int j;    
           for(j=0;j<sizeofbg;j++) {  if(processes[j].jpid==i) { processes[j].status=3; break; }  }           
           if(i>0) {printf("%s with pid %lld exited normally\n",processes[j].jname,i);
           for(int k=j+1;k<sizeofbg;k++)
           {
            processes[k-1]=processes[k];
           }
            sizeofbg--;
           }
       }  
}

