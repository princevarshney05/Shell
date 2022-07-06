main:main.o parse.o echo.o handle.o prompt.o pwd.o ls.o pinfo.o system_programs.o cd.o kills.o environment_var.o redirection.o pipes.o linked_list.o foreground.o fg.o bg.o
	gcc main.o parse.o echo.o handle.o prompt.o pwd.o ls.o pinfo.o system_programs.o cd.o kills.o environment_var.o redirection.o pipes.o linked_list.o foreground.o fg.o bg.o -lreadline 
main.o:main.c
	gcc -c main.c
parse.o:parse.c
	gcc -c parse.c
echo.o:echo.c
	gcc -c echo.c
handle.o:handle.c
	gcc -c handle.c
prompt.o:prompt.c
	gcc -c prompt.c
pwd.o:pwd.c
	gcc -c pwd.c
ls.o:ls.c
	gcc -c ls.c
pinfo.o:pinfo.c
	gcc -c pinfo.c
system_programs.o:system_programs.c
	gcc -c system_programs.c
cd.o:cd.c
	gcc -c cd.c
redirection.o:redirection.c
	gcc -c redirection.c
pipes.o:pipes.c
	gcc -c pipes.c
linked_list.o:linked_list.c
	gcc -c linked_list.c
foreground.o:foreground.c
	gcc -c foreground.c
fg.o:fg.c
	gcc -c fg.c
bg.o:bg.c
	gcc -c bg.c
kills.o:kills.c
	gcc -c kills.c
environment_var.o:environment_var.c
	gcc -c environment_var.c
remove:
	rm -f *.o
