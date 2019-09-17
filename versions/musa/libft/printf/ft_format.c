/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:49:02 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 07:54:06 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_format(t_list *data, char c)
{
	data->width--;
	if (data->width > 0)
		data->count += data->width;
	data->prec = 0;
	ft_pad_plus_width(data);
	ft_putchar_iter(data->pad_plus_width, ' ');
	if (c)
	{
		data->count += ft_putchar_ret_int(c);
	}
}
