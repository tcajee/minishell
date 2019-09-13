/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwnext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:35:35 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 10:18:02 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

const char	*ft_strwnext(const char *s, int c)
{
	if (s)
	{
		while (*s && *s == c)
			s++;
	}
	return (s);
}
