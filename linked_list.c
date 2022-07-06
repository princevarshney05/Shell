#include"headers.h"
#include"linked_list.h"
#include"string.h"
PNode *head = NULL;

void add_process(int pid,char *name){
    PNode *newnode = (PNode *)malloc(sizeof(PNode));
    newnode->name = name;
    newnode->pid = pid;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        
    }
    else
    {
        PNode *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        
    }
    

}

void remove_process(int pid){
    //printf("remove is called\n");
    if(head == NULL){
        return;
        
    }
    else{
        PNode *temp = head,*prev;
        if(head->pid == pid){
            
            head = head->next;
            free(temp);
        }
        else{
            while(temp != NULL){
                if(temp->pid == pid){
                    break;
                }
                prev = temp;
                temp = temp ->next;
            }
            if(temp != NULL){
                prev->next = temp->next;
                free(temp);
            }

        }
        
    }
    
}


void print(){
    if(head == NULL){
        
        return;
    }
    PNode *temp = head;
    char state,print_state[20];
    int counter = 1;
    FILE *fd;
    while(temp != NULL){
            state = give_status(temp->pid);
            if(state == 'S' || state == 'R'){
                sprintf(print_state,"%s","Running");
            }
            else if(state == 'T'){
                sprintf(print_state,"%s","Stopped");
            }

            
        
        printf("[%d] %s %s [%d]\n",counter++,print_state,temp->name,temp->pid);
            temp = temp->next;
    }
    printf("\n");
}

PNode *give_pid(int job_no){
    int i = 1;
    PNode *temp = head;
    while(temp != NULL){
        
        if(i == job_no){
            return temp;
        }
            
        i += 1;
        temp = temp->next;
    }
    return NULL;
}


char give_status(int pid){
    FILE *fd;
    char stat_path[1000],state;
    sprintf(stat_path,"/proc/%d/stat",pid);
    fd = fopen(stat_path,"r");
    if(fd != NULL){
        fscanf(fd,"%*d %*s %c",&state);
    }
    return state;
}