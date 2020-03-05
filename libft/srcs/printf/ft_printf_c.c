/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:23:52 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/07/10 11:56:53 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_c(t_list *data, unsigned char c)
{
	data->arg_len = 1;
	data->prec = 0;
	ft_pad_plus_width(data);
	data->count += data->arg_len + data->pad_plus_width;
	ft_putchar_iter(data->pad_plus_width, ' ');
	ft_putchar(c);
}

static void	ft_lc(t_list *data, int c)
{
	data->arg_len = ft_wcharlen(c);
	data->prec = 0;
	ft_pad_plus_width(data);
	ft_putchar_iter(data->pad_plus_width, ' ');
	ft_put_wchar(c);
	data->count += data->arg_len + data->pad_plus_width;
}

void		ft_print_c(t_list *data)
{
	if (data->fmt == 'c' && data->length_mod != 3)
		ft_c(data, (unsigned char)va_arg(data->arg, int));
	else
		ft_lc(data, va_arg(data->arg, int));
}
