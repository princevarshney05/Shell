#include "headers.h"
#include <sys/types.h>
#include <sys/wait.h>
#include"sys.h"
#include<string.h>
#include<signal.h>
#include<termios.h>
#include"linked_list.h"
#include"foreground.h"

int term_pid;
int bool;
int fg_pgid = -999;


void fun(int signo){
    
    int status,pid;
    pid = waitpid(-1,NULL,WNOHANG);
    
    if(pid > 0){
        
            bool = 1;
            term_pid = pid;
            remove_process(pid);
        }
    
}


void others(int argc,char **argv){
   signal(SIGCHLD,fun);
   

    char *last = argv[argc-1];
    
    if(strcmp(last,"&") == 0){
        
        argv[argc-1] = NULL;
    }
    else{
        argv[argc] = NULL;
    }
    
    int pid = fork();
    
    if(pid < 0){
        perror("");
    }
    else{
        if(pid == 0){ // child process
            
            setpgid(0,0);

            if(strcmp(last,"&") != 0){
                if(tcsetpgrp(STDIN_FILENO,getpgrp()) == -1){
                    
                }
            }
            
            if(execvp(argv[0],argv)==-1){
                perror("");
            }
            
        }
        else{  //parent
            
            setpgid(pid,pid);

            if(strcmp(last,"&") != 0){ //foreground process
                put_job_in_foreground(pid,argv[0]);
            }
            else{ //background process
                if(waitpid(pid,NULL,WNOHANG)==-1){
                    perror("");
                }
                add_process(pid,argv[0]);
            }
            
            
            
            
        }
    }
}