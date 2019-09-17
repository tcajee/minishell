/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:23:52 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 08:23:23 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_uns(t_list *data, unsigned long long nb)
{
	if (!(nb == 0 && data->prec == 1))
		data->arg_len = ft_longlen(nb, 10);
	ft_pad_plus_width(data);
	data->count += data->arg_len + data->pad_plus_width;
	ft_putchar_iter(data->pad_plus_width, ' ');
	ft_putnbr_long_long(nb);
}

void		ft_print_u(t_list *data)
{
	if (data->fmt == 'U')
		ft_uns(data, va_arg(data->arg, unsigned long long));
	else if (data->length_mod == 1)
		ft_uns(data, (unsigned char)va_arg(data->arg, int));
	else if (data->length_mod == 2)
		ft_uns(data, (unsigned short)va_arg(data->arg, int));
	else if (data->length_mod == 3)
		ft_uns(data, va_arg(data->arg, unsigned long));
	else if (data->length_mod == 4)
		ft_uns(data, va_arg(data->arg, unsigned long long));
	else if (data->length_mod == 5)
		ft_uns(data, va_arg(data->arg, uintmax_t));
	else if (data->length_mod == 6)
		ft_uns(data, va_arg(data->arg, size_t));
	else
		ft_uns(data, va_arg(data->arg, unsigned int));
}
