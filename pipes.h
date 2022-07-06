
#ifndef __PIPES_H
#define __PIPES_H
#include"parse.h"


int is_inbuilt(char *cmd);
void piping_main(struct op pipe_structure);
void create_child(int input_fd,int output_fd,int argc,char **argv);


#endif