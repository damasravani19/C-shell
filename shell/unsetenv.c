#include<stdio.h>
#include<stdlib.h>
#include"shell.h"

void execute_unsetenv(char ** input_arguments,int count)
{
  printf("%d %s %s\n",count,input_arguments[1],input_arguments[2]);
  
  if(count==0) { perror("Too few arguments"); }
  else if(count==1)
  {
      int x=unsetenv(input_arguments[1]);
      if(x!=0) { perror("couldn't delete th evariable"); }
  }
  else if(count>1)
  {
      perror("Too many arguments");
  }
  /*char* a=getenv(input_arguments[1]); 
  printf("%s\n",a);*/
}