/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:49:02 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 07:53:49 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_initialise(t_list *data)
{
	data->plus = 0;
	data->minus = 0;
	data->zero = 0;
	data->hash = 0;
	data->fmt = 0;
	data->width = 0;
	data->prec = 0;
	data->length_mod = 0;
	data->pad_flag = 0;
	data->pad_plus_width = 0;
	data->space = 0;
	data->arg_len = 0;
	data->len = 0;
	data->neg = 0;
}
