
#ifndef __RED_H
#define __RED_H

int *is_redir(int argc,char **argv);
int perform_redirection();
void restore();
void handle_redirection();
void initialize_structures();
#define BACK_UP 0
#define FILE_FD 1

#endif