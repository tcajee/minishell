/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:49:02 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 07:54:24 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (c);
	return (0);
}

int		is_width(char c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int		is_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (c);
	return (0);
}

int		is_specifier(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D')
		return (c);
	if (c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
		return (c);
	if (c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (c);
	return (0);
}
