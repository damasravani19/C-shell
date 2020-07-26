#include<stdio.h>
#include<pwd.h>
#include"shell.h"
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

void execute_pinfo(int argc,char * argv[])
//int main(int argc,char * argv[])
{
    //printf("%s",argv[1]);
    int pid;  
    char arr[100],check[100];
    if(argv[1][0]=='\0') { pid=getpid(); }
    else { pid=atoi(argv[1]); }
    printf("pid--%d\n",pid);
    sprintf(arr,"%d",pid);
    //for(int i=0;i<5;i++) { printf("%d",arr[i]); }
    char path1[2000]="";
    //memset(path1,0,2000);
    strcpy(path1,"/proc/");
    strcat(path1,arr);
    strcat(path1,"/status");
    //printf("%s\n",path1);
    FILE *fp1,*fp2;
    fp1=fopen(path1,"r");
    if(fp1==NULL) { printf("Error in opening the file"); }
    //print the status and virtual memory
    //status
    while(fgets(check,60,fp1)!=NULL ) {
       if(strncmp(check,"State",5)==0) { printf("Process status--%s",&check[6]); }
       if(strncmp(check,"VmSize",6)==0) { printf("Virtual Memory--%s",&check[7]); }
     }
    
    char path2[2000]="";
   // memset(path2,0,200);
    strcpy(path2,"/proc/");
    strcat(path2,arr);
    strcat(path2,"/exe");
    fp2=fopen(path2,"r");
    char*line=(char*)malloc(2947);
    int s = readlink(path2, line, 2017);
    printf("%s\n",line);
    //while(fgets(check,60,fp1)!=NULL ) {
    //   
    //}
    //print the executable path 
}

