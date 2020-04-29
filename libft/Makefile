# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/18 14:40:51 by tcajee            #+#    #+#              #
#    Updated: 2019/07/15 15:46:17 by tcajee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project file
NAME		= libft.a

# Project builds and dirs
SRCDIR		= ./srcs/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC			= $(addprefix $(SRCDIR), $(SRCNAMES))
INCDIR		= ./incs/
BUILDDIR	= ./build/
BUILDOBJS	= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Optimization and Compiler flags and commands
CC			= clang
CFLAGS		= -Wall -Werror -Wextra

# Main rule
all: $(BUILDDIR) $(NAME)

# Objects dir rule
$(BUILDDIR):
	@echo "Compiling: $(NAME)"
	@mkdir -p $(BUILDDIR)

# Objects rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

# Project file rule
$(NAME): $(BUILDOBJS)
	@ar -rc $(NAME) $(BUILDOBJS)
	@ranlib $(NAME)
	@echo "Compiled: $(NAME)"

# Cleaning up the object files
clean:
	@rm -rf $(BUILDDIR)

# Getting rid of the project file
fclean: clean
	@rm -rf $(NAME)

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
