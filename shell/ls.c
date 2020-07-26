#include<stdio.h>
#include<grp.h>
#include<time.h>
#include<sys/stat.h>
#include <dirent.h>
#include "shell.h"
#include <unistd.h>
#include <string.h>
#include<pwd.h>

void execute_ls(int argc,char *argv[])
//int main(int argc,char * argv[])
{
  //printf("%s\n",argv[1]);
  //printf("%d\n",argc);
  int flag_l,flag_a; 
  char gfile[1000],ref[1000];
  getcwd(ref,sizeof(ref));
  strcpy(gfile,ref);
  //printf("%s",ref);
  for(int i=1;i<argc;i++) 
  { 
     if(argv[i][0]=='-') 
     { 
        for(int j=1;j<strlen(argv[i]);j++)
         { 
            if(argv[i][j]=='l') { flag_l=1;}
            else if(argv[i][j]=='a') { flag_a=1;}
         } 
     }  

     else { strcpy(gfile,argv[i]); }      
 }

  //printf("%d %d\n",flag_a,flag_l);
  struct dirent *dir_st;
  char filepath[10000];
  char buffer[1000];
  long long int i,sizeofdirectory;
  chdir(gfile);
  getcwd(buffer,sizeof(buffer)); 
  //printf("%s\n",buffer);
  for(i=0;buffer[i]!='\0';i++) {  }
  sizeofdirectory=i;
  DIR * dr=opendir(buffer);

  
  if(flag_a==1 && flag_l==1)
  {
    
     while((dir_st= readdir(dr))!=NULL) 
     { 
        //char * filepath =(char *)((sizeofdirectory+strlen(dir_st->d_name)+5)*sizeof(char)) ;
        struct stat st;
        struct passwd *username = getpwuid(st.st_uid);
        struct group  *groupname = getgrgid(st.st_gid);
        memset(filepath,0,1000);
        strcpy(filepath,buffer);
        strcat(filepath,"/");
        strcat(filepath,dir_st->d_name) ;
        //printf("%s \n",filepath); 
        stat(filepath,&st); 

        //checking permisssions using stat part-1
        printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
        printf( (st.st_mode & S_IRUSR) ? "r" : "-");
        printf( (st.st_mode & S_IWUSR) ? "w" : "-");
        printf( (st.st_mode & S_IXUSR) ? "x" : "-");
        printf( (st.st_mode & S_IRGRP) ? "r" : "-");
        printf( (st.st_mode & S_IWGRP) ? "w" : "-");
        printf( (st.st_mode & S_IXGRP) ? "x" : "-");
        printf( (st.st_mode & S_IROTH) ? "r" : "-");
        printf( (st.st_mode & S_IWOTH) ? "w" : "-");
        printf( (st.st_mode & S_IXOTH) ? "x" : "-");

        //no of hard links
        printf(" %3lu",st.st_nlink);
        printf(" %s",username->pw_name);
        printf(" %s",groupname->gr_name);
        printf(" %5lu ",st.st_size);
        
        char date[10];
        strftime(date, 10, "%b %2d ", gmtime(&(st.st_mtime))); 
        printf("%s",date);  
        printf(" %s ",dir_st->d_name); 
        printf("\n");
     }
     
  }
  if(flag_l==1 && flag_a==0)
  {
    
     while((dir_st= readdir(dr))!=NULL) 
     { 
        //char * filepath =(char *)((sizeofdirectory+strlen(dir_st->d_name)+5)*sizeof(char)) ;
       if(dir_st->d_name[0]!='.')
       { 
        struct stat st;
        struct passwd *username = getpwuid(st.st_uid);
        struct group  *groupname = getgrgid(st.st_gid);
        memset(filepath,0,1000);
        strcpy(filepath,buffer);
        strcat(filepath,"/");
        strcat(filepath,dir_st->d_name) ;
        //printf("%s \n",filepath); 
        stat(filepath,&st); 

        //checking permisssions using stat part-1
        printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
        printf( (st.st_mode & S_IRUSR) ? "r" : "-");
        printf( (st.st_mode & S_IWUSR) ? "w" : "-");
        printf( (st.st_mode & S_IXUSR) ? "x" : "-");
        printf( (st.st_mode & S_IRGRP) ? "r" : "-");
        printf( (st.st_mode & S_IWGRP) ? "w" : "-");
        printf( (st.st_mode & S_IXGRP) ? "x" : "-");
        printf( (st.st_mode & S_IROTH) ? "r" : "-");
        printf( (st.st_mode & S_IWOTH) ? "w" : "-");
        printf( (st.st_mode & S_IXOTH) ? "x" : "-");

        //no of hard links
        printf(" %3lu",st.st_nlink);
        printf(" %s",username->pw_name);
        printf(" %s",groupname->gr_name);
        printf(" %5lu ",st.st_size);
        
        char date[10];
        strftime(date, 10, "%b %2d ", gmtime(&(st.st_mtime))); 
        printf("%s",date);  
        printf(" %s ",dir_st->d_name); 
        printf("\n");
       } 
     }
     
  }
  else if(flag_a==1 && flag_l==0)
  {
     while((dir_st= readdir(dr))!=NULL) { printf("%s\n",dir_st->d_name); }
  }
  else 
  {
      while((dir_st= readdir(dr))!=NULL)
      {
        if(dir_st->d_name[0]!='.')
        { printf("%s\n",dir_st->d_name);}
      }
  }

  chdir(ref);
  //getcwd(buffer,sizeof(buffer));
  //printf("%s",buffer);
}