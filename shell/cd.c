#include<stdio.h>
#include<unistd.h>
#include"shell.h"
void execute_cd(int argc,char *argv[])
//int main(int argc,char * argv[])
{
   //just storing in buffer the address of the present working directory so that aftere xecution i can go back to my previous directory 
   char buffer[1000];
   //getcwd(buffer,sizeof(buffer));
   chdir(argv[1]); 
   //getcwd(buffer,sizeof(buffer));
   
}