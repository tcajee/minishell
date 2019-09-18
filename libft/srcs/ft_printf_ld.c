/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:23:52 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 08:19:14 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_uns_d(t_list *data, long long nb)
{
	if (nb < 0)
		data->neg = 1;
	if (!(nb == 0 && data->prec == 1))
		data->arg_len = ft_longlen(ft_abs_l(nb), 10);
	ft_pad_flag(data);
	ft_pad_plus_width(data);
	data->count += data->arg_len + data->pad_plus_width;
	ft_putchar_iter(data->pad_plus_width, ' ');
	if (data->pad_flag && ++data->count)
		ft_putchar_iter(1, data->pad_flag);
	ft_putnbr_long_neg(ft_abs_l(nb));
}
