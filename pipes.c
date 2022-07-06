#include "headers.h"
#include "string.h"
#include "handle.h"
#include <sys/types.h>
#include <sys/wait.h>
#include"pipes.h"
#include"parse.h"
#include"redir.h"




int is_inbuilt(char *cmd){
    char *inbuilts[] = {"echo","cd","pwd","ls","pinfo","jobs","quit","fg","bg","kjob","overkill","setenv","unsetenv"};
    for(int i = 0; i < 7; i++){
        if(strcmp(cmd,inbuilts[i]) == 0){
            return 1;
        }
    }
    return 0;
}



void piping_main(struct op pipe_structure){

    
    int my_pipes[2],pid;
    int input_fd = STDIN_FILENO;
    struct op cur;
    for(int i = 0;i<pipe_structure.n-1;i++){
        if(pipe(my_pipes) == -1){
            perror("pipe: ");
        }
        cur = parse_commands(pipe_structure.list[i]," ");
        cur.list[cur.n] = NULL;
        
        create_child(input_fd,my_pipes[1],cur.n,cur.list);
        
        close(my_pipes[1]);
        free(cur.list);
        input_fd = my_pipes[0];
        

    }
    
    
    cur = parse_commands(pipe_structure.list[pipe_structure.n-1]," ");
    cur.list[cur.n] = NULL;
    create_child(input_fd,STDOUT_FILENO,cur.n,cur.list);

}

void create_child(int input_fd,int output_fd,int argc,char **argv){
    int pid,*status;
    pid = fork();
    if(pid < 0){
        perror("");
    }
    else if(pid == 0){
        if(input_fd != STDIN_FILENO){
            dup2(input_fd,STDIN_FILENO);
            close(input_fd);
        }
        if(output_fd != STDOUT_FILENO){
            dup2(output_fd,STDOUT_FILENO);
            close(output_fd);
        }

        status = is_redir(argc,argv); //checking redirection
        
        if(status[0] > 0){ 
            argv[status[1]] = NULL;
            handle_redirection();
            if(perform_redirection() == 0){
                exit(0);
            }
            
                    
        }
        if(status[0] >= 0){
            if(is_inbuilt(argv[0])){

                handle_commands(status[1],argv);
                
            }
            else
            {
                
                if(execvp(argv[0],argv)==-1){
                    perror(argv[0]);
                }
            }
            
        }
        else{
            printf("Wrong syntax \n");
        }
        exit(0);
        
    }
    else{
        wait(NULL);
    }

}



