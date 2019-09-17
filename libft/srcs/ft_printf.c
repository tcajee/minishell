/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:04:50 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 07:59:17 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_specifiers(t_list *data)
{
	if (data->fmt == 'c' || data->fmt == 'C')
		ft_print_c(data);
	else if (data->fmt == 's' || data->fmt == 'S')
		ft_print_s(data);
	else if (data->fmt == 'd' || data->fmt == 'i')
		ft_print_dec(data);
	else if (data->fmt == 'p')
		ft_print_p(data, va_arg(data->arg, void *));
	else if (data->fmt == 'D')
		ft_print_uns_d(data, va_arg(data->arg, long));
	else if (data->fmt == 'x' || data->fmt == 'X')
		ft_print_hex(data);
	else if (data->fmt == 'u' || data->fmt == 'U')
		ft_print_u(data);
	else if (data->fmt == 'o' || data->fmt == 'O')
		ft_print_o(data);
}

static int	ft_process_data(t_list *data, char *str)
{
	int		i;

	i = ft_parse_arg(data, str);
	if (data->fmt == 0 || data->fmt == '%')
		ft_print_format(data, str[i]);
	else
		ft_specifiers(data);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	t_list	data;
	char	*str;

	str = (char *)format;
	va_start(data.arg, format);
	data.count = 0;
	data.index = 0;
	while (str[data.index])
	{
		if (str[data.index] == '%')
		{
			ft_initialise(&data);
			data.index++;
			if (!str[data.index])
				break ;
			data.index += ft_process_data(&data, &str[data.index]);
		}
		else
			data.count += ft_putchar_ret_int(str[data.index]);
		data.index++;
	}
	va_end(data.arg);
	return (data.count);
}
