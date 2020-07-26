
char bg_name[100000][100];
char sspidname[100];
long long int bg[100];
long long int sizeofbg;
long long int sspid;
long long int shellid;
struct job{
        char jname[100];
        int  jpid;
        int  status; // for running 2 for stopped 3
    }processes[1000];


void execute_echo(int argc,char * agrv[]);
void execute_pwd(int argc,char *argv[]);
void execute_ls(int argc,char *argv[]);
void execute_cd(int argc,char *argv[]);
void execute_pinfo(int argc,char * argv[]);
void execute_exithandler(int sig);
void execute_fg(long long int a,char * input_arguments[]);
void execute_bg(long long int count,char * input_arguments[]);

void callfork(char ** input_arguments,int count);
void redirectioncheck(char ** input_arguments,int count);
void function_call(char **input_arguments, int count);

void execute_inputredirection(char ** input_arguments,int count,int position);
void execute_outputredirection(char ** input_arguments,int count,int position);
void execute_ioredirection(char ** input_arguments,int count,int position1,int position2);
void execute_appendredirection(char ** input_arguments,int count,int position);

void execute_pip(char * buffer);
char ** split_eachpipe(char * buffer);

void execute_jobs();
void execute_kjob(char ** input_arguments,int count);
void execute_overkill();
void execute_bbgrbg(char ** input_arguments,int count);
void execute_fgbg(char ** input_arguments,int count);

void execute_quit();
void execute_setenv(char ** input_arguments,int count);
void execute_unsetenv(char ** input_arguments,int count);

void sigintHandler (int sig_num);

void execute_cronjob(char ** input_arguments,int count);