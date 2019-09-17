/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:23:52 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 08:22:23 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_s(t_list *data, char *str)
{
	if (str == NULL)
		str = "(null)";
	if (ft_strlen(str) > (size_t)(data->prec - 1))
		data->arg_len = data->prec - 1;
	else
		data->arg_len = ft_strlen(str);
	data->prec = 0;
	ft_pad_plus_width(data);
	data->count += data->arg_len + data->pad_plus_width;
	ft_putchar_iter(data->pad_plus_width, ' ');
	while (*str && data->arg_len-- > 0)
		ft_putchar(*str++);
}

static int	get_size(t_list *data, int *str)
{
	int	size;
	int	size_int;

	size = 0;
	while (*str)
	{
		size_int = ft_intlen(*str++);
		if (size + size_int <= data->prec - 1)
			size += size_int;
	}
	return (size);
}

static void	ft_ls(t_list *data, int *str)
{
	if (str == NULL)
		str = L"(null)";
	if (data->prec > 0)
		data->arg_len = get_size(data, str);
	else
		data->arg_len = ft_wstrlen((unsigned*)str);
	data->prec = 0;
	ft_pad_plus_width(data);
	data->count += data->arg_len + data->pad_plus_width;
	ft_putchar_iter(data->pad_plus_width, ' ');
	while (data->arg_len > 0)
	{
		data->arg_len -= ft_wcharlen(*str);
		ft_put_wchar(*str++);
	}
}

void		ft_print_s(t_list *data)
{
	if (data->fmt == 's' && data->length_mod != 3)
		ft_s(data, va_arg(data->arg, char *));
	else
		ft_ls(data, va_arg(data->arg, wint_t *));
}
