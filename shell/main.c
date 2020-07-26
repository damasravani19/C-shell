#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "shell.h"
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

#include <grp.h>
#include <time.h>

#define buffersize 50
long long int bg[100];
char bg_name[100000][100];
long long int sizeofbg;

void function_call(char **input_arguments, int count)
{
  //for (int i = 0; i <= 1; i++){printf("%s..\n", input_arguments[i]);}
  char *checklist_commands[] = {"ls", "cd", "echo", "pwd", "pinfo"};
  int fg, i, pole;
  fg = 1; //pole=0;
  if (count == -1)
    return;
  //if(input_arguments[count]==NULL||input_arguments[count][0]=='\0')return;
  if (count >= 0 && input_arguments[count][0] == '&')
  {
    fg = 0;
  }
  else
  {
    fg = 1;
  }
  for (i = 0; i < 5; i++)
  {
    if (input_arguments[0] == checklist_commands[i])
      ;
    {
      if (strncmp(input_arguments[0], "echo", 4) == 0)
      {
        execute_echo(count + 1, input_arguments);
        return;
      }
      else if (strncmp(input_arguments[0], "cd", 2) == 0)
      {
        execute_cd(count + 1, input_arguments);
        return;
      }
      else if (strncmp(input_arguments[0], "ls", 2) == 0)
      {
        execute_ls(count + 1, input_arguments);
        return;
      }
      else if (strncmp(input_arguments[0], "pwd", 3) == 0)
      {
        execute_pwd(count + 1, input_arguments);
        return;
      }
      else if (strncmp(input_arguments[0], "pinfo", 5) == 0)
      {
        execute_pinfo(count + 1, input_arguments);
        return;
      }
      //   pole=1;
    }
  }

  if(fg==0) { execute_bg(count,input_arguments); }
  if(fg==1) { execute_fg(count,input_arguments); }
  
}
void status_check()
{
  char *buffer;
  size_t buffer_size = 500; // size_t is a special type of interger used for getline
  size_t input;
  long long int i, count, j, k, length, m, set;
  count = -1;
  buffer = (char *)malloc(buffersize * sizeof(char));
  if (buffer == 0)
  {
    fprintf(stderr, "allocation error\n");
    exit(EXIT_FAILURE);
  }

  input = getline(&buffer, &buffer_size, stdin);
  // printf("%s\n",buffer);
  char **input_arguments = (char **)malloc(buffersize * sizeof(char *));

  for (i = 0; i < buffersize; i++)
  {
    input_arguments[i] = (char *)malloc(1000 * sizeof(char));
  }
  char sample[100];
  int pip,redirection;
  pip=0; redirection=0;
  for (i = 0; buffer[i] != 10; i++)
  {
     if(buffer[i]=='|'){ pip=1;} 
     if(buffer[i]=='>' || buffer[i]=='<' || (buffer[i]=='>' && buffer[i+1]=='>')) {redirection=1;}
  }
  if(pip==1) {  execute_pip(buffer);  return; }
  else
  {
  length = i;
  buffer[length]=';';
  //printf("%d\n",length);

   int initiallenght,finallenght;
     initiallenght=0;
  for(m=0;m<length+1;m++)
  {
    if(buffer[m]==';') { 
    finallenght=m; count=-1;
    //printf("%d %d\n",initiallenght,finallenght);
    for(i=initiallenght;i<finallenght;i++) 
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
       }
    }   
    input_arguments[++count]=NULL;
    count--;
   // printf("%d ",count);
   // printf("%s \n",input_arguments[0]);
   //  printf("a");
   // for(int f=0;/* input_arguments[f]!=NULL */ && f<=count;f++) { printf("%s\n",input_arguments[f]);} printf("a");
    if(strncmp(input_arguments[0],"jobs",4)==0) {  execute_jobs();}
    else if(strncmp(input_arguments[0],"kjob",4)==0) {  execute_kjob(input_arguments,count); }
    else if(strncmp(input_arguments[0],"quit",4)==0) {  execute_quit(); }
    else if(strncmp(input_arguments[0],"setenv",6)==0) {  execute_setenv(input_arguments,count); }
    else if(strncmp(input_arguments[0],"unsetenv",8)==0) {  execute_unsetenv(input_arguments,count); }
    else if(strncmp(input_arguments[0],"overkill",8)==0) {  execute_overkill(); }
    else if(strncmp(input_arguments[0],"bg",2)==0) {  execute_bbgrbg(input_arguments,count); }
    else if(strncmp(input_arguments[0],"fg",2)==0) {  execute_fgbg(input_arguments,count); }
    //else if(strncmp(input_arguments[0],"cronjob",7)==0) { printf("%d ",count); printf("a"); execute_cronjob(input_arguments,count); }
    //else if(strncmp(input_arguments[0],"fg",2)==0) { execute_fgbg(input_arguments,count); }
    else if(redirection==0) { function_call(input_arguments,count); }
    //if(input_arguments[0]=="jobs") { execute_jobsmake}
    else if(redirection==1)
     {
        if(strncmp(input_arguments[0],"cd",2)==0) { execute_cd(count+1,input_arguments);} 
        else{ callfork(input_arguments,count); }
     }
    initiallenght=finallenght+1;
    }
  }
  }
  return;
}  
 
void sigintHandler (int sig_num)
{
	signal(SIGINT, sigintHandler);
	fflush(stdout);
}
void sigtstpHandler(int sig_num) 
{
  
  pid_t p = getpid();
  ///printf("%lld  %lld\n",p,shellid);
   // if (p != shellid)
   //     return;
  //printf("cysd");
  if(sspid!=-1)
  {
    //printf("%d",sizeofbg);
    strcpy(processes[sizeofbg].jname,sspidname);
    processes[sizeofbg].jpid=sspid;
    processes[sizeofbg].status=3; // status=3 implies stopped
    sizeofbg++;
  }
	signal(SIGTSTP, sigtstpHandler);
}

int main()
{
  int flag, x, y;
  flag = 0;
  char ref[1000], curr_dir[1000];
  if (flag == 0)
  {
    getcwd(ref, sizeof(ref));
    x = strlen(ref);
    flag = 1;
  }
  //signal(SIGCHLD, execute_exithandler);

    signal(SIGTSTP, sigtstpHandler);
    signal(SIGINT, sigintHandler);
  while (1)
  {
    //signal(SIGTSTP, sigtstpHandler);
    //signal(SIGINT, sigintHandler);
    sspid=-1;
    // at the start itself get to know the home directory path and size then every time do pwd based on intital size peinth the remaining path based on th requirement
    //calling the function to check the exit status of backgroud process
    char hostname[100];
    gethostname(hostname, 1024);
    uid_t userid = geteuid();
    struct passwd *pw = getpwuid(userid);
    //username@hostname:~>
    printf("%s@", pw->pw_name);
    printf("%s:", hostname);
    char buffer[100];
    getcwd(buffer, sizeof(buffer)); // a null charcter exsits at the end
    y = strlen(buffer);
    //printf("%d %d",x,y);
    //printf("%s\n %s\n",ref,buffer);

    if (strncmp(ref, buffer, x) == 0 && x == y){  printf("~>"); }
    else if (strncmp(ref, buffer, x) == 0 && x < y)
    {   printf("~%s>", &buffer[x]);    }
    else{  printf("%s>", buffer);  }
    //for(int i=0;i<25;i++) printf("%d %c\n",buffer[i],buffer[i]);
    //printf("%s\n",buffer);
    status_check();
  }
  return 0;
}