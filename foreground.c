#include "headers.h"
#include <sys/types.h>
#include <sys/wait.h>
#include<signal.h>
#include<termios.h>
#include"linked_list.h"
#include"signal.h"

extern int fg_pgid;
extern struct termios shell_tmodes;

void put_job_in_foreground(int pid,char *name){
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN,SIG_IGN);
    tcsetpgrp(STDIN_FILENO,getpgid(pid));
                    
    kill(pid,SIGCONT);           
                
    fg_pgid = pid;
    int status;
    if(waitpid(pid,&status,WUNTRACED)==-1){
        perror("");
    }
    if(WIFSTOPPED(status)){
        add_process(pid,name);
    }

    tcsetpgrp(STDIN_FILENO,getpgrp());

    tcsetattr(STDIN_FILENO,0, &shell_tmodes)==-1;
                    
                

    signal(SIGTTOU, SIG_DFL);
    signal(SIGTTIN,SIG_DFL);
}