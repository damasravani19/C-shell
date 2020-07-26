#include<stdio.h>
#include<string.h>
#include"shell.h"

void redirectioncheck(char ** input_arguments,int count)
{
  int a,b,c,flag;
  flag=0;
   int checki,checko,checka;
   checki=0;checko=0;checka=0;
   for( int i=0;i<=count;i++)
    { 
      if (strncmp(input_arguments[i], "cd", 2) == 0) { flag=1;}

     if(input_arguments[i][0]=='<') { checki++; a=i; } 
     else if(input_arguments[i][0]=='>' && input_arguments[i][1]=='>') { checka++; c=i; }
     else if(input_arguments[i][0]=='>') { checko++; b=i; }
    } 
     //printf("%d %d %d\n",checki,checko,checka);

   if( checki!=0 || checka!=0 || checko!=0)
   {
    if(flag==0)
    {
       if(checki==1 && checko==1) { execute_ioredirection(input_arguments,count,a,b);}
       else if(checko==1) { execute_outputredirection(input_arguments,count,b); }
       else if(checki==1) { execute_inputredirection(input_arguments,count,a);}
       else if(checka==1) { execute_appendredirection(input_arguments,count,c); }
    }
    else 
    {
      execute_cd(count + 1, input_arguments);  return;
    }

   }
   else{   /*printf("xsa");*/ function_call(input_arguments,count); }
}