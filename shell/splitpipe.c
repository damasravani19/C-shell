#include<stdio.h>
#include"shell.h"
#include<stdlib.h>

char ** split_eachpipe(char * buffer)
{
    //printf("%s",buffer);
    long long int i,k,j,finallenght,count;
    char sample[100];
    count=-1;
   //for(i=0;i<200;i++) { printf("%d ",buffer[i]); } 
   //printf("\n");
  char **input_arguments = (char **)malloc(20 * sizeof(char *));
  for (i = 0; i < 20; i++) { input_arguments[i] = (char *)malloc(1000 * sizeof(char)); }
  //printf("done\n");
    for(i=0;buffer[i]!=10 && buffer[i]!=0;i++) { ;}
    //printf("loopdone\n");
    finallenght=i;
    for(i=0;i<finallenght;i++) 
    {
       k=0;
      // printf("%d\n",i);
       for (j = i; buffer[j] != 32 && j < finallenght; j++)
       {
        
        sample[k] = buffer[j];
        i++;
        k++;
      }
      if(k!=0) count++;
      //printf("%lld..",count);
      for (int a = 0; a < k; a++)
      {
        input_arguments[count][a] = sample[a];
        //printf("done2\n");
      }
    }
    //printf("done3\n");
    input_arguments[++count]=NULL;
    //for(i=0;i<=count;i++) { printf("%s  ",input_arguments[i]); }
    return input_arguments;
} 