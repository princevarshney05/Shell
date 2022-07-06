#include "headers.h"
#include<string.h>
#include "parse.h"
struct op parse_commands(char *input,char *c){
    char **argv = (char **)malloc(1000*sizeof(char *));
    char *current;
    int i = 0;
    struct op output;
    while((current = strtok(input,c)) != NULL){
        argv[i] = current;
        i++;
        input = NULL;
    }
    output.list = argv;
    output.n = i;
    return output;

}