#include<stdio.h>
#include<stdlib.h>
#include"shell.h"

void execute_setenv(char ** input_arguments,int count)
{
   printf("%d %s %s\n",count,input_arguments[1],input_arguments[2]);
   if(count==0)
   { 
        perror("too few arguments");
   } 
   else if(count>2)
   {
       perror("too many arguments");
   }
   else if(count==1)
   {
       // just the variable name is provided
       int x=setenv(input_arguments[1],"",1);
       if(x!=0) { perror("cannot set the variable"); }
   }
   else if(count==2)
   {
       //varaible name along with it's value is provided
      int x=setenv(input_arguments[1],input_arguments[2],1);
      if(x!=0) { perror("cannot set the variable"); }
   }
  /*char* a=getenv(input_arguments[1]); 
  printf("%s\n",a);*/

}