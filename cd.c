#include"headers.h"
#include "cd.h"
#include"string.h"
#include"prompt.h"
extern char root[];
extern char previous[];
char current[1000];

void cd(int argc,char **argv){
    if(argc == 2){
            if(strcmp(argv[1],"-") ==0){
                getcwd(current,1000);
                printf("%s\n",calculatepath_relativeto_root(previous));
                chdir(previous);
                strcpy(previous,current);
            }
            else{
                getcwd(previous,1000);
                if(strcmp(argv[1],"~") ==0){
                    
                    chdir(root);
                }
                
                else if(chdir(argv[1]) != 0){
                    perror("cd ");
                }
                
            }
            

           
        }

}