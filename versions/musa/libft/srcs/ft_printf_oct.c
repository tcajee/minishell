/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:23:52 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 08:20:09 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_oct(t_list *data, unsigned long long nb)
{
	if (!(nb == 0 && data->prec == 1))
		data->arg_len = ft_longlen(nb, 8);
	ft_pad_plus_width(data);
	data->count += data->arg_len + data->pad_plus_width;
	ft_putchar_iter(data->pad_plus_width, ' ');
	if (data->hash == 1 && ((nb != 0 && data->arg_len >= data->prec - 1)
		|| (nb == 0 && data->prec == 1)))
	{
		ft_putstr("0");
		data->count += 1;
	}
	if (nb == 0 && data->prec != 1)
		ft_putchar('0');
	else if (nb != 0)
		ft_print_long_oct(nb, 8);
}

void		ft_print_o(t_list *data)
{
	if (data->fmt == 'O')
		ft_oct(data, va_arg(data->arg, unsigned long long));
	else if (data->length_mod == 1)
		ft_oct(data, (unsigned char)va_arg(data->arg, int));
	else if (data->length_mod == 2)
		ft_oct(data, (unsigned short)va_arg(data->arg, int));
	else if (data->length_mod == 3)
		ft_oct(data, va_arg(data->arg, unsigned long));
	else if (data->length_mod == 4)
		ft_oct(data, va_arg(data->arg, unsigned long long));
	else if (data->length_mod == 5)
		ft_oct(data, va_arg(data->arg, uintmax_t));
	else if (data->length_mod == 6)
		ft_oct(data, va_arg(data->arg, size_t));
	else
		ft_oct(data, va_arg(data->arg, unsigned int));
}
