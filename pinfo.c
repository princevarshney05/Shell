#include"headers.h"
#include <sys/types.h>
#include "pinfo.h"
void process_information(int argc,char **argv){
    int pid,msize;
    char exe_path[1000],stat_path[1000],statm_path[1000];
    char exec_name[100],state;
    
    for(int i=0;i<100;i++){
        exec_name[i] = '\0';
    }

    FILE *fd;
    if(argc == 1){
        pid = getpid();
    }
    else if(argc == 2){
        pid = atoi(argv[1]);
    }
    else{
        printf("illegal arguments to pinfo\n");
        return;
    }

    printf("pid -- %d\n",pid);

    sprintf(exe_path,"/proc/%d/exe",pid);
    sprintf(stat_path,"/proc/%d/stat",pid);
    sprintf(statm_path,"/proc/%d/statm",pid);
    
    
    fd = fopen(stat_path,"r");
    if(fd != NULL){
        fscanf(fd,"%*d %*s %c",&state);
        printf("Process status -- %c\n",state);
    }
    else{
        printf("Process status -- Given pid is wrong\n");
    }

    fd = fopen(statm_path,"r");
    if(fd != NULL){
        fscanf(fd,"%d",&msize);
        printf("Memory -- %d\n",msize);
    }
    else{
        printf("Memory -- Given pid is wrong\n");
    }
    
    if(readlink(exe_path,exec_name,100) != -1)
        printf("Executable path : %s\n",exec_name);
    else
        perror("Executable path -- ");
    

}