# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 11:15:24 by mbaloyi           #+#    #+#              #
#    Updated: 2018/08/15 07:52:48 by mbaloyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFTOBJ = ../libft/ft_atoi.o ../libft/ft_bzero.o \
			../libft/ft_isalnum.o ../libft/ft_isalpha.o \
			../libft/ft_isascii.o ../libft/ft_isdigit.o \
			../libft/ft_isspace.o ../libft/ft_isprint.o \
			../libft/ft_itoa.o ../libft/ft_memalloc.o \
			../libft/ft_memccpy.o ../libft/ft_memchr.o \
			../libft/ft_memcmp.o ../libft/ft_memcpy.o \
			../libft/ft_memdel.o ../libft/ft_memmove.o \
			../libft/ft_memset.o ../libft/ft_putchar.o \
			../libft/ft_putchar_fd.o ../libft/ft_putendl.o \
			../libft/ft_putendl_fd.o ../libft/ft_putnbr.o \
			../libft/ft_putnbr_fd.o ../libft/ft_putstr.o \
			../libft/ft_putstr_fd.o ../libft/ft_strcat.o \
			../libft/ft_strchr.o ../libft/ft_strclr.o \
			../libft/ft_strcmp.o ../libft/ft_strcpy.o \
			../libft/ft_strdel.o ../libft/ft_strdup.o \
			../libft/ft_strequ.o ../libft/ft_striter.o \
			../libft/ft_striteri.o ../libft/ft_strjoin.o \
			../libft/ft_strlcat.o ../libft/ft_length.o \
			../libft/ft_strmap.o ../libft/ft_strmapi.o \
			../libft/ft_strncat.o ../libft/ft_strncmp.o \
			../libft/ft_strncpy.o ../libft/ft_strnequ.o \
			../libft/ft_strnew.o ../libft/ft_strnstr.o \
			../libft/ft_strrchr.o ../libft/ft_strsplit.o \
			../libft/ft_strstr.o ../libft/ft_strsub.o \
			../libft/ft_strtrim.o ../libft/ft_tolower.o \
			../libft/ft_toupper.o ../libft/ft_put_wchar.o \
			../libft/ft_putnbr_long.o ../libft/get_next_line.o

SRC =	ft_printf.c ft_is_.c \
		ft_format.c ft_init.c ft_parse_arg.c \
		ft_padding.c ft_parse_arg.c \
		ft_printf_c.c ft_printf_s.c ft_printf_d_i.c \
		ft_long.c ft_printf_p.c ft_printf_ld.c \
		ft_printf_hex.c ft_printf_ud.c ft_printf_oct.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;34mCreated -- $@ \033[0m"
	@make -C ../libft/ all
	@ar rc $(NAME) $(OBJ) $(LIBFTOBJ)
	@ranlib $(NAME)
	

%.o: %.c
	@echo "     \033[0;34mCompiling -- $@ \033[0m"
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@make -C ../libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C ../libft/ fclean
	@rm -rf $(NAME)

re: fclean all

norm :
	@make -C ../libft/ norm
	norminette $(SRC) 

.PHONY : all fclean re