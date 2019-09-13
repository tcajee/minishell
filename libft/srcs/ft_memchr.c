/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:23:45 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:09 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_h;

	i = -1;
	src_h = (unsigned char *)s;
	while (++i < n)
	{
		if (src_h[i] == (unsigned char)c)
			return ((void *)&s[i]);
	}
	return (NULL);
}
