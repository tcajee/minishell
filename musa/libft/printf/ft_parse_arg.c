/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:49:02 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 07:55:21 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_parse_arg(t_list *data, char *str)
{
	int	i;
	int	r;

	i = 0;
	while (str[i] && (data->fmt = is_specifier(str[i])) == 0)
	{
		r = 0;
		if (is_flag(str[i]))
			ft_flags(data, str[i]);
		else if (str[i] == '0' && (i == 0 || (str[i - 1] != '.'
			&& (str[i - 1] <= '0' || str[i - 1] > '9'))))
			data->zero = 1;
		else if ((i > 0 && str[i - 1] == '.') || str[i] == '.')
			i = ft_prec(data, str, i);
		else if (ft_isdigit(str[i]) && (i == 0 || (str[i - 1] != '.')))
			i = ft_width(data, str, i);
		else if ((r = ft_length(data, (str + i))) == 2)
			return (i);
		i += 1 + r;
	}
	return (i);
}

void	ft_flags(t_list *data, char c)
{
	if (c == '-')
		data->minus = 1;
	else if (c == '+')
		data->plus = 1;
	else if (c == ' ')
		data->space = 1;
	else if (c == '#')
		data->hash = 1;
}

int		ft_prec(t_list *data, char *str, int i)
{
	if (ft_isdigit(*str))
	{
		data->prec = 1;
		if (ft_isdigit(str[i + 1]))
			data->prec += ft_atoi(str + i + 1);
		while (str[i + 1] && ft_isdigit(str[i + 1]))
			i++;
	}
	return (i);
}

int		ft_width(t_list *data, char *str, int i)
{
	if (ft_isdigit(*str))
	{
		data->width = ft_atoi(str + i);
		while (str[i + 1] && ft_isdigit(str[i + 1]))
			i++;
	}
	return (i);
}

int		ft_length(t_list *data, char *str)
{
	if (str[0] == 'h' && str[1] && str[1] == 'h')
	{
		data->length_mod = data->length_mod > 1 ? data->length_mod : 1;
		return (1);
	}
	else if (str[0] == 'h')
		data->length_mod = data->length_mod > 2 ? data->length_mod : 2;
	else if (str[0] == 'l' && str[1] && str[1] == 'l')
	{
		data->length_mod = data->length_mod > 4 ? data->length_mod : 4;
		return (1);
	}
	else if (str[0] == 'l')
		data->length_mod = data->length_mod > 3 ? data->length_mod : 3;
	else if (str[0] == 'j')
		data->length_mod = data->length_mod > 5 ? data->length_mod : 5;
	else if (str[0] == 'z')
		data->length_mod = data->length_mod > 6 ? data->length_mod : 6;
	else
		return (2);
	return (0);
}
