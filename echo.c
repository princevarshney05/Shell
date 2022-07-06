#include "headers.h"
#include "echo.h"
#include<string.h>



void echo(int argc,char **argv){
    
    char ans[1000];
    ans[0] = '\0';
    int i = 1;
    while(i <= argc-1){
        
        strcat(ans,argv[i]);
        strcat(ans," ");
        i += 1;
    }
    printf("%s\n",ans);
    
    
    
}