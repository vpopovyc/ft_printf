
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