#ifndef __LS_H
#define __LS_H

void handle_ls(int argc,char **argv);
void print_details(char *dir_path,char *filename,int option_l);
void check_type(mode_t st_mode);
void print_permissions(mode_t st_mode);
void get_username(uid_t uid);
void get_groupname(gid_t gid);
void print_modification_time(time_t time);
#endif