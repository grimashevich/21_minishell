# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 21:12:21 by ccamie            #+#    #+#              #
#    Updated: 2022/04/12 21:12:22 by ccamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

HEADER		=	minishell.h

LIBFT		=	libft/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined
# CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SOURCE		=	envp/envp_append.c				\
				envp/envp_count.c				\
				envp/envp_get_index.c			\
				envp/envp_get_value.c			\
				envp/envp_init.c				\
				envp/envp_insert.c				\
				envp/envp_print.c				\
				envp/envp_remove_all.c			\
				envp/envp_remove_by_index.c		\
				envp/envp_remove_first.c		\
				envp/envp_remove_last.c			\
				envp/envp_remove.c				\
				envp/envp_replace_by_index.c	\
				envp/envp_replace.c				\
				envp/envp_status.c				\
				pwd/pwd_update.c				\
				parserlvl1/parserlvl1.c			\
				parserlvl1/print_tree.c			\
				main.c							\

OBJECT		=	$(SOURCE:.c=.o)

.PHONY		:	all clean fclean re libft

all			:	libft $(NAME)

$(NAME)		:	$(OBJECT) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJECT) $(LIBFT) -o $(NAME)

%.o			:	%.c Makefile
				$(CC) $(CFLAGS) -c $< -o $@

libft		:
				make -C libft

clean		:
				make -C libft clean
				$(RM) $(OBJECT)

fclean		:
				make -C libft fclean
				$(RM) $(OBJECT)
				$(RM) $(NAME)

re			:	fclean all
