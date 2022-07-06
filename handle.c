#include "headers.h"
#include<string.h>
#include"handle.h"
#include"echo.h"
#include"pwd.h"
#include"ls.h"
#include "pinfo.h"
#include"sys.h"
#include"cd.h"
#include"linked_list.h"
#include"fg.h"
#include"bg.h"
#include"kills.h"
#include"envr.h"

void handle_commands(int argc,char **argv){
    if(strcmp(argv[0],"echo") == 0){
        echo(argc,argv);
    }
    else if(strcmp(argv[0],"pwd") == 0){
        pwd(argc,argv);
    }
    else if(strcmp(argv[0],"cd") == 0){
        
        cd(argc,argv);
        
    }
    else if(strcmp(argv[0],"ls") == 0){
        handle_ls(argc,argv);
    }
    else if(strcmp(argv[0],"pinfo") == 0){
        
        process_information(argc,argv);
    }
    else if(strcmp(argv[0],"jobs") == 0){
        
        print();
    }
    else if(strcmp(argv[0],"fg") == 0){
        
        fg_command(argc,argv);
    }
    else if(strcmp(argv[0],"bg") == 0){
        
        handle_bg(argc,argv);
    }
    else if(strcmp(argv[0],"kjob") == 0){
        
        handle_kjob(argc,argv);
    }
    else if(strcmp(argv[0],"overkill") == 0){
        
        handle_overkill(argc,argv);
    }
    else if(strcmp(argv[0],"setenv") == 0){
        
        handle_setenv(argc,argv);
    }
    else if(strcmp(argv[0],"unsetenv") == 0){
        
        handle_unsetenv(argc,argv);
    }
    else if(strcmp(argv[0],"quit") == 0){
        
        exit(0);
    }

    else
    {
        others(argc,argv);
    }
    

    
}