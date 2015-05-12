# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpreda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/28 17:31:45 by rpreda            #+#    #+#              #
#    Updated: 2014/11/28 17:44:04 by rpreda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC = ft_do_stuff.c ft_get_infos.c ft_help_do_stuff.c ft_help_do_stuff_two.c ft_help_grab.c ft_ls.c ft_sort_collection.c
OBJ = ft_do_stuff.o ft_get_infos.o ft_help_do_stuff.o ft_help_do_stuff_two.o ft_help_grab.o ft_ls.o ft_sort_collection.o
all:
		make -C libft/ fclean
		make -C libft/
		make -C libft/ clean
		gcc -Wall -Wextra -Werror -I libft/includes -c $(SRC)
		gcc -o $(NAME) $(OBJ) -L libft/ -lft
clean:
		/bin/rm -f $(OBJ)
fclean: clean
		/bin/rm -f $(NAME)
re: fclean all
