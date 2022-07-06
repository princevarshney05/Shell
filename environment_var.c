#include"headers.h"

void handle_setenv(int argc,char **argv){
    if(argc <= 3 && argc > 1){
        char *name,*value = NULL;
        name = argv[1];
        if(argc == 3){
            value = argv[2];
        }
        setenv(name,value,1);
    }
    else{
        printf("Illegal number of arguments to setenv\n");
    }
}

void handle_unsetenv(int argc,char **argv){
    if(argc == 2){
        unsetenv(argv[1]);
    }
    else{
        printf("Illegal number of arguments to unsetenv\n");
    }
}