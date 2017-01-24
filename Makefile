# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 16:18:35 by vpopovyc          #+#    #+#              #
#    Updated: 2017/01/24 20:07:53 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = main.c format.c ft_s_printf.c ft_group1.c ft_making_move.c

OBJ = $(SRC:.c=.o)

INC = -I ft_printf.h

CFLAGS = -c  

LIBCR = @make -C libft/

LIBINC = -I libft/includes/libft.h -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBCR)
	@gcc $(LIBINC) $(OBJ) -o $(NAME)
	@echo "./ft_printf compiled"

%.o: %.c
	@gcc $(INC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

liball:
	$(LIBCR) all

libclean:
	$(LIBCR) clean

libfclean:
	$(LIBCR) fclean

libre:
	$(LIBCR) re 
