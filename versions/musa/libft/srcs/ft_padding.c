/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:23:52 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 07:54:59 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_pad_flag(t_list *data)
{
	if (data->neg)
		data->pad_flag = '-';
	else if (data->plus)
		data->pad_flag = '+';
	else if (data->space)
		data->pad_flag = ' ';
}

void	ft_pad_plus_width(t_list *data)
{
	int	size;

	size = 0;
	if (data->minus == 0 && data->width > 0 &&
		(data->zero == 0 || data->prec > 0))
	{
		size = data->width - data->arg_len;
		if (data->pad_flag)
			size--;
		if ((data->hash == 1 && (data->fmt == 'x' || data->fmt == 'X'))
			|| data->fmt == 'p')
			size -= 2;
		if (data->hash == 1 && (data->fmt == 'o' || data->fmt == 'O'))
			size--;
		data->pad_plus_width = size < 0 ? 0 : size;
	}
}
