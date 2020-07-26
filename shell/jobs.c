#include<stdio.h>
#include<string.h>
#include"shell.h"

void execute_jobs()
{
    /*struct job{
        char jname[100];
        int  jpid;
        int  status; // for running 2 for stopped 3
    }processes[10000];*/
   for(int i=0;i<sizeofbg;i++)
   {
       printf("%d\n",i);
       printf("[%d] ",i+1); 
      // printf("%d %d\n",i,processes[i].status);printf("pid--%d\n",pid);
      char arr[100],str1[100],check[100];
      sprintf(arr,"%d",processes[i].jpid);
    //for(int i=0;i<5;i++) { printf("%d",arr[i]); }
    char path1[2000]="";
    //memset(path1,0,2000);
    strcpy(path1,"/proc/");
    strcat(path1,arr);
    strcat(path1,"/status");
    //printf("%s\n",path1);
    FILE *fp1,*fp2;
    fp1=fopen(path1,"r"); 
    if(fp1==NULL) { perror("process not found");}
    while(fgets(check,60,fp1)!=NULL ) {
       if(strncmp(check,"State",5)==0) { strcpy(str1,&check[6]); }
       //if(strncmp(check,"VmSize",6)==0) { printf("Virtual Memory--%s",&check[7]); }
    }
       //if(processes[i].status==2) { printf("Running ");}
       //else if(processes[i].status==3) { printf("Stopped ");}
       printf("%s",str1);
       printf("%s ",processes[i].jname);
       printf("%d ",processes[i].jpid);
       printf("\n");
   }
 return;

}