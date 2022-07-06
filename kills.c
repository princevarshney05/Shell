#include"headers.h"
#include"linked_list.h"
#include<signal.h>
#include"kills.h"

void handle_kjob(int argc,char **argv){
    if(argc == 3){
        PNode *temp;
        if((temp = give_pid(atoi(argv[1])))!= NULL){
            if(kill(temp->pid,atoi(argv[2])) == -1){
                perror("kjon ");
            }
        }
        else{
            printf("job doesn't exits \n");
        }
    }
    else{
        printf("Illegal arguments to kjob\n");
    }
}

void handle_overkill(int argc,char **argv){
    if(argc == 1){
        PNode *temp;
        while((temp = give_pid(1)) != NULL){
            kill(temp->pid,SIGKILL);
            remove_process(temp->pid);
        }

    }
    else{
        printf("Illegal arguments to kjob\n");
    }
}