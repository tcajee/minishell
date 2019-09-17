/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:52:36 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:08 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_atoi(const char *str)
{
	long		res;
	long		sign;
	const char	*input;

	input = str;
	res = 0;
	sign = 1;
	while (ft_isspace(*input))
		input++;
	if (*input == '+')
		input++;
	else if (*input == '-')
	{
		sign = -1;
		input++;
	}
	while (*input && ft_isdigit(*input))
		res = res * 10 + (*input++ - '0');
	return ((int)res * (int)sign);
}
