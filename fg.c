#include"headers.h"
#include"linked_list.h"
#include"foreground.h"
#include"fg.h"


void fg_command(int argc,char **argv){
    if(argc == 2){
        PNode *temp;
        if((temp = give_pid(atoi(argv[1])))!= NULL){
            
            put_job_in_foreground(temp->pid,temp->name);
            remove_process(temp->pid);
        }
        else{
            printf("job doesn't exits \n");
        }
    }
    else{
        printf("Illegal number of arguments to fg\n");
    }
    
    
}