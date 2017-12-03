# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazurok <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:30:49 by oshvorak          #+#    #+#              #
#    Updated: 2017/11/21 19:57:13 by amazurok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft.a

SRC = 	ft_arr_to_list.c ft_arrsplit.c ft_check_format.c ft_check_valid.c \
		ft_error.c ft_fill_help.c ft_frame.c ft_frame_help.c ft_frame_search.c \
		ft_list_push_back.c ft_listnew.c ft_lstlen.c ft_read.c ft_realloc.c \
		ft_size_map.c main.c ft_free_list.c ft_usage.c

OBJ = $(patsubst %.c, %.o, $(SRC))

MAKE =  cd libft

all: $(NAME)
	
$(NAME): $(OBJ)
	$(MAKE) && make
	$(MAKE) && mv $(LIB) ..
	gcc -Wall -Wextra -Werror $(OBJ) $(LIB) -o $(NAME)  

%.o : %.c
	gcc -c -Wall -Wextra -Werror $<
	
clean:
	rm -f $(OBJ)
	$(MAKE) && make clean

fclean: clean
	rm -f $(NAME) $(LIB)
	$(MAKE) && make fclean

re: fclean all


