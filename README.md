# DEPEDENCY
Install libreadline-dev by running `sudo apt-get install libreadline-dev`

# How to run?
Type "make main" (without quotes) on the terminal,followed by ./a.out.If you wish to remove all the object files type "make remove" (without quotes)



# FILES DESCRIPTION
1. headers.h : This file contains all the common headers required across various files.

2. main.c : This contains the main shell loop.

3. prompt.c : This contains two functions i.e initialize_prompt() to initialize the prompt and prompt() which is called at every iteration of loop in  main.c

4. prompt.h : This contains function prototype for the file prompt.c

5. parse.c : This contains a function parse_commands() which breaks a string into tokens based on a character c.

6. parse.h : This contains function prototype for the file parse.c

7. handle.c : This containsa function handle_commands() which is called after parsing of the input is done.This 
inturn calls appropriate functions according to the command given.

8. handle.h : This contains function prototype for the file handle.c

9. echo.c : This contains function needed to implement echo command.

10. echo.h : This contains function prototype for the file echo.c

11. ls.c : This contains function needed to implement ls command.

12. ls.h : This contains function prototype for the file ls.c

13. pwd.c : This contains function needed to implement pwd command.

14. pwd.h : This contains function prototype for the file pwd.c

15. pinfo.c : This contains function needed to implement pinfo command.

16. pinfo.h : This contains function prototype for the file pinfo.c

17. system_programs.c : This contains function needed to implement all the other system commands.

18. sys.h : This contains function prototype for the file system_programs.c

19. cd.c : This contains function needed to implement cd command.

20. cd.h : This contains function prototype for the file cd.c

21. Makefile: This contains instruction for compilation.


22. bg.c : This contains function needed to implement bg command.

23. bg.h : This contains function prototype for file bg.c.

24. environment_var.c : This contains function needed to implement setenv and unsetenv commands.

25. envr.h : This contains function prototype for file environment_var.c.

26. foreground.c : This contains function to put a job in the foreground.

27. foreground.h : This contains function prototype for file foreground.c.

28. kills.c : This contains function needed to implement kjob and overkill commands.

29. kills.h : This contains function prototype for file kills.c.

30. linked_list.c : This contains functions required to add_process,remove_process,print details of the          background processes.

31. linked_list.h : This contains function prototype for file linked_list.c

32. pipes.c : This contains function needed to implement pipes.

33. pipes.h : This contains function prototype for file pipes.c.

34. redirection.c : This contains function needed to implement redirection.

35. redir.h : This contains function prototype for file redirection.c.

36. fg.c : This contains function needed to implement fg command.

37. fg.h : This contains function prototype for file fg.c