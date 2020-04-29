/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:38:25 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 10:12:53 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_itoa(int n)
{
	char	out[12];
	char	*new;
	long	x;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	else if (n < 0)
		x = n * -1;
	else
		(x = n);
	i = 0;
	while (x > 0)
	{
		out[i++] = (x % 10) + 48;
		x /= 10;
	}
	if (n < 0)
		out[i++] = '-';
	out[i] = '\0';
	if (!(new = ft_strnew(ft_strlen(out))))
		return (NULL);
	return (new = ft_strcpy(new, ft_strrev(out)));
}
