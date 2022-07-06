#ifndef __LINK_H
#define __LINK_H
struct process_node{
    int pid;
    char *name;
    struct process_node *next;
    
};

typedef struct process_node PNode;

void add_process(int pid,char *name);
void remove_process(int pid);
void print();
PNode *give_pid(int job_no);
char give_status(int pid);
#endif