# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skorac <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 11:13:00 by skorac            #+#    #+#              #
#    Updated: 2018/09/27 13:48:02 by skorac           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CCLIB = -L libft -lft
CCFLAGS = -Wall -Werror -Wextra
SRCDIR = src
OBJDIR = obj
INCDIR = includes libft/includes

SRC =		get_next_line.c \
			utils.c 		\
			mini_echo.c 	\
			mini_env.c 		\
			mini_setenv.c	\
			qtsplit.c 		\
			mini_unsetenv.c \
			main.c 			\
			mini_setenv.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
	@make -C libft
	@gcc $(CCLIB) -o $(NAME) $(OBJS)
build:
	@mkdir -p $(OBJDIR)
clean:
	@make -C libft clean
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
re: fclean all

dev : all
	@./$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc -c $(CCFLAGS) $(INCS) -o $@ $<
