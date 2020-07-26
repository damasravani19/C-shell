#include<stdio.h>
#include<unistd.h>
#include"shell.h"
#include<pwd.h>

void execute_pwd(int argc,char *argv[])
//int main()
{
    char buffer[100];
    getcwd(buffer,sizeof(buffer));
    printf("%s\n",buffer);
}