
Main task is to reproduce the behavior of libc func – printf.

Prototyped like that:
"%[modifier][fieldwidth][.precision][lengthmodifier][formatspecifier]"

Choose output options in main.c
Compile binary named ft_printf && execute it in terminal

Makefile usage:

make all	- to compile binary named ft_printf

make clean	- remove *.o files

make fclean	- same as clean + erasing *.a file

make re		- rule fclean && all

make liball	- compile libft

make libclean	- remove *.o files in libft folder

make libre	- rule libfclean && liball

https://server.179.ru/tasks/python/2014b1/22-bits.html

http://www.linuxforums.org/forum/linux-programming-scripting/88-color-console.html

https://en.wikipedia.org/wiki/ANSI_escape_code#Colors

http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c

