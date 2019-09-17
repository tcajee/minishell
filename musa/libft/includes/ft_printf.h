/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:00:23 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 08:08:27 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

# define X      "0123456789abcdef"
# define HX     "0123456789ABCDEF"
# define OCT    "01234567"

typedef struct	s_list
{
	int		index;
	va_list	arg;
	char	fmt;
	int		count;
	int		plus;
	int		minus;
	int		zero;
	int		hash;
	int		width;
	int		prec;
	int		length_mod;
	int		pad_flag;
	int		pad_plus_width;
	int		space;
	int		arg_len;
	int		len;
	int		neg;
}				t_list;

int				ft_printf(const char *format, ...);
int				ft_is_format(char *str);
int				run_printf(char *str);
void			ft_initialise(t_list *data);
void			ft_print_format(t_list *data, char c);
int				ft_parse_arg(t_list *data, char *str);
void			ft_flags(t_list *data, char c);
int				ft_width(t_list *data, char *str, int i);
int				ft_prec(t_list *data, char *str, int i);
int				ft_length(t_list *data, char *str);
int				is_flag(char c);
int				is_width(char c);
int				is_length(char c);
int				is_specifier(char c);
int				ft_printf_char(char c);
void			ft_print_c(t_list *data);
void			ft_print_s(t_list *data);
void			ft_print_dec(t_list *data);
void			ft_print_p(t_list *data, void *nb);
void			ft_print_uns_d(t_list *data, long long nb);
void			ft_print_hex(t_list *data);
void			ft_print_u(t_list *data);
void			ft_print_o(t_list *data);
void			ft_pad_flag(t_list *data);
void			ft_pad_plus_width(t_list *data);
void			ft_print_long_hex(unsigned long long nb, int base);
void			ft_print_long_lhex(unsigned long long nb, int base);
void			ft_print_long_oct(unsigned long long nb, int base);
int				ft_longlen(unsigned long nb, int base);
#endif
