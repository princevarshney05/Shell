#include "prompt.h"
#include "headers.h"
#include<pwd.h>
#include <unistd.h>
#include<string.h>

char system_name[100];
char *username;
char root[1000];
char previous[1000];
char prompt_message[1000];
void initialize_prompt(){
    gethostname(system_name,100);
    username = getlogin();
    getcwd(root,1000);
    strcpy(previous,root);

}



char * prompt() {
    
    
    char *cwd;
    char cur_path[1000];
    getcwd(cur_path,1000);
    if(strcmp(root,cur_path) == 0)
        cwd = "~";
    else
        cwd = calculatepath_relativeto_root(cur_path);
    
    sprintf(prompt_message,"<%s@%s:%s>",username,system_name,cwd);
    
    return prompt_message;   
}


char *calculatepath_relativeto_root(char *cur_path){
    if(strlen(cur_path) < strlen(root)){
        return cur_path;
    }
    else{
        char *modified = (char *)malloc(1000*sizeof(char));
        modified[0] = '~';
        int index = 1;
        for(int i=strlen(root);i<strlen(cur_path);i++){
            modified[index] = cur_path[i];
            index++;
        }
        modified[index] = '\0';
        return modified;
    }
    


}