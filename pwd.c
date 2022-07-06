#include "headers.h"

void pwd(int argc,char **argv){
    if(argc == 1){
        char paths[1000];
        char *op = getcwd(paths,1000);
        if(op != NULL)
            printf("%s\n",paths);
        else
            perror("pwd");
    }
    else{
        printf("Illegal");
    }

}