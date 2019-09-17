/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:23:52 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 08:16:43 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_dec(t_list *data, int n)
{
	if (n < 0)
		data->neg = 1;
	if (!(n == 0 && data->prec == 1))
		data->arg_len = n == -2147483648 ? 10 : ft_intlen(ft_abs(n));
	ft_pad_flag(data);
	ft_pad_plus_width(data);
	data->count += data->arg_len + data->pad_plus_width;
	ft_putchar_iter(data->pad_plus_width, ' ');
	if (data->pad_flag && ++data->count)
		ft_putchar_iter(1, data->pad_flag);
	ft_putnbr_neg(n);
}

void		ft_print_dec(t_list *data)
{
	if (data->length_mod == 1)
		ft_dec(data, (char)va_arg(data->arg, int));
	else if (data->length_mod == 2)
		ft_dec(data, (short)va_arg(data->arg, int));
	else if (data->length_mod == 3)
		ft_print_uns_d(data, va_arg(data->arg, long));
	else if (data->length_mod == 4)
		ft_print_uns_d(data, va_arg(data->arg, long long));
	else if (data->length_mod == 5)
		ft_print_uns_d(data, va_arg(data->arg, intmax_t));
	else if (data->length_mod == 6)
		ft_print_uns_d(data, va_arg(data->arg, size_t));
	else
		ft_dec(data, va_arg(data->arg, int));
}
