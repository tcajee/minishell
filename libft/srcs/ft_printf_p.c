/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:23:52 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 08:21:01 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_p(t_list *data, void *nb)
{
	long	num;

	num = (long)nb;
	if (!(num == 0 && data->prec == 1))
		data->arg_len = ft_longlen(num, 16);
	ft_pad_plus_width(data);
	data->count += data->arg_len + data->pad_plus_width;
	ft_putchar_iter(data->pad_plus_width, ' ');
	ft_putstr("0x");
	data->count += 2;
	if (num == 0 && data->prec != 1)
		ft_putchar('0');
	else if (nb != 0)
		ft_print_long_hex(num, 16);
}
