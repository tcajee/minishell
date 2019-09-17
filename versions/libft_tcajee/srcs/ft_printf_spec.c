/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:55:55 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/03 17:20:47 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	ft_spec(char *spec, va_list list, int width)
{
	if (*spec == 's')
		ft_s(width, list);
	if (*spec == 'd')
		ft_d(width, list);
	if (*spec == 'x')
		ft_x(width, list);
	else if (*spec == 'l')
		ft_l(width, list);
}
