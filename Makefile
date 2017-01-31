# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 16:18:35 by vpopovyc          #+#    #+#              #
#    Updated: 2017/01/30 17:55:18 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = format.c ft_s_printf.c ft_group_onetwo.c ft_group_united.c ft_making_move.c \
	  ft_bit_party.c

OBJ = $(SRC:.c=.o)

LIBOBJ = libft/*.o

INC = -I ft_printf.h

CFLAGS = -c -Wall -Wextra -Werror

LIBCR = make -C libft/

LIBINC = -I libft/includes/libft.h -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBCR) all
	ar rc $(NAME) $(OBJ) $(LIBOBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(INC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

liball:
	$(LIBCR) all

libclean:
	$(LIBCR) clean

libre:
	$(LIBCR) re 
