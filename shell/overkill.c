#include<stdio.h>
#include<signal.h>
#include"shell.h"

void execute_overkill()
{
   
   for(int i=0;i<sizeofbg;i++)
   {
       kill(processes[i].jpid,SIGKILL);
   }
   sizeofbg=0;
}