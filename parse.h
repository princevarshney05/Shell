#ifndef __PARSE_H
#define __PARSE_H
struct op{
    char **list;
    int n;
};
struct op parse_commands(char *input,char *c);

#endif