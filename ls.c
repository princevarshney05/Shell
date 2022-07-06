#include"headers.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<getopt.h>
#include "ls.h"
#include<string.h>
extern char root[];
void handle_ls(int argc,char **argv){
    optind = 0;
    int opt;
    int option_a = 0,option_l=0,index = 0;
    char *dir_name[1000];
    char cwd[1000];
    while ((opt = getopt(argc, argv, ":la")) != -1){
        switch(opt){
            case 'l' :  option_l = 1;
                        break;
            case 'a' :  option_a = 1;
                        break;
            case '?' :  printf("Unknown option\n");

        }
    }
    
    if (optind < argc) 
    {
        
        while (optind < argc)
            dir_name[index++]=argv[optind++];
        
    }
    else
    {
        index++;
        dir_name[0] = getcwd(cwd,1000);
    }
    
    
    
        
    DIR *dr;
    struct dirent *ptr;
    for(int i= 0;i<index;i++){
        printf("%s:\n",dir_name[i]);
        if (strcmp(dir_name[i],"~") == 0)
        {
            dir_name[i] = root;
        }
        
        dr = opendir(dir_name[i]);
        if(dr == NULL){
            perror("ls ");
        }
        else{
            while((ptr = readdir(dr)) != NULL){
                if(option_a == 0){
                    
                    if((ptr->d_name)[0] != '.')
                        print_details(dir_name[i],ptr->d_name,option_l);
                }
                else
                {
                    print_details(dir_name[i],ptr->d_name,option_l);
                }
                
                
            }
            closedir(dr);
        }
        printf("\n");
    }

}

void print_details(char *dir_path,char *contentname,int option_l){
    
    char contentpath[1000];
    sprintf(contentpath,"%s/%s",dir_path,contentname);
    struct stat buf;
    
    if(stat(contentpath,&buf) == 0){
        
        if(option_l){
            check_type(buf.st_mode);
            print_permissions(buf.st_mode);
            printf("%ld\t",buf.st_nlink);
            get_username(buf.st_uid);
            get_groupname(buf.st_gid);
            printf("%ld\t",buf.st_size);
            print_modification_time(buf.st_mtime);
        }
        printf("%s",contentname);
        printf("\n");
    }
    else
    {
        perror("ls ");
    }
    
    
    
}

void check_type(mode_t st_mode){
    char c;
    if(S_ISDIR(st_mode))
        c = 'd';
    if(S_ISREG(st_mode))
        c = '-';
    if(S_ISLNK(st_mode))
        c = 'l';
    printf("%c",c);
}

void print_permissions(mode_t st_mode){
    printf((st_mode & S_IRUSR)? "r":"-");
    printf((st_mode & S_IWUSR)? "w":"-");
    printf((st_mode & S_IXUSR)? "x":"-");
    
    
    printf((st_mode & S_IRGRP)? "r":"-");
    printf((st_mode & S_IWGRP)? "w":"-");
    printf((st_mode & S_IXGRP)? "x":"-");
    
    
    printf((st_mode & S_IROTH)? "r":"-");
    printf((st_mode & S_IWOTH)? "w":"-");
    printf((st_mode & S_IXOTH)? "x":"-");
    printf("\t");
}

void get_username(uid_t uid){
    struct passwd *ptr = getpwuid(uid);
    printf("%s\t",ptr->pw_name);
}

void get_groupname(gid_t gid){
    struct group *ptr = getgrgid(gid);
    printf("%s\t",ptr->gr_name);
}

void print_modification_time(time_t time){
    char str[100];
    strftime(str,100,"%b %d %H:%M",localtime(&time));
    printf("%s\t",str);
}

