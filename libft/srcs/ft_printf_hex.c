/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:23:52 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 08:18:37 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_hex(t_list *data, unsigned long long nb)
{
	if (!(nb == 0 && data->prec == 1))
		data->arg_len = ft_longlen(nb, 16);
	ft_pad_plus_width(data);
	data->count += data->arg_len + data->pad_plus_width;
	ft_putchar_iter(data->pad_plus_width, ' ');
	if (nb != 0 && data->hash == 1)
	{
		data->fmt == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		data->count += 2;
	}
	if (nb == 0 && data->prec != 1)
		ft_putchar('0');
	if (data->fmt == 'X')
		ft_print_long_lhex(nb, 16);
	else
		ft_print_long_hex(nb, 16);
}

void		ft_print_hex(t_list *data)
{
	if (data->length_mod == 1)
		ft_hex(data, (unsigned char)va_arg(data->arg, int));
	else if (data->length_mod == 2)
		ft_hex(data, (unsigned short)va_arg(data->arg, int));
	else if (data->length_mod == 3)
		ft_hex(data, va_arg(data->arg, unsigned long));
	else if (data->length_mod == 4)
		ft_hex(data, va_arg(data->arg, unsigned long long));
	else if (data->length_mod == 5)
		ft_hex(data, va_arg(data->arg, intmax_t));
	else if (data->length_mod == 6)
		ft_hex(data, va_arg(data->arg, size_t));
	else
		ft_hex(data, va_arg(data->arg, unsigned int));
}
