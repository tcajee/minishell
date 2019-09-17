/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:49:02 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/08/15 07:54:41 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_long_hex(unsigned long long nb, int base)
{
	if (nb > 0)
	{
		ft_print_long_hex(nb / base, base);
		if (nb % base > 9)
			ft_putchar(X[nb % base]);
		else
			ft_putchar(X[nb % base]);
	}
}

void	ft_print_long_lhex(unsigned long long nb, int base)
{
	if (nb > 0)
	{
		ft_print_long_lhex(nb / base, base);
		if (nb % base > 9)
			ft_putchar(HX[nb % base]);
		else
			ft_putchar(HX[nb % base]);
	}
}

void	ft_print_long_oct(unsigned long long nb, int base)
{
	if (nb > 0)
	{
		ft_print_long_lhex(nb / base, base);
		if (nb % base > 9)
			ft_putchar(OCT[nb % base]);
		else
			ft_putchar(OCT[nb % base]);
	}
}

int		ft_longlen(unsigned long nb, int base)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		i++;
		nb /= base;
	}
	return (i);
}
