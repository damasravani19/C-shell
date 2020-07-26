#include<stdio.h>
#include"shell.h"
void execute_echo(int argc,char *argv[])
//int main(int argc,char *argv[])
{
 long long int i;
 //printf(" %d "code ,argc);
 for(i=1;i<argc;i++)  { printf("%s",argv[i]);  }
 printf("\n");
}      