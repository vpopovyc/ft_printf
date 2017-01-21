# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 16:18:35 by vpopovyc          #+#    #+#              #
#    Updated: 2017/01/16 17:03:46 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = main.c format.c ft_tell_me_flag_baby.c ft_s_printf.c

OBJ = $(SRC:.c=.o)

INC = -I ft_printf.h

CFLAGS = -c  

LIBCR = make -C libft/

LIBINC = -I libft/includes/libft.h -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBCR) all &>/dev/null
	gcc $(LIBINC) $(OBJ) -o $(NAME)

%.o: %.c
	gcc $(INC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

libclean:
	$(LIBCR) clean &>/dev/null

libfclean:
	$(LIBCR) fclean &>/dev/null

libre:
	$(LIBCR) re &>/dev/null  
