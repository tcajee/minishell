# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 11:16:40 by mbaloyi           #+#    #+#              #
#    Updated: 2018/09/13 11:16:46 by mbaloyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell_lib.a

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

LIB_A	=	./libft/printf/libftprintf.a

SRCS	=	ft_env.c ft_utils.c ft_echo.c\
			ft_exit.c ft_cd.c ft_setenv.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME) : $(OBJS)
	@echo "\033[1;33mCreated -- $@\033[0m"
	@make -C ./libft all
	@ar rc $(NAME) $(OBJS) 
	@ranlib $(NAME)
	@$(CC) minishell.c -o minishell $(FLAGS) $(LIB_A) $(NAME)

%.o: %.c
	@echo "     \033[0;33mCompiling -- $@ \033[0m"
	@$(CC) $(FLAGS) -c $< -o $@
	
clean:
	@make -C ./libft clean
	@rm -rf $(OBJS)
	
fclean : clean
	@make -C ./libft fclean
	@rm -rf ft_ls
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf minishell

re : fclean all

norm :
	@make -C ./libft norm
	@echo "\033[0;32mWill auto clear in 10 secs\033[0m"
	@sleep 10
	clear