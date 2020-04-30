# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/29 13:11:02 by tcajee            #+#    #+#              #
#    Updated: 2019/09/18 17:03:46 by tcajee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project file
NAME		= minishell

# Project builds and dirs
SRCDIR		= ./srcs/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC			= $(addprefix $(SRCDIR), $(SRCNAMES))
BUILDDIR	= ./build/
BUILDOBJS	= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Libft builds and dirs
LIBDIR		= ./libft/
LIBFT		= ./libft/libft.a
LIBINC		= ./libft/incs

# Optimization and Compiler flags and commands
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

# Main rule
all: $(BUILDDIR) $(LIBFT) $(NAME)

# Object dir rule
$(BUILDDIR):
	@echo "Compiling: $(NAME)"
	@mkdir -p $(BUILDDIR)

# Objects rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBINC) -o $@ -c $<

# Project file rule
$(NAME): $(BUILDOBJS)
	@$(CC) $(CFLAGS) $(BUILDOBJS) -L$(LIBDIR) -lft -o $(NAME)
	@echo "Compiled: $(NAME)"

# Libft rule
$(LIBFT):
	@make -C $(LIBDIR)

# Cleaning up the build files
clean:
	@rm -rf $(BUILDDIR)
	@make -C $(LIBDIR) clean

# Getting rid of the project file
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
