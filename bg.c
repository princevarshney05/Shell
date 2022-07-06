#include"headers.h"
#include"linked_list.h"
#include"signal.h"

void handle_bg(int argc,char **argv){
    if(argc == 2){
        PNode *temp;
        if((temp = give_pid(atoi(argv[1])))!= NULL){
            
            char status = give_status(temp->pid);
            if(status == 'T'){
                kill(temp->pid,SIGCONT);
            }
        }
        else{
            printf("job doesn't exits \n");
        }
    }
    else{
        printf("Illegal number of argumemts to bg\n");
    }
}