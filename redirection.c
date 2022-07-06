#include "headers.h"
#include"string.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include"redir.h"

char *input_file,*output_file,*append_file;
int status[3],given_fd[3],fd_file[3],fd_backup[3];

void initialize_structures(){
    input_file = NULL;
    output_file = NULL;
    append_file = NULL;
    status[0] = status[1] = status[2]= 0;
    given_fd[0] = given_fd[1] = given_fd[2] = -1;
    fd_file[0] = fd_file[1] = fd_file[2] = -1;
    fd_backup[0] = fd_backup[1] = fd_backup[2] = -1;
}

int *is_redir(int argc,char **argv){

    int *is_needed = (int *)malloc(2*sizeof(int));
    is_needed[0] = 0;
    is_needed[1] = argc;
    initialize_structures();
    for(int i=0;i<argc;i++){
        
        if(strcmp(argv[i],"<") == 0){
            is_needed[0] = 1;
            status[0] = 1;
            input_file = argv[i+1];
            if(input_file == NULL){
                is_needed[0] = -1;
            }
            is_needed[1] -= 2;
            //argv[i] = argv[i+1] = NULL;
            
        }
        if(strcmp(argv[i],">") == 0){
           
            is_needed[0] = 1;
            status[1] = 1;
            output_file = argv[i+1];
            if(output_file == NULL){
                is_needed[0] = -1;
            }
            is_needed[1] -= 2;
            //argv[i] = argv[i+1] = NULL;
        }
        if(strcmp(argv[i],">>") == 0){
            is_needed[0] = 1;
            status[2] = 1;
            append_file = argv[i+1];
            if(append_file == NULL){
                is_needed[0] = -1;
            }
            is_needed[1] -= 2;
            //argv[i] = argv[i+1] = NULL;
        }

    }
    
    return is_needed;
}

int  perform_redirection(){
    
    if(status[0]){
        fd_file[0] = open(input_file,O_RDONLY,0777);
        if(fd_file[0] == -1){
            perror(input_file);
            return 0;
        }
        fd_backup[0] = dup(given_fd[0]);
    }
    if(status[1]){
        fd_file[1] = open(output_file,O_CREAT | O_WRONLY | O_TRUNC, 0644);
        fd_backup[1] = dup(given_fd[1]);
    }
    if(status[2])
    {
        
        fd_file[2] = open(append_file,O_CREAT | O_WRONLY | O_APPEND, 0644);
        fd_backup[2] = dup(given_fd[2]);
    }
    for(int i=0;i<=2;i++){
        if(fd_file[i] != -1){
            dup2(fd_file[i],given_fd[i]);
        }
    }
    return 1;
}

void restore(){

    for(int i=0;i<=2;i++){
        if(fd_file[i] != -1 && fd_backup[i] != -1){
            dup2(fd_backup[i],given_fd[i]);
            close(fd_file[i]);
            close(fd_backup[i]);
        }
    }
    
}


void handle_redirection(){
    if(status[0]){
        given_fd[0] = STDIN_FILENO;
    }  
    if(status[1]){
        given_fd[1] = STDOUT_FILENO;
    }

    if(status[2]){
        given_fd[2] = STDOUT_FILENO;
    }

}