#include "prompt.h"
#include "parse.h"
#include "headers.h"
#include"handle.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "redir.h"
#include"pipes.h"
#include <fcntl.h>
#include<signal.h>
#include<termios.h>
#include<string.h>


extern int fg_pgid;
struct termios shell_tmodes;

int bool_status = 0;

void sigint_handler(int signo){
    
    
    if(fg_pgid != -999){
        
        if(kill(-fg_pgid,SIGINT) == -1){
            perror("ctrcl c:");
        }
        fg_pgid = -999;
    }
}

void sigtstp_handler(int signo){
    
    
    if(fg_pgid != -999){
        
        if(kill(-fg_pgid,SIGTSTP) == -1){
            perror("");
        }
        fg_pgid = -999;
        
    }
}


extern int term_pid,bool;

int main()
{
    
    tcgetattr(STDIN_FILENO,&shell_tmodes);
    signal(SIGINT,sigint_handler);
    signal(SIGTSTP,sigtstp_handler);
    struct op output,cur,piping;
    int *status;
    
    
    
    
    initialize_prompt();
    while (1)
    {
        
        fg_pgid = -999;
        
        
        char *input = readline(prompt());
        if(input == NULL){
            exit(0);
        }
        
        output = parse_commands(input,";"); // checking for mutiple commands
        
        for(int i=0;i<output.n;i++){

            piping = parse_commands(output.list[i],"|"); //checking for piping

            if(piping.n == 1){ //no piping
                

                cur = parse_commands(piping.list[0]," ");
                
                status = is_redir(cur.n,cur.list); //checking redirection
                
                if(status[0] > 0){ //yes
                    
                    handle_redirection();
                    
                    if(perform_redirection()){
                        handle_commands(status[1],cur.list);
                    
                        restore();
                    }
                    
                }
                else if(status[0] == 0){ //no
                    handle_commands(cur.n,cur.list);
                }
                else{
                    printf("Wrong syntax \n");
                }
                
                free(status);
                free(cur.list);
            }
            else{
                piping_main(piping);
                free(piping.list);
            }
            
        }
        free(output.list);
        if(bool){
            bool = 0;
            printf("%d is terminated\n",term_pid);
        }
        
        
        
    
    }
    
    
    
}
