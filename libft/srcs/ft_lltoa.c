/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:23:09 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/29 14:30:42 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_lltoa(long long int n)
{
	char	*nstr;

	if (!(nstr = (char *)ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(nstr, "-2147483648"));
	if (n < 0)
	{
		nstr[0] = '-';
		nstr[1] = '\0';
		nstr = ft_strjoin(nstr, ft_itoa(-n));
	}
	else if (n >= 10)
		nstr = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n >= 0 && n <= 9)
	{
		nstr[0] = n + '0';
		nstr[1] = '\0';
	}
	return (nstr);
}
